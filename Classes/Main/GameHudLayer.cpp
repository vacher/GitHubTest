#include "GameHudLayer.h"
#include "GameWorldScene.h"

using namespace cocos2d;

GameHudLayer::GameHudLayer(void)
{
	m_pLevelLabel     = NULL;
	m_pScoreLabel     = NULL;
	m_prossTimer      = NULL;
	m_nLevel          = 1;
	m_nBloodNum       = 3;
}

GameHudLayer::~GameHudLayer(void)
{
}

bool GameHudLayer::init()
{

	bool bRet = false;
	do 
	{
		log("GameHudLayer init");
		CC_BREAK_IF(!BaseLayer::init());

		auto bg = LayerColor::create(Color4B::RED);
		this->addChild(bg);

		//1 设置范围
		setContentSize(Size(getWinSize().width,100));

		//2 添加计时器
		//addTimeClock();

		//3 添加分数标签
		//addScoreLabel();

		//4 添加血
		//addBloodLabel();

		//5 添加帮助
		//addHelpButton();

		//6 添加暂停
		//addPauseButton();

		log("GameHudLayer init Finish");

		bRet = true;
	} while (0);

	return bRet;
}

void GameHudLayer::onEnter()
{
	CCLayer::onEnter();
	
}

bool GameHudLayer::addTimeClock()
{//计时器
	bool bRet=false;
	do
	{
// 		CCSprite *sp = CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(PLAY_CLOCK));
// 		m_prossTimer = CCProgressTimer::create(sp);
// 		m_prossTimer->setPosition(ccp(-getWinSize().width/2 + HUD_WIDTH_DELTA,-HUD_HEIGHT_DELTA-5));
// 		//…Ë÷√Ω¯∂»Ãıµƒ—˘ Ω
// 		m_prossTimer->setType( kCCProgressTimerTypeRadial);
// 		//…Ë÷√Ω¯∂»÷µ∑∂Œß[0,100]
// 		m_prossTimer->setPercentage(100);
// 		//∑¥Ω¯∂»º∆ ±
// 		//m_prossTimer->setReverseProgress(true);
// 		addChild(m_prossTimer);
// 
// 		m_pLevelLabel = CCLabelAtlas::create("1",FONT_GAME_SCORE,33,37,'0');
// 		CC_BREAK_IF(!m_pLevelLabel);
// 		m_pLevelLabel->setScale(0.8f);
// 		m_pLevelLabel->setAnchorPoint(ccp(0.5,0.5));
// 		m_pLevelLabel->setPosition(ccp(-getWinSize().width/2 + HUD_WIDTH_DELTA,-HUD_HEIGHT_DELTA-5));
// 		this->addChild(m_pLevelLabel,2);

		bRet = true;
	}while (0);
	return bRet;
}

void GameHudLayer::animateClockRun()
{
// 	m_prossTimer->stopAllActions();
// 
// 	m_prossTimer->setPercentage(0);
// 	CCProgressTo *to1 = CCProgressTo::create(GAME_RUNTIME, 100);//”Œœ∑ ±º‰
// 	CCCallFunc *func = CCCallFunc::create(this,callfunc_selector(GameHudLayer::progressCallback));
// 	m_prossTimer->runAction( CCSequence::create(to1,func,NULL));
}

void GameHudLayer::stopClockRun()
{
	//m_prossTimer->stopAllActions();
}

void GameHudLayer::progressCallback()
{
	//时间到
//     CCLOG("time out");
// 	GameWorldScene *pWorldScene = (GameWorldScene*)getParent();
//     pWorldScene->stopGame();
// 	pWorldScene->overGame();
}

void GameHudLayer::resetLevel()
{
// 	//…Ë÷√µ»º∂
// 	m_nLevel = CCUserDefault::sharedUserDefault()->getIntegerForKey(KEY_LEVELNUM,1);
// 	m_nLevel++;
// 	CCUserDefault::sharedUserDefault()->setIntegerForKey(KEY_LEVELNUM,m_nLevel);
// 	CCString *strLevel = CCString::createWithFormat("%d",m_nLevel);
// 	m_pLevelLabel->setString(strLevel->getCString());
// 
// 	animateClockRun();
}

bool GameHudLayer::addScoreLabel()
{//ÃÌº”∑÷ ˝

	bool bRet=false;
	do
	{
// 		CCSprite *spScoreBar =  CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(PLAY_SCOREBAR));
// 		spScoreBar->setPosition(ccp(0,0));
// 		this->addChild(spScoreBar);
// 
// 		m_pScoreLabel = CCLabelAtlas::create("0",FONT_GAME_SCORE,33,37,'0');
// 		CC_BREAK_IF(!m_pScoreLabel);
// 		m_pScoreLabel->setAnchorPoint(ccp(0.5,0.5));
// 		m_pScoreLabel->setPosition(ccp(22,-20));
// 		this->addChild(m_pScoreLabel,3);

		bRet = true;
	}while (0);
	return bRet;
}

