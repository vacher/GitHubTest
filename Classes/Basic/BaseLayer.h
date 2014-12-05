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

	//��ȡ����λ��
	cocos2d::Size getWinSize();// �õ���ǰ���Ӵ��ڵĴ�С
	cocos2d::Vec2 getWinOrigin();// �õ���ǰ���Ӵ��ڵ���ʼ��
	cocos2d::Vec2 getWinCenter();// �õ���Ļ���м�ĵ�
	cocos2d::Vec2 converSpritRel(float x, float y);//��������Ļ�е�λ��ת���� ���Ӵ��ڵ� λ��

	//��Ϸ����
	void playBackgroundMusic(const char *name);
	void stopBackgroundMusic();
};
#endif