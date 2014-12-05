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

	//继承
	virtual void onEnter();
	virtual bool init();
	CREATE_FUNC(GameHudLayer);

	//重置等级
	void resetLevel();
	void stopClockRun();

	//增加分数
	void animateAddScore(Vec2 scorePoint);
	//减血
	void resetBlood();

private:
	//分数
	bool addScoreLabel();
	void scoreComCallback(Node *sender);

	//时钟
	bool addTimeClock();
	void animateClockRun();
	void progressCallback();
	
	//暂停
	bool addPauseButton();
	void pauseGameCallBack(Ref *obj);

	//帮助
	bool addHelpButton();
	void helpGameCallBack(Ref *obj);

	//血条
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
