
#ifndef __ENEMY_LAYER_H__
#define __ENEMY_LAYER_H__

#include "cocos2d.h"
USING_NS_CC;

class DEnemy;
class EnemyLayer :public Layer
{
public:
	EnemyLayer();
	~EnemyLayer();

	//初始化
	CREATE_FUNC(EnemyLayer);
	virtual bool init();

	//逻辑
	void logic(float delta);

	void removeEnemy(DEnemy *enemy);

private:
	/* 存放所有即将要出场的怪物对象 */
	Vector<DEnemy*> m_enemyVec;
	
	/* 计时器 */
	float m_fTimeCounter;
};

#endif