//  GamePlayLayer.h
#ifndef __GAMEWORLD_SCENE_H__
#define __GAMEWORLD_SCENE_H__

#include "Basic/BaseLayer.h"

enum EnSceneLayerZNum {
	Z_BACKGROUND_LAYER = 0,
	Z_SHOW_LAYER = 5,
	Z_PLAY_LAYER= 10,
	Z_HUD_LAYER = 15,
	Z_MSG_LAYER = 20
};

enum EnSceneElemTag {
	tag_LAYER_BACKGROUND = 1,
	tag_LAYER_SHOW = 2,
	tag_LAYER_PLAYER = 3,
	tag_LAYER_HUD =4,
	tag_LAYER_MSG= 5
};

#define  MAX_ARRAYNUM 100
	
class GameHudLayer;
class GamePlayLayer;
class GameMapLayer;
class GameWorldScene:public BaseLayer
{
public:
	GameWorldScene(void);
	~GameWorldScene(void);

	bool init();
	static cocos2d::Scene* createScene();
	CREATE_FUNC(GameWorldScene);

	//进入/退出场景
	virtual void onEnterTransitionDidFinish();
    virtual void onExit();
    
	//游戏运行的外部接口
	void addScore(int nScore);
	void resetBlood();
	void startGame();
	void pauseGame();
	void helpGame();
	void nextLevel();
    void stopGame();//先停止状态
    void overGame();//执行动画后弹出结束对话框
    
    //添加广告//移除广告
    void addCommercials();
    void removeCommercials();
    
private:
	void gameOverCallback(Node *sender);
   

private:
	GameMapLayer      *m_pMapLayer;
	GameHudLayer      *m_pHudLayer;
	GamePlayLayer     *m_pPlayLayer;
};

#endif