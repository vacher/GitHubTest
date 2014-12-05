#include "GameManager.h"
#include "Main/GameMenuScene.h"
#include "Main/GameWorldScene.h"

/*³õÊ¼»¯*/
GameManager* GameManager::mManager = NULL;
GameManager* GameManager::getInstance()
{
	if (mManager == NULL)
	{
		mManager = new GameManager();
		mManager->init();
	}
	return mManager;
}

bool GameManager::init() {
	bool bRet = false;

	do {

		//¼ÓÔØÍ¼Æ¬
		loadPictureRes();

		//¼ÓÔØÉùÒô
		loadSoundRes();

		bRet = true;
	} while (0);

	return bRet;
}

void GameManager::loadPictureRes()
{
	//load pic
	auto cache = CCSpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile(LIST_ELEMS, IMG_ELEMS);
	cache->addSpriteFramesWithFile(LIST_SPRITES, IMG_SPRITES);

	//load Asy
	Director::getInstance()->getTextureCache()->addImage(MENU_BG);
	Director::getInstance()->getTextureCache()->addImage(PLAY_BG);
	
}

void GameManager::loadSoundRes()
{//¼ÓÔØÉùÒô
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic(MISC_BG_MP3);
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect(SOUND_CHOMP);
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect(SOUND_ERROR);
}

void GameManager::changeScene(EnSceneId sceneId)
{
	Director* director = Director::getInstance();
	Scene* scene = NULL;
	switch (sceneId)
	{
		case SCENE_ID_LOADING:
		{//ÔØÈë³¡¾°
			//scene = GameLoading::scene();
		}
		break;
		case SCENE_ID_MENU:
		{//²Ëµ¥³¡¾°
			if (director->getRunningScene() == NULL)
			{
				scene = GameMenuScene::createScene();
			}
			else
			{
				scene = CCTransitionSlideInL::create(0.3, GameMenuScene::createScene());
			}
		}
		break;
		case SCENE_ID_WORLD:
		{//
			 scene = CCTransitionSlideInB::create(1, GameWorldScene::createScene());
		}
		break;
		case SCENE_ID_UPWQ:
		{//
			 //scene = CCTransitionSlideInR::create(1, GameUpgradeScene::scene());
		}
		break;
		case SCENE_ID_ABOUT:
		{//
			//scene = GameAboutScene::scene();
		}
		break;
		case SCENE_ID_OVER:
		{
		    //scene = CCTransitionSlideInT::create(1,GameOverScene::scene());
		}
		break;
		case SCENE_ID_PASS:
		{
		}
		break;
	default:
		break;
	}

	if (scene != NULL)
	{
		if (director->getRunningScene() == NULL)
		{
			director->runWithScene(scene);
		}
		else
		{
			director->replaceScene(scene);
		}
	}
}

////////////////////////// play audio ////////////////////////////////////////
void GameManager::pauseAudioMusic()
{
	CocosDenshion::SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

void GameManager::resumeAudioMusic()
{
	CocosDenshion::SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}

void GameManager::stopAudioMusic()
{
	CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();
}

void GameManager::playAudioMusic(const char* filename)
{
	if (!CocosDenshion::SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())
	{
		if (UserDefault::getInstance()->getBoolForKey(KEY_PLAYMUISC, true))
		{
			CocosDenshion::SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(0.3f);
			CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic(filename, true);
		}
	}
}

void GameManager::playAudioSound(const char* filename)
{
	if (UserDefault::getInstance()->getBoolForKey(KEY_PLAYEFFECT, true))
	{
		CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(filename);
	}
}

void GameManager::stopAudioSound()
{
	CocosDenshion::SimpleAudioEngine::getInstance()->stopAllEffects();
}