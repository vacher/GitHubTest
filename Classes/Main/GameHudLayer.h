//DotHudController.h

#ifndef __GAMEHUD_H__
#define __GAMEHUD_H__

#include "cocos2d.h"
#include "Basic/BaseLayer.h"
#include "Basic/GameResouces.h"
#include "Basic/GameConfigures.h"

class GameHudLayer:public BaseLayer
{
public:
	GameHudLayer(void);
	~GameHudLayer(void);

	//�̳�
	virtual void onEnter();
	virtual bool init();
	CREATE_FUNC(GameHudLayer);

	//���õȼ�
	void resetLevel();
	void stopClockRun();

	//���ӷ���
	void animateAddScore(Vec2 scorePoint);
	//��Ѫ
	void resetBlood();

private:
	//����
	bool addScoreLabel();
	void scoreComCallback(Node *sender);

	//ʱ��
	bool addTimeClock();
	void animateClockRun();
	void progressCallback();
	
	//��ͣ
	bool addPauseButton();
	void pauseGameCallBack(Ref *obj);

	//����
	bool addHelpButton();
	void helpGameCallBack(Ref *obj);

	//Ѫ��
	bool addBloodLabel();
	
private:
	cocos2d::Sprite		 * m_arrBloods[3];
	cocos2d::LabelAtlas	 * m_pLevelLabel;
	cocos2d::LabelAtlas	 * m_pScoreLabel;
	cocos2d::ProgressTimer * m_prossTimer;
	int m_nLevel;
	int m_nBloodNum;
};
#endif
