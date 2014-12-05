//
//  GCHelper.m
//  TheSame
//
//  Created by dai dan on 14-7-27.
//
//

#import "GameCenterHelper.h"

@implementation GameCenterHelper

@synthesize gameCenterAvailable;

#pragma mark Initialization

static GameCenterHelper *sharedHelper = nil;
+ (GameCenterHelper *) sharedInstance {
    if (!sharedHelper) {
        sharedHelper = [[GameCenterHelper alloc] init];
    }
    return sharedHelper;
}

//初始化
- (id)init {
    if ((self = [super init])) {
        gameCenterAvailable = [self isGameCenterAvailable];
        if (gameCenterAvailable) {
            [self registerForAuthenticationNotification];
        }
    }
    return self;
}

//注册用户变更检测
- (void) registerForAuthenticationNotification
{
    NSNotificationCenter *nc = [NSNotificationCenter defaultCenter];
    [nc addObserver:self
           selector:@selector(authenticationChanged)
               name:GKPlayerAuthenticationDidChangeNotificationName
             object:nil];
}

//对GameCenter的支持判断
- (BOOL)isGameCenterAvailable {
    // check for presence of GKLocalPlayer API
    Class gcClass = (NSClassFromString(@"GKLocalPlayer"));
    
    // check if the device is running iOS 4.1 or later
    NSString *reqSysVer =@"4.1";
    NSString *currSysVer = [[UIDevice currentDevice] systemVersion];
    BOOL osVersionSupported = ([currSysVer compare:reqSysVer
                                           options:NSNumericSearch] != NSOrderedAscending);
    
    return (gcClass && osVersionSupported);
}

//用户变更通知
- (void)authenticationChanged {
    
    if ([GKLocalPlayer localPlayer].isAuthenticated &&!userAuthenticated) {
        NSLog(@"Authentication changed: player authenticated.");
        userAuthenticated = TRUE;
    } else if (![GKLocalPlayer localPlayer].isAuthenticated && userAuthenticated) {
        NSLog(@"Authentication changed: player not authenticated");
        userAuthenticated = FALSE;
    }
}

#pragma mark User functions
//用户登录
- (void)authenticateLocalUser {
    
    if (!gameCenterAvailable) return;
    
    NSLog(@"Authenticating local user...");
    if ([GKLocalPlayer localPlayer].authenticated == NO) {
        [[GKLocalPlayer localPlayer] authenticateWithCompletionHandler:nil];
    } else {
        NSLog(@"Already authenticated!");
    }
}

//上传分数
- (void) reportScore:(int64_t) score
{
    GKScore *scoreReporter = [[[GKScore alloc] initWithCategory:@"MSList"] autorelease];
    scoreReporter.value = score;
    
    [scoreReporter reportScoreWithCompletionHandler:^(NSError *error) {
        if (error != nil)
        {
            // handle the reporting error
            NSLog(@"上传分数出错.");
            //If your application receives a network error, you should not discard the score.
            //Instead, store the score object and attempt to report the player’s process at
            //a later time.
        }else {
            NSLog(@"上传分数成功");
        }
        
    }];
}
//下载分数
- (void) retrieveTopTenScores
{
    GKLeaderboard *leaderboardRequest = [[GKLeaderboard alloc] init];
    if (leaderboardRequest != nil)
    {
        leaderboardRequest.playerScope = GKLeaderboardPlayerScopeGlobal;
        leaderboardRequest.timeScope = GKLeaderboardTimeScopeAllTime;
        leaderboardRequest.range = NSMakeRange(1,10);
        leaderboardRequest.category = @"MSList";
        [leaderboardRequest loadScoresWithCompletionHandler: ^(NSArray *scores, NSError *error) {
            if (error != nil){
                // handle the error.
                NSLog(@"下载失败");
            }
            if (scores != nil){
                // process the score information.
                NSLog(@"下载成功....");
                NSArray *tempScore = [NSArray arrayWithArray:leaderboardRequest.scores];
                for (GKScore *obj in tempScore) {
                    NSLog(@"    playerID            : %@",obj.playerID);
                    NSLog(@"    category            : %@",obj.category);
                    NSLog(@"    date                : %@",obj.date);
                    NSLog(@"    formattedValue    : %@",obj.formattedValue);
                    NSLog(@"    value                : %d",obj.value);
                    NSLog(@"    rank                : %d",obj.rank);
                    NSLog(@"**************************************");
                }
            }
        }];
    }
}

//显示排行榜
- (void) showLeaderboard
{
    tempVC=[[UIViewController alloc] init];
    GKLeaderboardViewController *leaderboardController = [[GKLeaderboardViewController alloc] init];
    if (leaderboardController != nil)
    {
        UIApplication* clientApp = [UIApplication sharedApplication];
        UIWindow* topWindow = [clientApp keyWindow];
        if (!topWindow)
        {
            topWindow = [[clientApp windows] objectAtIndex:0];
        }
        [topWindow addSubview:tempVC.view];
        leaderboardController.leaderboardDelegate = self;
        [tempVC presentModalViewController: leaderboardController animated: YES];
    }
}
-(void) leaderboardViewControllerDidFinish:(GKLeaderboardViewController *)viewController
{
    //if ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPhone)
    //{
        [tempVC dismissModalViewControllerAnimated:NO];//在iphone上需要设置为NO，才可以继续响应事件（笔者还没有找到其他解决办法）
    //}
    //else
    //{
    //    [tempVC dismissModalViewControllerAnimated:YES];//
    //}
    
    [tempVC.view removeFromSuperview]; //为了使排行榜关闭的时候，能够继续响应事件
}
@end
