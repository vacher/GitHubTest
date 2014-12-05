
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

	//��ʼ��
	CREATE_FUNC(FoodLayer);
	virtual bool init();

	//�߼�
	void logic(float delta);

private:
	/* �������ļ��м��ع������� */
	void loadMonstersFromTmxConf();
	/* ������м���Ҫ�����Ĺ������ */
	Vector<DFood*> m_foodVec;
	
	/* ��ʱ�� */
	float m_fTimeCounter;
};

#endif