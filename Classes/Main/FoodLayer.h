
#ifndef __MONSTER_LAYER_H__
#define __MONSTER_LAYER_H__

#include "cocos2d.h"
USING_NS_CC;

class DFood;
class FoodLayer :public Layer
{
public:
	FoodLayer();
	~FoodLayer();

	//初始化
	CREATE_FUNC(FoodLayer);
	virtual bool init();

	//逻辑
	void logic(float delta);

private:
	/* 从配置文件中加载怪物数据 */
	void loadMonstersFromTmxConf();
	/* 存放所有即将要出场的怪物对象 */
	Vector<DFood*> m_foodVec;
	
	/* 计时器 */
	float m_fTimeCounter;
};

#endif