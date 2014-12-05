//
//  GamePlayLayer.h
#ifndef __GAMEPLAY_LAYER_H__
#define __GAMEPLAY_LAYER_H__

#include "Basic/BaseLayer.h"

//对象标签
enum tag_PlayLayer
{
	Tag_Player = 300,
	Tag_Food ,
	Tag_Enemy,
	Tag_FoodLayer,
	Tag_EnemyLayer
};

enum Z_PlayLayer
{
	Z_FoodLayer = 1,
	Z_EnemyLayer =3,
	Z_Player = 5,
	Z_Food =7,
	Z_Enemy =9,
	Z_Score = 11
};

class DEnemy;
class GamePlayLayer:public BaseLayer
{
public:
	GamePlayLayer(void);	
	~GamePlayLayer(void);

	bool init();
	CREATE_FUNC(GamePlayLayer);

	//开始游戏
	void startPlaying();
	//游戏结束
	void overGame();
	void popOverDiag(float delta);
	
	//加分
	void addScore(int nScore, Vec2 nodePos);

	//触摸响应-单点
	virtual bool onTouchBegan(Touch *touch, Event *event);
	virtual void onTouchMoved(Touch *touch, Event *event);
	virtual void onTouchEnded(Touch *touch, Event *event);
	virtual void onTouchCancelled(Touch *touch, Event *event);

	//触摸响应-多点
// 	virtual void onTouchesBegan(const std::vector<cocos2d::Touch *>& touches, cocos2d::Event * event);
// 	virtual void onTouchesEnded(const std::vector<cocos2d::Touch *>& touches, cocos2d::Event * event);
// 	virtual void onTouchesMoved(const std::vector<cocos2d::Touch *>& touches, cocos2d::Event * event);
// 	virtual void onTouchesCancelled(const std::vector<cocos2d::Touch *>& touches, cocos2d::Event * event);

	//返回player
	Sprite* getPlayer();

	//运行状态
	CC_SYNTHESIZE(bool,m_bGameRun,GameRun);//运行状态 
private:
	void initTouches();//初始化触摸侦听
	void logic(float delta);//主消息循环
	
private:
	bool m_bCanUse;//是否能触摸
	Sprite *m_spriteFish;
	Vector<DEnemy*> m_vecEnemy;
};

#endif