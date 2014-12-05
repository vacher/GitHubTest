#include "DEnemy.h"
#include "Main/GamePlayLayer.h"

DEnemy::DEnemy(void)
{
	m_isActed = false;
	m_nType   = -1;
}


DEnemy::~DEnemy(void)
{
}

DEnemy* DEnemy::createEnemy(const char* fileName,int _type)
{
	DEnemy* enemy = new DEnemy();
	if(enemy && enemy->initWithFile(fileName))
	{
		enemy->autorelease();
		enemy->enemyInit(fileName,_type);
		return enemy;
	}
	CC_SAFE_DELETE(enemy);
	return NULL;
}

//初始化
void DEnemy::enemyInit(const char* fileName,int _type)
{
	m_nType = _type;

	//创建动画
	createAnimate(fileName, 10);

	Size size = Director::getInstance()->getWinSize();
	if(_type==0)
	{
		m_nScoreValue=198;
	}else if(_type==1)
	{
		m_nScoreValue=428;
	}else if(_type ==2)
	{
		m_nScoreValue=908;
	}

	//X在屏幕内随机位置
	this->setPosition(Point(CCRANDOM_0_1()*size.width,size.height+this->getContentSize().height));
	
	//移动逻辑
	this->scheduleUpdate();
}

//三种不同的移动逻辑
void DEnemy::update(float time)
{
	GamePlayLayer * sLayer = (GamePlayLayer*)getParent();
	switch (m_nType)
	{
	case 0:
	{
			  this->setPosition(this->getPosition() + Point(0, -3));
	}
		break;
	case 1:
	{
			  //判断防止重复调用此动作，保证此逻辑只会执行一次
			  if (m_isActed)
			  {
				  break;
			  }
			  m_isActed = true;

			  this->runAction(Sequence::create(MoveTo::create(2.0, sLayer->getPlayer()->getPosition() + Point(-20, 0)),
				  DelayTime::create(0.5),
				  MoveTo::create(0.8, this->getPosition()), NULL));

	}
		break;
	case 2:
	{
			  if (m_isActed)
			  {
				  break;
			  }
			  m_isActed = true;
			  this->runAction(CCSequence::create(CCMoveTo::create(1.2, sLayer->getPlayer()->getPosition() + Point(0, 20)),
				  CCDelayTime::create(1),
				  CCMoveTo::create(0.8, this->getPosition()), NULL));
	}
		break;
	}

	//删除
// 	if (this->getPositionY() < -this->getContentSize().height)
// 	{
// 		//删除
// 		sLayer->removeEnemy(this);
// 	}

	auto player = sLayer->getPlayer();
	if (player->getBoundingBox().intersectsRect(this->getBoundingBox()))
	{
		//sLayer->overGame();
	}
}
//让敌怪有动态的效果
void DEnemy::createAnimate(const char* fileName,int allCount)
{
	auto animation = CCAnimation::create();
	auto texture = Director::getInstance()->getTextureCache()->addImage(fileName);
	int eachWidth=this->getContentSize().width/allCount;//每个切片的宽
	for (int i =0; i<allCount; i++) 
	{
		animation->addSpriteFrameWithTexture(texture, Rect(i*eachWidth, 0, eachWidth, this->getContentSize().height));
	}
	animation->setDelayPerUnit(0.03f);//必须设置否则不会动态播放
	animation->setRestoreOriginalFrame(true);//是否回到第一帧
	animation->setLoops(-1);//重复次数 （-1:无限循环）
	auto animate = CCAnimate::create(animation);
	this->runAction(animate);

}

