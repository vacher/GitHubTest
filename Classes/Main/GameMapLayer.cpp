#include "GameMapLayer.h"


GameMapLayer::GameMapLayer(void)
{
}


GameMapLayer::~GameMapLayer(void)
{
}

GameMapLayer* GameMapLayer::createMap(const char* fileName)
{
	GameMapLayer* map = new GameMapLayer();
	if(map && map->create())
	{
		map->autorelease();
		map->mapInit(fileName);
		return map;
	}
	CC_SAFE_DELETE(map);
	return NULL;
}

void GameMapLayer::mapInit(const char* fileName)
{
	Size size = Director::getInstance()->getWinSize();

	//创建第一张地图背景图
	auto turnImg = Sprite::createWithTexture(Director::getInstance()->getTextureCache()->getTextureForKey(fileName));
	turnImg->setPosition(Point(turnImg->getContentSize().width*0.5,turnImg->getContentSize().height*0.5));
	this->addChild(turnImg,0,tag_oneImg);

	//创建第二张地图背景图，用于交替循环
	auto turnImg2 = Sprite::createWithTexture(Director::getInstance()->getTextureCache()->getTextureForKey(fileName));
	turnImg2->setPosition(Point(turnImg2->getContentSize().width*0.5,turnImg2->getContentSize().height*1.5));
	this->addChild(turnImg2,0,tag_twoImg);

	this->scheduleUpdate();
}

void GameMapLayer::update(float time)
{
	Size size = Director::getInstance()->getWinSize();
	Sprite *sp1 = (Sprite*)this->getChildByTag(tag_oneImg);

	//当第一张地图超出屏幕外，将其重置坐标,接在当前显示的图片下
	if(sp1->getPositionY()<=-sp1->getContentSize().height*0.5)
	{
		sp1->setPosition(Point(sp1->getContentSize().width*0.5,sp1->getContentSize().height*1.5f-1));
	}
	else
	{
		sp1->setPosition(sp1->getPosition()+Point(0,-1));
	}
	//当第二张地图超出屏幕外，将其重置坐标,接在当前显示的图片下
	Sprite* sp2 = (Sprite*)this->getChildByTag(tag_twoImg);
	if(sp2->getPositionY()<=-sp2->getContentSize().height*0.5)
	{
		sp2->setPosition(Point(sp2->getContentSize().width*0.5,sp2->getContentSize().height*1.5f-1));
	}
	else
	{
		sp2->setPosition(sp2->getPosition()+Point(0,-1));
	}

}

void GameMapLayer::onExit()
{
	//解除更新函数
	this->unscheduleUpdate();
	Layer::onExit();
}