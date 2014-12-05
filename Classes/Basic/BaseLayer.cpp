#include "BaseLayer.h"

Scene* BaseLayer::createScene()
{
	auto* scene = Scene::create();
	BaseLayer* layer= BaseLayer::create();
	scene->addChild(layer);
	return scene;
}

bool BaseLayer::init(){
	bool isRet=false;
	do 
	{
		CC_BREAK_IF(!Layer::init());
		isRet=true;
	} while (0);
	return isRet;
}

Size BaseLayer::getWinSize()
{
	return	Director::getInstance()->getVisibleSize();
}

Vec2 BaseLayer::getWinOrigin()
{
	return Director::getInstance()->getVisibleOrigin();
}

Vec2 BaseLayer::getWinCenter()
{
	return	Point(getWinSize().width / 2 + getWinOrigin().x, getWinSize().height / 2 + getWinOrigin().y);
}

Vec2 BaseLayer::converSpritRel(float x, float y){
	return Point(x + getWinOrigin().x, y + getWinOrigin().y);
}

//²¥·Å±³¾°ÒôÀÖ
void BaseLayer::playBackgroundMusic(const char *name)
{
	SimpleAudioEngine::getInstance()->playBackgroundMusic(name);
}

void BaseLayer::stopBackgroundMusic()
{
	SimpleAudioEngine::getInstance()->stopBackgroundMusic();
}
