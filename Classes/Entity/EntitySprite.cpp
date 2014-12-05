#include "EntitySprite.h"

EntitySprite::EntitySprite()
{
    m_pHLSprite   = NULL;
	m_nEntityStat = STAT_IDLE;
	m_nEntityType = 0;
		
}

EntitySprite::~EntitySprite()
{
    
}

EntitySprite* EntitySprite::create(const char * filename,int nType)
{
    EntitySprite *pRet = new EntitySprite();
    if (pRet && pRet->init(filename,nType))
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        delete pRet;
        pRet = NULL;
        return NULL;
    }
}

EntitySprite* EntitySprite::createWithTexture(Texture2D *pTexture,int nType)
{
	EntitySprite *pRet = new EntitySprite();
	if (pRet && pRet->initWithTexture(pTexture,nType))
	{
		pRet->autorelease();
		return pRet;
	}
	else
	{
		delete pRet;
		pRet = NULL;
		return NULL;
	}
}

EntitySprite* EntitySprite::createWithFrame(SpriteFrame *pFrame,int nType)
{
	EntitySprite *pRet = new EntitySprite();
	if (pRet && pRet->initWithFrame(pFrame,nType))
	{
		pRet->autorelease();
		return pRet;
	}
	else
	{
		delete pRet;
		pRet = NULL;
		return NULL;
	}
}

bool EntitySprite::init(const char * filename,int nType)
{
	initWithFile(filename);
	m_nEntityType = nType;

    return true;
}

bool EntitySprite::initWithTexture(Texture2D *pTexture,int nType)
{
	CCSprite::initWithTexture(pTexture);
	m_nEntityType = nType;

// 	m_pEffectSprite = CCSprite::create("s1.png");
// 	m_pEffectSprite->setPosition(ccp(70,150));
// 	this->addChild(m_pEffectSprite);
// 	m_pEffectSprite->setVisible(false);

	return true;
}

bool EntitySprite::initWithFrame(SpriteFrame *pFrame,int nType)
{
	CCSprite::initWithSpriteFrame(pFrame);
	m_nEntityType = nType;

// 	m_pEffectSprite = CCSprite::create("s1.png");
// 	m_pEffectSprite->setPosition(ccp(70,150));
// 	this->addChild(m_pEffectSprite);
// 	m_pEffectSprite->setVisible(false);

	return true;
}


bool EntitySprite::moveToPostion(const Vec2& position)
{
    auto* mt = MoveTo::create(0.2, position);
    this->runAction(mt);
    //deGameManager->playAudioSound(SOUND_LOADING);
    return true;
}

void EntitySprite::runAnimation(int nType)
{
	this->stopAllActions();

	auto delay = DelayTime::create(1.0);
	auto moveUp = MoveBy::create(0.2, Point(0, 15));
	auto moveDown = MoveBy::create(0.2, Point(0, -15));
	auto pAct = Sequence::create(delay, moveUp, moveDown, NULL);

	this->runAction(CCRepeatForever::create(pAct));
}

void EntitySprite::runEffectAnimate()
{
// 	m_pEffectSprite->setVisible(true);
// 	this->stopAllActions();
// 
// 	auto boomAnimation = Animation::create();
// 	for (int i = 0; i < 18; i++)
// 	{
// 		CCString *str = CCString::createWithFormat("s%d.png",i+1);
// 		boomAnimation->addSpriteFrameWithFileName(str->getCString());
// 	}
// 	boomAnimation->setDelayPerUnit(0.1f);
// 	boomAnimation->setRestoreOriginalFrame(true);
// 
// 	m_pEffectSprite->runAction(CCSequence::create(CCAnimate::create(boomAnimation),
// 		CCCallFunc::create(this, callfunc_selector(EntitySprite::restart)),
// 		NULL));
}

void EntitySprite::restart()
{
	m_pEffectSprite->setVisible(false);
}