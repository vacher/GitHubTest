/*
 该场景为游戏开始画面，在加载logo和默认画面后，玩家会看到此画面。

 通过此画面，玩家可以选择开始游戏、进入商城、查看开发者信息，并可以设置开启或关闭游戏中的音效。
 */
#ifndef __STARTGAME_SCENE_H__
#define __STARTGAME_SCENE_H__

#include "Basic/BaseLayer.h"

enum EnMenuTag {
	TAG_WELCOME_PLAY = 100,
	TAG_WELCOME_HELP,
	TAG_WELCOME_SETTING,
	TAG_WELCOME_LEADBOARD,
	TAG_WELCOME_ACHIEVEMENT,
	TAG_WELCOME_ADVERT,
	TAG_WELCOME_SHARE,
	TAG_WELCOME_BTN1,
	TAG_WELCOME_BTN2,
	TAG_WELCOME_BNT3,
	TAG_WELCOME_MORE,
	TAG_WELCOME_EMAIL,
	TAG_WELCOME_MSG,
	TAG_WELCOME_MUSIC,
	TAG_WELCOME_SOUND,
	TAG_SOUND_ON,
	TAG_MUSIC_ON
};	


#define EDGE_SYGBTN 80
#define SPACE_FUNCBTN 80

class GameMenuScene : public BaseLayer
{
public:
    bool init();
	static cocos2d::Scene* createScene();
	CREATE_FUNC(GameMenuScene);

	virtual void onEnterTransitionDidFinish();

    void showCommercial(float dt);
    
private:
	//设置背景元素
	bool setViewElems();
	//设置操作按钮
	bool setOperateElems();
	//设置系统按钮
	bool setSystemElems();

	//菜单回调
	void menuGameCallback(Ref* pSender);

	//title动画
	void animateTitleCallback(Node *sender);
	//按钮动画
	void animateBtnCallback(Node *sender);
	//粒子效果
	void setParticleEffect();
    
private:
    //排行榜
    void showLeaderboard();
	//设置
	void showOption();
    //广告
    void showCommercial();
    //分享
    void shareContent();
    //发短信
    void sendShortMsg();
    //发送邮件
    void sendEmail();
    
private:
	Sprite *m_spTitle;
	Menu	 *m_pMenu;
	Menu	 *m_pExMenu;
	MenuItemSprite* m_pItemVon;
	MenuItemSprite* m_pItemEff;
};

#endif