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
	//ʵ��������
	static DEnemy* createEnemy(const char* fileName,int _type);
	
	//��ֵ���ٷ���
	int m_nScoreValue;

private:
	//��ʼ��
	void enemyInit(const char* fileName,int _type);
	//���˳ɶ�̬����
	void createAnimate(const char* fileName,int allCount);
	//�����߼�
	void update(float time);

private:
	//�Ƿ��Ѿ��˶�����
	bool m_isActed;
	//��ǰ��������
	int m_nType;
};
#endif
