#include "GamePlayLayer.h"
#include "GameWorldScene.h"
#include "GameManager.h"
#include "Entity/EntitySprite.h"
#include "Entity/DEnemy.h"

#include "FoodLayer.h"
#include "EnemyLayer.h"

using namespace cocos2d;
using namespace CocosDenshion;

GamePlayLayer::GamePlayLayer(void)
{
	m_bGameRun = false;
	m_spriteFish = nullptr;
}

GamePlayLayer::~GamePlayLayer(void)
{
}

bool GamePlayLayer::init()
{
	bool bRet = false;

	do 
	{
		CC_BREAK_IF(!BaseLayer::init());
		
		//1 创建Food层
		auto foodLayer = FoodLayer::create();
		this->addChild(foodLayer, Z_FoodLayer, Tag_FoodLayer);

		//2 创建Monter层
		auto enemyLayer = EnemyLayer::create();
		this->addChild(enemyLayer, Z_EnemyLayer, Tag_EnemyLayer);

		//3 创建Player
		m_spriteFish = Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("redfish.png"));
		m_spriteFish->setPosition(Point(getWinSize().width*0.5, 100));
		this->addChild(m_spriteFish,3,Tag_Player);
		m_spriteFish->setVisible(false);

		//4 开启触摸
		initTouches();

		bRet = true;
	} while (0);

	return bRet;
}

void GamePlayLayer::initTouches()
{
	//1创建一个事件监听器//EventListenerTouchOneByOne（单点触摸） 和 EventListenerTouchAllAtOnce（多点触摸）
	auto listener = EventListenerTouchOneByOne::create();
	//2 绑定触摸事件//单点触摸
	listener->onTouchBegan = CC_CALLBACK_2(GamePlayLayer::onTouchBegan, this);// 触摸开始时触发
	listener->onTouchMoved = CC_CALLBACK_2(GamePlayLayer::onTouchMoved, this);// 触摸移动时触发
	listener->onTouchEnded = CC_CALLBACK_2(GamePlayLayer::onTouchEnded, this);// 触摸接触时触发
	listener->onTouchCancelled = CC_CALLBACK_2(GamePlayLayer::onTouchCancelled, this);// 触摸退出时触发

	/* //多点触摸
	auto listener = EventListenerTouchAllAtOnce::create();
	listener->onTouchBegan = CC_CALLBACK_2(GamePlayLayer::onTouchesBegan, this);// 触摸开始时触发
	listener->onTouchMoved = CC_CALLBACK_2(GamePlayLayer::onTouchesMoved, this);// 触摸移动时触发
	listener->onTouchEnded = CC_CALLBACK_2(GamePlayLayer::onTouchesEnded, this);// 触摸接触时触发
	listener->onTouchCancelled = CC_CALLBACK_2(GamePlayLayer::onTouchesCancelled, this);// 触摸退出时触发
	*/

	//3 添加监听器
	listener->setSwallowTouches(true);//不向下传递触摸
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, m_spriteFish);
}

void GamePlayLayer::startPlaying()
{//开始运行
	log("GamePlayLayer::startPlaying in");
	m_bGameRun = true;

	log("GamePlayLayer::startPlaying out");
}

void GamePlayLayer::overGame()
{
	m_bGameRun = false;
	log("over game");

	//添加失败界面
	Size size = Director::getInstance()->getWinSize();
	LayerColor* layer = LayerColor::create(Color4B(0, 0, 0, 190), size.width, size.height);
	Sprite* sp = Sprite::create("game_lost.png");
	sp->setPosition(Point(size.width*0.5, size.height*0.5));
	layer->addChild(sp);
	this->addChild(layer, 100);

	
	scheduleOnce(schedule_selector(GamePlayLayer::popOverDiag),1.0f);
}

void GamePlayLayer::popOverDiag(float delta)
{
	((GameWorldScene*)this->getParent())->overGame();
}

void GamePlayLayer::addScore(int nScore,Vec2 nodePos)
{
	auto spAddScore = Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(SCORE_ADD));
	spAddScore->setScale(0.5f);
	string strScore = Convert2String(nScore);
	auto aScoreLabel = LabelAtlas::create(strScore.c_str(), FONT_ADD_SCORE, 36, 46, '0');
	aScoreLabel->setPosition(Point(35, 0));
	spAddScore->addChild(aScoreLabel);
	spAddScore->setPosition(nodePos);
	this->addChild(spAddScore, Z_Score);

	//创建后续动作和回调
	auto func = [=](){
		//发送分数
		((GameWorldScene*)this->getParent())->addScore(nScore);

		//移除自己
		spAddScore->removeFromParentAndCleanup(true);
	};
	auto moveby = MoveBy::create(0.5f, Point(0, 10));
	auto fade = FadeOut::create(0.5f);
	auto callFunc = CallFunc::create(func);
	spAddScore->runAction(CCSequence::create(moveby, fade, callFunc, NULL));
}


/************************************************** 触摸响应****************************************************/
bool GamePlayLayer::onTouchBegan(Touch *touch, Event *event)
{
	Vec2 pos = touch->getLocation();
	m_spriteFish->setPosition(pos);
	m_spriteFish->setVisible(true);

	//设置游戏开始运行
	UserDefault::getInstance()->setBoolForKey(KEY_GAMERUNNING,true);

	return true;
}

void GamePlayLayer::onTouchMoved(Touch *touch, Event *event)
{
	Vec2 pos = touch->getLocation();
	m_spriteFish->setPosition(pos);
}

void GamePlayLayer::onTouchEnded(Touch *touch, Event *event)
{
	if (m_spriteFish == nullptr)
	{

	}
	//MessageBox("End", "touch");
	log("over");
}

void GamePlayLayer::onTouchCancelled(Touch *touch, Event *event)
{

}

/*
void GamePlayLayer::onTouchesBegan(const std::vector< cocos2d::Touch *>& touches, cocos2d::Event * event)
{
	MessageBox("begin", "touch");
}
void GamePlayLayer::onTouchesEnded(const std::vector< cocos2d::Touch *>& touches, cocos2d::Event * event)
{
	MessageBox("End", "touch");
}
void GamePlayLayer::onTouchesMoved(const std::vector< cocos2d::Touch *>& touches, cocos2d::Event * event)
{

}
void GamePlayLayer::onTouchesCancelled(const std::vector< cocos2d::Touch *>& touches, cocos2d::Event * event)
{

}*/

/********************************************* 角色管理 ********************************************/
Sprite* GamePlayLayer::getPlayer()
{
	return m_spriteFish;
}


void GamePlayLayer::logic(float delta)
{
	FoodLayer *foodLayer = (FoodLayer*)this->getChildByTag(Tag_FoodLayer);
	foodLayer->logic(delta);
}

