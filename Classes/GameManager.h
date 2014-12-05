//��Ϸ������
/*
1 ��������
2 ���ֹ���
3 ��Դ����
*/
#ifndef __GAME_MANAGER_H__
#define __GAME_MANAGER_H__
#include "cocos2d.h"
#include "SimpleAudioEngine.h"

#include "Basic/GameConfigures.h"	
#include "Basic/GameResouces.h"

using namespace cocos2d;
using namespace CocosDenshion;

#define deGameManager GameManager::getInstance()

class GameManager
{
public:
	virtual bool init();
	static GameManager* getInstance();

	//������
	void changeScene(EnSceneId sceneID);

	//��������
	void playAudioMusic(const char* filename);
	void stopAudioMusic();
	void playAudioSound(const char* filename);
	void stopAudioSound();
	void pauseAudioMusic();
	void resumeAudioMusic();

private:
	void loadSoundRes();
	void loadPictureRes();

private:
	static GameManager* mManager;
};

#endif