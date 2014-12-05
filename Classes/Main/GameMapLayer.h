#ifndef _SCROLLMap_H_
#define _SCROLLMap_H_

#include "cocos2d.h"
using namespace cocos2d;

typedef enum{
	tag_oneImg,
	tag_twoImg,
}tagMap;//枚举两张地图背景的交替出现

class GameMapLayer: public cocos2d::Layer
{
public:
	GameMapLayer(void);
	~GameMapLayer(void);

	//实例化函数
	static GameMapLayer* createMap(const char* fileName);

private:
	//初始化
	void mapInit(const char* fileName);
	//逻辑
	void update(float time);
	//生命周期函数的退出
	virtual void onExit();
};

#endif