void GameHudLayer::animateAddScore(Vec2 scorePoint)
{	
// 	CCSprite *spAddScore =  CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(SCORE_ADD));
// 	spAddScore->setScale(0.5f);
// 	CCString *strScore= CCString::createWithFormat("%d",MIN_SCORE_UNIT*((m_nLevel+10)/10));
// 	CCLabelAtlas* aScoreLabel = CCLabelAtlas::create(strScore->getCString(),FONT_ADD_SCORE,36,46,'0');
// 	aScoreLabel->setPosition(ccp(35,0));
// 	spAddScore->addChild(aScoreLabel);
// 	spAddScore->setPosition(scorePoint);
// 	this->addChild(spAddScore,2);
// 
// 	//¥¥Ω®∂Ø◊˜
// 	CCMoveBy *moveby = CCMoveBy::create(0.5f,ccp(0,10));
// 	CCFadeOut *fade = CCFadeOut::create(0.5f);
// 	CCCallFuncN *func = CCCallFuncN::create(this,callfuncN_selector(GameHudLayer::scoreComCallback));
// 	spAddScore->runAction(CCSequence::create(moveby,fade,func,NULL));

}		

void GameHudLayer::scoreComCallback(Node *sender)
{
// 	CCLOG("LL Call:%p",sender);
// 	if (sender)
// 	{
// 		//≤•∑≈…˘“Ù
// 
// 		//∑÷ ˝‘ˆº”
// 		int nCurrentScore = CCUserDefault::sharedUserDefault()->getIntegerForKey(KEY_CURRENTSCORE,0);
// 		nCurrentScore += MIN_SCORE_UNIT*((m_nLevel+10)/10);
// 		m_pScoreLabel->setString(CCString::createWithFormat("%d",nCurrentScore)->getCString());
// 		CCUserDefault::sharedUserDefault()->setIntegerForKey(KEY_CURRENTSCORE,nCurrentScore);
// 
// 		//…æ≥˝◊‘º∫
// 		sender->removeFromParent();
// 	}
}

bool GameHudLayer::addBloodLabel()
{
	bool bRet=false;
	do
	{
// 		for (int i =0 ;i<3;i++)
// 		{
// 			CCSprite * spBlood = CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(HUD_LIFE_FULL));
// 			spBlood->setPosition(ccp(-getWinSize().width*0.35+40*i,- HUD_HEIGHT_DELTA));
// 			this->addChild(spBlood);
// 
// 			CCSprite * spLostBlood = CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(HUD_LIFE_LOST));
// 			spLostBlood->setAnchorPoint(ccp(0,0));
// 			spLostBlood->setPosition(CCPointZero);
// 			spBlood->addChild(spLostBlood,1,11);
// 			spLostBlood->setVisible(false);
// 
// 			m_arrBloods[i] = spBlood;
// 		}

		bRet = true;
	}while (0);
	return bRet;
}

void GameHudLayer::resetBlood()
{
// 	if (m_nBloodNum<=0)
// 	{
// 		return;
// 	}
// 
// 	m_nBloodNum--;
// 	//œ‘ æµÙ—™
// 	m_arrBloods[m_nBloodNum]->getChildByTag(11)->setVisible(true);
// 
// 	//µÙ3∏ˆ”Œœ∑Ω· ¯
// 	if (m_nBloodNum<=0)
// 	{
// 		GameWorldScene *pScene = (GameWorldScene*)getParent();
// 		pScene->overGame();
// 	}
}

bool GameHudLayer::addHelpButton()
{
	bool bRet=false;
	do
	{
// 		// ¥¥Ω®∞Ô÷˙”Œœ∑∞¥≈•
// 		CCMenuItemSprite* pPause = CCMenuItemSprite::create(\
// 			CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(BTN_HELP_NORMAL)),\
// 			CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(BTN_HELP_PRESS)),\
// 			this,\
// 			menu_selector(GameHudLayer::helpGameCallBack));
// 		CC_BREAK_IF(!pPause);
// 		pPause->setScale(0.8f);
// 		pPause->setPosition(ccp(getWinSize().width/2 - 3*HUD_WIDTH_DELTA,-HUD_HEIGHT_DELTA));
// 
// 		CCMenu* pMenu = CCMenu::create(pPause,NULL);
// 		CC_BREAK_IF(!pMenu);
// 		pMenu->setPosition(CCPointZero);
// 		this->addChild(pMenu);

		bRet = true;
	}while (0);
	return bRet;
}

void GameHudLayer::helpGameCallBack(Ref *obj)
{
// 	GameWorldScene *pScene = (GameWorldScene*)getParent();
// 	pScene->helpGame();
}

bool GameHudLayer::addPauseButton()
{
	bool bRet=false;
	do
	{
// 		// ¥¥Ω®‘›Õ£”Œœ∑∞¥≈•
// 		CCMenuItemSprite* pPause = CCMenuItemSprite::create(\
// 			CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(PAUSE_BTN_NORMAL)),\
// 			CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(PAUSE_BTN_PRESS)),\
// 			this,\
// 			menu_selector(GameHudLayer::pauseGameCallBack));
// 
// 		CC_BREAK_IF(!pPause);
// 		pPause->setPosition(ccp(getWinSize().width/2 - HUD_WIDTH_DELTA,-HUD_HEIGHT_DELTA));
// 
// 		CCMenu* pMenu = CCMenu::create(pPause,NULL);
// 		CC_BREAK_IF(!pMenu);
// 		pMenu->setPosition(CCPointZero);
// 		this->addChild(pMenu);

		bRet = true;

	}while (0);
	return bRet;
}

void GameHudLayer::pauseGameCallBack(Ref *obj)
{
// 	GameWorldScene *pScene = (GameWorldScene*)getParent();
// 	pScene->pauseGame();
}

