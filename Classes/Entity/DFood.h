
#ifndef __DFOOD_H_
#define __DFOOD_H_
#include "cocos2d.h"
USING_NS_CC;

class DFood :public Node
{
public:
	DFood();
	~DFood();

	//初始化
	static DFood *create(int ID);
	virtual bool init(int ID);
	void update(float time);

	//添加到场景
	void joinToWorld(Node* parent);

	//激活状态
	void setActive(bool bAct);
	bool isActived();

	CC_SYNTHESIZE(int, m_ID, ID);
	CC_SYNTHESIZE(float, m_fShowTime, fShowTime);
	CC_SYNTHESIZE(int, m_iPosX, iPosX);
	CC_SYNTHESIZE(int, m_iPosY, iPosY);
	CC_SYNTHESIZE(int, m_iAtk, iAtk);
	CC_SYNTHESIZE(Value, m_sModelPath, sModelPath);
	CC_SYNTHESIZE(int, m_iValueScore, ValueScore);

private:
	void foodBeEat();
	void readJsonValue(const char *filename);

private:
	bool m_bActived;
	Sprite* m_spEnity;
};

#endif