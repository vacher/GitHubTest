
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

	//��ʼ��
	CREATE_FUNC(EnemyLayer);
	virtual bool init();

	//�߼�
	void logic(float delta);

	void removeEnemy(DEnemy *enemy);

private:
	/* ������м���Ҫ�����Ĺ������ */
	Vector<DEnemy*> m_enemyVec;
	
	/* ��ʱ�� */
	float m_fTimeCounter;
};

#endif