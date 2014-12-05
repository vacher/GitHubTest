#include "AppDelegate.h"
#include "GameManager.h"

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLView::create("My Game");
        director->setOpenGLView(glview);
    }
	
	/* 设置Win32屏幕大小为480X800, */
	glview->setFrameSize(SCREEN_DEFAULT_WIDTH, SCREEN_DEFAULT_HEIGHT);

	//设置设计分辨率
	glview->setDesignResolutionSize(SCREEN_DEFAULT_WIDTH, SCREEN_DEFAULT_HEIGHT, ResolutionPolicy::FIXED_WIDTH);

	//设置搜索路径
	std::vector<std::string> searchPaths;
	searchPaths.push_back("Config");
	searchPaths.push_back("Fonts");
	searchPaths.push_back("Misc");
	searchPaths.push_back("Particle");
	searchPaths.push_back("UIImages");
	searchPaths.push_back("Sprites");
	searchPaths.push_back("Background");
	searchPaths.push_back("Animation");
	FileUtils::getInstance()->setSearchPaths(searchPaths);
	//director->setContentScaleFactor(1440.0f / 320.0f);

    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);

    // create a scene. it's an autorelease object
	deGameManager->changeScene(SCENE_ID_MENU);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
     SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
     SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
