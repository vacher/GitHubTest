#include "GameMenuScene.h"
#include "GameManager.h"
//#include "GameWorldScene.h"
//#include "GameHelpLayer.h"

using namespace cocos2d;

#ifdef USE_GAMECENTER
#import "GameCenterHelper.h"
#endif // DEBUG

#ifdef USE_GAMECENTER
#include "GameSMSHelper.h"
#endif

#ifdef USE_SHARESDK
#include "GameShareHelper.h"
#endif


Scene* GameMenuScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = GameMenuScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

bool GameMenuScene::init()
{
    bool bRet = false;

    do 
    {
        CCLOG("GameStartScene::init in");
		CC_BREAK_IF(!BaseLayer::init());
        
// 		//1 初始化播放声音
// 		CCUserDefault::sharedUserDefault()->setBoolForKey(KEY_PLAYMUISC,true);
// 		CCUserDefault::sharedUserDefault()->setBoolForKey(KEY_PLAYEFFECT,true);
// 		deGameManager->playAudioMusic(MISC_BG_MP3);
// 
// 		//2 背景元素
 		setViewElems();
 
		//3 功能按钮
		setOperateElems();
 
 		//4 系统按钮
 		setSystemElems();
// 
// 		//5 粒子效果
// 		setParticleEffect();

        log("GameStartScene::init out");

        bRet = true;
    } while (0);

    return bRet;
}

bool GameMenuScene::setViewElems()
{
	bool bRet = false;

	do 
	{
		//background
		auto bg = Director::getInstance()->getTextureCache()->getTextureForKey(MENU_BG);
		auto spStartBG =  Sprite::createWithTexture(bg);
		spStartBG->setPosition(getWinCenter());
		this->addChild(spStartBG);

		//title
// 		m_spTitle =  Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(START_TITLE));
// 		m_spTitle->setPosition(Point(getWinSize().width*0.5,getWinSize().height+m_spTitle->getContentSize().height));
// 		this->addChild(m_spTitle);

// 		CCSprite *spLogo =  CCSprite::createWithTexture(CCTextureCache::sharedTextureCache()->textureForKey(START_LOGO));
// 		spLogo->setPosition(ccp(getWinSize().width*0.5,getWinSize().height*0.5));
// 		this->addChild(spLogo);

		bRet = true;
	} while (0);

	return bRet;
}

bool GameMenuScene::setOperateElems()
{
	bool bRet = false;

	do 
	{
		//1 order
		auto pStartItem = MenuItemSprite::create(\
			Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(START_PLAY_NORMAL)), \
			Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(START_PLAY_SELECT)), \
			CC_CALLBACK_1(GameMenuScene::menuGameCallback,this));
		pStartItem->setTag(TAG_WELCOME_PLAY);
		pStartItem->setPosition(Point(getWinSize().width*0.5,getWinSize().height*0.5));

		m_pMenu = Menu::create(pStartItem,NULL);
		m_pMenu->setPosition(Point::ZERO);
		this->addChild(m_pMenu,1);

		bRet = true;
	} while (0);

	return bRet;
}

bool GameMenuScene::setSystemElems()
{
	bool bRet = false;

	do 
	{

		auto pLeadItem = MenuItemSprite::create(\
			Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(START_LEADER_NORMAL)), \
			Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(START_LEADER_SELECT)), \
			CC_CALLBACK_1(GameMenuScene::menuGameCallback, this));
		pLeadItem->setTag(TAG_WELCOME_LEADBOARD);
		pLeadItem->setPosition(Point(getWinSize().width*0.2, getWinSize().height*0.3));

		auto pOptionItem = MenuItemSprite::create(\
			Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(START_SETTING_NORMAL)), \
			Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(START_SETTING_SELECT)), \
			CC_CALLBACK_1(GameMenuScene::menuGameCallback, this));
		pOptionItem->setTag(TAG_WELCOME_SETTING);
		pOptionItem->setPosition(Point(getWinSize().width*0.8, getWinSize().height*0.3));

		m_pMenu = Menu::create(pLeadItem, pOptionItem,NULL);
		m_pMenu->setPosition(Point::ZERO);
		this->addChild(m_pMenu, 1);

