#ifndef _SCROLLMap_H_
#define _SCROLLMap_H_

#include "cocos2d.h"
using namespace cocos2d;

typedef enum{
	tag_oneImg,
	tag_twoImg,
}tagMap;//ö�����ŵ�ͼ�����Ľ������

class GameMapLayer: public cocos2d::Layer
{
public:
	GameMapLayer(void);
	~GameMapLayer(void);

	//ʵ��������
	static GameMapLayer* createMap(const char* fileName);

private:
	//��ʼ��
	void mapInit(const char* fileName);
	//�߼�
	void update(float time);
	//�������ں������˳�
	virtual void onExit();
};

#endif
