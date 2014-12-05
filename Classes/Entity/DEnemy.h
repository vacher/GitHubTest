#ifndef __DEnemy_H__
#define __DEnemy_H__


#include "cocos2d.h"
using namespace cocos2d;

class DEnemy:public cocos2d::Sprite
{
public:
	DEnemy(void);
	~DEnemy(void);

public:
	//实例化函数
	static DEnemy* createEnemy(const char* fileName,int _type);
	
	//价值多少分数
	int m_nScoreValue;

private:
	//初始化
	void enemyInit(const char* fileName,int _type);
	//敌人成动态表现
	void createAnimate(const char* fileName,int allCount);
	//敌人逻辑
	void update(float time);

private:
	//是否已经运动过了
	bool m_isActed;
	//当前敌人类型
	int m_nType;
};
#endif