// 		//1 lead
// 		CCMenuItemSprite* pLeadItem = CCMenuItemSprite::create(\
// 			CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(START_LEADER_NORMAL)),\
// 			CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(START_LEADER_SELECT)),\
// 			this,\
// 			menu_selector(GameStartScene::menuGameCallback));
// 		pLeadItem->setTag(TAG_WELCOME_LEADBOARD);
// 		pLeadItem->setPosition(ccp(EDGE_SYGBTN,getWinSize().height*0.2));
// 		pLeadItem->setOpacity(0);
// 
//         //2 分享
// 		CCMenuItemSprite* pEmailItem = CCMenuItemSprite::create(\
// 			CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(START_SHARE_NORMAL)), \
// 			CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(START_SHARE_SELECT)), \
// 			this,\
// 			menu_selector(GameStartScene::menuGameCallback));
// 		pEmailItem->setTag(TAG_WELCOME_SHARE);
// 		pEmailItem->setPosition(ccp(EDGE_SYGBTN,getWinSize().height*0.1));
// 		pEmailItem->setOpacity(0);
// 
// 
// 		// 3 music
// 		m_pItemVon  = CCMenuItemSprite::create(\
// 			CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(MUSICON_NORMAL)),\
// 			CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(MUSICON_PRESS)));
// 		m_pItemVon->setOpacity(0);
// 
// 		CCMenuItemSprite* pitemVoff = CCMenuItemSprite::create(\
// 			CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(MUSICOFF_NORMAL)),\
// 			CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(MUSICOFF_PRESS)));
// 
// 		CCMenuItemToggle* pMusic=NULL;
// 		if(CCUserDefault::sharedUserDefault()->getBoolForKey(KEY_PLAYMUISC,true))
// 		{
// 			pMusic = CCMenuItemToggle::createWithTarget(this,menu_selector(GameStartScene::menuGameCallback),m_pItemVon,pitemVoff,NULL);
// 		}
// 		else 
// 		{
// 			pMusic=CCMenuItemToggle::createWithTarget(this,menu_selector(GameStartScene::menuGameCallback),pitemVoff,m_pItemVon,NULL);
// 		}
// 		pMusic->setPosition(ccp(getWinSize().width-EDGE_SYGBTN,getWinSize().height*0.2)); 
// 		pMusic->setTag(TAG_WELCOME_MUSIC);
// 		
// 
// 		//4 sound
// 		m_pItemEff = CCMenuItemSprite::create(\
// 			CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(EFFECTON_NORMAL)),\
// 			CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(EFFECTON_PRESS)));
// 		m_pItemEff->setOpacity(0);
// 
// 		CCMenuItemSprite* pItemEffVoff = CCMenuItemSprite::create(\
// 			CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(EFFECTOFF_NORMAL)),\
// 			CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(EFFECTOFF_PRESS)));
// 
// 		CCMenuItemToggle* pEffect=NULL;
// 		if(CCUserDefault::sharedUserDefault()->getBoolForKey(KEY_PLAYEFFECT,true))
// 		{
// 			pEffect = CCMenuItemToggle::createWithTarget(this,menu_selector(GameStartScene::menuGameCallback),m_pItemEff,pItemEffVoff,NULL);
// 		}
// 		else 
// 		{
// 
// 			pEffect = CCMenuItemToggle::createWithTarget(this,menu_selector(GameStartScene::menuGameCallback),pItemEffVoff,m_pItemEff,NULL);
// 		}
// 		pEffect->setPosition(ccp(getWinSize().width-EDGE_SYGBTN,getWinSize().height*0.1));  
// 		pEffect->setTag(TAG_WELCOME_SOUND);
// 
// 		m_pExMenu =CCMenu::create(pLeadItem,pEmailItem,pMusic,pEffect,NULL);
// 		m_pExMenu->setPosition(CCPointZero);
// 		this->addChild(m_pExMenu,1);

		bRet = true;
	} while (0);

	return bRet;
}

void GameMenuScene::setParticleEffect()
{
// 	//CCParticleBatchNode
// 	CCParticleSystem* myParticle = CCParticleSystemQuad::create("particle.plist");
// 	CCParticleBatchNode *batch = CCParticleBatchNode::createWithTexture(myParticle ->getTexture());
// 	batch->addChild(myParticle );
// 	batch->setPosition(ccp(-getWinSize().width*0.5,0));
// 	addChild(batch, 10);
}

void GameMenuScene::menuGameCallback(Ref* pSender)
{
	Node *node = (Node*)pSender;
	switch (node->getTag())
	{
	case TAG_WELCOME_SETTING:
		{//设置
			showOption();
		}
		break;
	case TAG_WELCOME_PLAY:
		{//开始
			deGameManager->changeScene(SCENE_ID_WORLD);
		}
		break;
    case TAG_WELCOME_LEADBOARD:
		{//排行榜
            showLeaderboard();
		}
        break;
    case TAG_WELCOME_SHARE:
		{//分享
			shareContent();
		}
        break;
    case TAG_WELCOME_MSG:
        {//msg
            sendShortMsg();
        }
        break;
    case TAG_WELCOME_EMAIL:
        {//msg
            sendEmail();
        }
            break;
    case TAG_WELCOME_MUSIC:
		{//音乐
			if(UserDefault::getInstance()->getBoolForKey(KEY_PLAYMUISC,true))
			{
				deGameManager->pauseAudioMusic();
				UserDefault::getInstance()->setBoolForKey(KEY_PLAYMUISC, false);
			}else 
			{
				deGameManager->resumeAudioMusic();              
				UserDefault::getInstance()->setBoolForKey(KEY_PLAYMUISC, true);
				CCLOG("music is play");
			}
		}
		break;
	case  TAG_WELCOME_SOUND:
		{//声音
			if (UserDefault::getInstance()->getBoolForKey(KEY_PLAYEFFECT, true))
			{
				UserDefault::getInstance()->setBoolForKey(KEY_PLAYEFFECT, false);
			}
			else 
			{
				UserDefault::getInstance()->setBoolForKey(KEY_PLAYEFFECT, true);
			}
		}
		break;
	default:
		break;
	}
}

