#include "GameWorldScene.h"
#include "GameManager.h"
#include "GameMapLayer.h"
#include "GamePlayLayer.h"
#include "GameHudLayer.h"

// #include "Sprites/EntitySprite.h"
// #include "Sprites/MsgTipSprite.h"

// #include "GamePauseLayer.h"

// #include "GameOverLayer.h"
// #include "GameHelpLayer.h"


#ifdef USE_COMM_BANNER
#include "DuoMCommHelper.h"
#endif

using namespace cocos2d;
using namespace CocosDenshion;

Scene* GameWorldScene::createScene()
{
	auto scene = Scene::create();

	auto layer = GameWorldScene::create();

	scene->addChild(layer);

	return scene;
}

GameWorldScene::GameWorldScene(void)
{
	m_pHudLayer      = NULL;
	m_pPlayLayer     = NULL;
}

GameWorldScene::~GameWorldScene(void)
{

}

bool GameWorldScene::init()
{
	bool bRet = false;

	do 
	{
		CC_BREAK_IF(!BaseLayer::init());
		
		//1 初始化
		UserDefault::getInstance()->setIntegerForKey(KEY_CURRENTSCORE,0);	
		UserDefault::getInstance()->setIntegerForKey(KEY_HITHESTSCORE, 0);
		UserDefault::getInstance()->setBoolForKey(KEY_GAMERUNNING, false);


		//2 背景层
		m_pMapLayer = GameMapLayer::createMap(PLAY_BG);
		CC_BREAK_IF(!m_pMapLayer);
		this->addChild(m_pMapLayer, Z_BACKGROUND_LAYER, tag_LAYER_BACKGROUND);

		//3 游戏层
		m_pPlayLayer = GamePlayLayer::create();
		CC_BREAK_IF(!m_pPlayLayer);
		this->addChild(m_pPlayLayer,Z_PLAY_LAYER,tag_LAYER_PLAYER);

		//4 状态层
		m_pHudLayer = GameHudLayer::create();
		m_pHudLayer->setPosition(Point(0, getWinSize().height - HUDLAYER_HEIHT));
		this->addChild(m_pHudLayer,Z_HUD_LAYER,tag_LAYER_HUD);

		bRet = true;
	} while (0);

	return bRet;
}

/*************************************************** ≥ı ºªØ ********************************************************/

void GameWorldScene::onEnterTransitionDidFinish()
{
	CCLayer::onEnterTransitionDidFinish();

     deGameManager->playAudioMusic(MISC_BG_MP3);
    
    //打开帮助
//	helpGame();
	
}

void GameWorldScene::onExit()
{
    CCLayer::onExit();
}

/************************************************* 状态改变 *********************************************/
void GameWorldScene::startGame()
{
// 	m_pPlayLayer->startPlaying();
// 
// 	m_pHudLayer->resetLevel();
    
    //after show start
    addCommercials();
}

void GameWorldScene::pauseGame()
{
// 	GamePauseLayer *pauseLayer = GamePauseLayer::create();
// 	if (pauseLayer)
// 	{
//         deGameManager->playAudioSound(SOUND_PAUSE);
//         
// 		CCDirector::sharedDirector()->pause();
// 		this->addChild(pauseLayer,100);
// 	}
}


void GameWorldScene::helpGame()
{
// 	GameHelpLayer *helpLayer = GameHelpLayer::create();
// 	if (helpLayer)
// 	{
// 		this->addChild(helpLayer,Z_MSG_LAYER);
// 	}
}

void GameWorldScene::overGame()
{
//     if (m_bPopOverDiag)
//     {//已经弹出了就返回
//         return;
//     }
//     
//     if(m_bProtectedStatus)
//     {//保护状态
//         return;
//     }
//     
//     //1 移除广告
//     removeCommercials();
// 
// 	//3 创建弹出对话框
// 	GameOverLayer *overLayer = GameOverLayer::create();
// 	if (overLayer)
// 	{
// 		overLayer->setPosition(ccp(0,getWinSize().height*0.5));
// 		this->addChild(overLayer,100);
//         
//         //弹出成功则置未true
//         m_bPopOverDiag = true;
// 	}
//  
// 	//4 移动到位置
// 	CCMoveTo *moveto = CCMoveTo::create(0.5f,ccp(0,0));
// 	CCCallFuncN *func = CCCallFuncN::create(this,callfuncN_selector(GameWorldScene::gameOverCallback));
// 	overLayer->runAction(CCSequence::create(moveto,func,NULL));
}

void GameWorldScene::gameOverCallback(Node *sender)
{//游戏结束回调
    deGameManager->stopAudioMusic();
    deGameManager->playAudioSound(SOUND_FAIL);
}

void GameWorldScene::stopGame()
{
//     if(m_bProtectedStatus)
//     {//保护状态
//         return;
//     }
//     
//     CCLOG("stopGame");
//     //2 重置状态
//     m_pPlayLayer->setGameRun(false);
//     m_pHudLayer->stopClockRun();
}

void GameWorldScene::addScore(int nScore)
{
	//m_pHudLayer->animateAddScore(scorePoint);
}

void GameWorldScene::nextLevel()
{
//     CCLOG("nextLevel");
// 	//下一关
//     m_pPlayLayer->startPlaying();
// 	m_pHudLayer->resetLevel();
}

void GameWorldScene::resetBlood()
{
//	m_pHudLayer->resetBlood();
}

//添加广告
void GameWorldScene::addCommercials()
{
#ifdef USE_COMM_BANNER
    DuoMCommHelper::sharedInstance()->addCommercialBannar();
#endif
}
//移除广告
void GameWorldScene::removeCommercials()
{
#ifdef USE_COMM_BANNER
    DuoMCommHelper::sharedInstance()->removeCommercialBannar();
#endif
}

