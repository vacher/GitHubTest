
#ifndef __ENTITY_SPRITE_H__
#define __ENTITY_SPRITE_H__
#include "cocos2d.h"
USING_NS_CC;

enum EnEntityStat 
{
	STAT_IDLE= 0,
	STAT_USING,
	STAT_RUNNING
};

class EntitySprite : public cocos2d::Sprite
{
public:
    EntitySprite();
    ~EntitySprite();

    bool init(const char * filename,int nType);
    static EntitySprite* create(const char * filename,int nType);
	bool initWithTexture(Texture2D *pTexture,int nType);
	static EntitySprite* createWithTexture(Texture2D *pTexture,int nType);
	bool initWithFrame(SpriteFrame *pFrame,int nType);
	static EntitySprite* createWithFrame(SpriteFrame *pFrame,int nType);
   
	CC_SYNTHESIZE(EnEntityStat,m_nEntityStat,EntityStat);
	CC_SYNTHESIZE(int,m_nEntityType,EntityType);
	CC_SYNTHESIZE(Sprite*,m_pHLSprite,HLSprite);

	bool moveToPostion(const Vec2& position);
	void runAnimation(int nType);
	
	//执行效果动画
	void runEffectAnimate();
	void restart();

private:
	Sprite *m_pEffectSprite;

};


#endif /* defined(__ENTITY_SPRITE_H__) */