void GameMenuScene::onEnterTransitionDidFinish()
{
	CCLayer::onEnterTransitionDidFinish();

/*	float movetime = 0.1f;
	float delaytime = 0.1f;
	float fadetime = 2.0f;

	//title
	CCMoveTo *titlemove = CCMoveTo::create(movetime*2,ccp(getWinSize().width*0.5,getWinSize().height*0.5+190));
	CCCallFuncN *titlecallback = CCCallFuncN::create(this, callfuncN_selector(GameMenuScene::animateTitleCallback));
	m_spTitle->runAction(CCSequence::create(titlemove,titlecallback,NULL));

	//func btn
	CCNode *node1 = m_pMenu->getChildByTag(TAG_WELCOME_ORDER);
	CCDelayTime *delay1 = CCDelayTime::create(delaytime);
	CCMoveTo *move1 = CCMoveTo::create(movetime,ccp(getWinSize().width*0.5,getWinSize().height*0.5+SPACE_FUNCBTN));
	CCCallFuncN *callback1 = CCCallFuncN::create(this, callfuncN_selector(GameMenuScene::animateBtnCallback));
	node1->runAction(CCSequence::create(delay1,move1,callback1,NULL));

	CCNode *node2 = m_pMenu->getChildByTag(TAG_WELCOME_REVERSE);
	CCDelayTime *delay2 = CCDelayTime::create(delaytime*2);
	CCMoveTo *move2 = CCMoveTo::create(movetime,ccp(getWinSize().width*0.5,getWinSize().height*0.5-SPACE_FUNCBTN*0.5));
	CCCallFuncN *callback2 = CCCallFuncN::create(this, callfuncN_selector(GameMenuScene::animateBtnCallback));
	node2->runAction(CCSequence::create(delay2,move2,callback2,NULL));

	CCNode *node3 = m_pMenu->getChildByTag(TAG_WELCOME_CHOISE);
	CCDelayTime *delay3 = CCDelayTime::create(delaytime*3);
	CCMoveTo *move3 = CCMoveTo::create(movetime,ccp(getWinSize().width*0.5,getWinSize().height*0.5-SPACE_FUNCBTN*2));
	CCCallFuncN *callback3 = CCCallFuncN::create(this, callfuncN_selector(GameMenuScene::animateBtnCallback));
	node3->runAction(CCSequence::create(delay3,move3,callback3,NULL));

	//system btn
	CCNode *nodeEx1 = m_pExMenu->getChildByTag(TAG_WELCOME_LEADBOARD);
	CCFadeIn *fade1 = CCFadeIn::create(fadetime);
	nodeEx1->runAction(fade1);

	CCNode *nodeEx2 = m_pExMenu->getChildByTag(TAG_WELCOME_SHARE);
	CCFadeIn *fade2 = CCFadeIn::create(fadetime);
	nodeEx2->runAction(fade2);

	CCFadeIn *fade3 = CCFadeIn::create(fadetime);
	m_pItemVon->runAction(fade3);

 	CCFadeIn *fade4 = CCFadeIn::create(fadetime);
 	m_pItemEff->runAction(fade4);
    
    //显示广告
    //scheduleOnce(schedule_selector(GameStartScene::showCommercial), 1.0);
    showCommercial(0);*/
}

void GameMenuScene::showCommercial(float dt)
{
#ifdef USE_COMM_SCREEN
    //显示插屏广告
    UIApplication* clientApp = [UIApplication sharedApplication];
    UIWindow* topWindow = [clientApp keyWindow];
    [topWindow.rootViewController loadScreenAD];
#endif
}

void GameMenuScene::animateBtnCallback(Node *sender)
{
	//1 play sound
	deGameManager->playAudioSound(SOUND_INSCENE);

	//2 set visible
	((MenuItemSprite*)sender)->setEnabled(true);

	//3 play animate
	auto toBig = CCScaleTo::create(0.5,1.1f);
	auto toSmall = CCScaleTo::create(0.5, 1.0f);
	auto delay = CCDelayTime::create(2.0f);
	sender->runAction(CCRepeatForever::create(CCSequence::create(toBig,toSmall,delay,NULL)));
}

void GameMenuScene::animateTitleCallback(Node *sender)
{
	//1 play sound
	deGameManager->playAudioSound(SOUND_INSCENE);

}

//排行榜
void GameMenuScene::showLeaderboard()
{
#ifdef USE_GAMECENTER
    [[GameCenterHelper sharedInstance] showLeaderboard];
#endif // USE_GAMECENTER
}
//设置
void GameMenuScene::showOption()
{
	MessageBox("test", "Option");
}
//分享
void GameMenuScene::shareContent()
{
#ifdef USE_SHARESDK
    GameShareHelper::sharedInstance()->shareContent();
#endif
}

//发短信
void GameMenuScene::sendShortMsg()
{
#ifdef USE_GAMECENTER
    [[GameSMSHelper sharedInstance] sendGameSMS];
#endif
}

//发送邮件
void GameMenuScene::sendEmail()
{
    
}

