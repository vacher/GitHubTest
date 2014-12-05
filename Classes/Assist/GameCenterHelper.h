//
//  GCHelper.h
//  TheSame
//
//  Created by dai dan on 14-7-27.
//
//

#import<Foundation/Foundation.h>
#import<GameKit/GameKit.h>

@interface GameCenterHelper : NSObject <GKLeaderboardViewControllerDelegate>{
    BOOL gameCenterAvailable;
    BOOL userAuthenticated;
    UIViewController *tempVC;
}

@property (assign, readonly) BOOL gameCenterAvailable;

+ (GameCenterHelper *)sharedInstance;
- (void)authenticateLocalUser;
- (void) showLeaderboard;
- (void) reportScore:(int64_t) score;

@end
