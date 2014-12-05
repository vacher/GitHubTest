#ifndef __BASE_LAYER_H__
#define __BASE_LAYER_H__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
using namespace cocos2d;
using namespace CocosDenshion;

#define PI 3.14
class BaseLayer:public cocos2d::Layer{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(BaseLayer);

	//获取坐标位置
	cocos2d::Size getWinSize();// 得到当前可视窗口的大小
	cocos2d::Vec2 getWinOrigin();// 得到当前可视窗口的起始点
	cocos2d::Vec2 getWinCenter();// 得到屏幕正中间的点
	cocos2d::Vec2 converSpritRel(float x, float y);//把设在屏幕中的位置转化成 可视窗口的 位置

	//游戏音乐
	void playBackgroundMusic(const char *name);
	void stopBackgroundMusic();
};
#endif