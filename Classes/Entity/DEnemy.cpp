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

//��ʼ��
void DEnemy::enemyInit(const char* fileName,int _type)
{
	m_nType = _type;

	//��������
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

	//X����Ļ�����λ��
	this->setPosition(Point(CCRANDOM_0_1()*size.width,size.height+this->getContentSize().height));
	
	//�ƶ��߼�
	this->scheduleUpdate();
}

//���ֲ�ͬ���ƶ��߼�
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
			  //�жϷ�ֹ�ظ����ô˶�������֤���߼�ֻ��ִ��һ��
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

	//ɾ��
// 	if (this->getPositionY() < -this->getContentSize().height)
// 	{
// 		//ɾ��
// 		sLayer->removeEnemy(this);
// 	}

	auto player = sLayer->getPlayer();
	if (player->getBoundingBox().intersectsRect(this->getBoundingBox()))
	{
		//sLayer->overGame();
	}
}
//�õй��ж�̬��Ч��
void DEnemy::createAnimate(const char* fileName,int allCount)
{
	auto animation = CCAnimation::create();
	auto texture = Director::getInstance()->getTextureCache()->addImage(fileName);
	int eachWidth=this->getContentSize().width/allCount;//ÿ����Ƭ�Ŀ�
	for (int i =0; i<allCount; i++) 
	{
		animation->addSpriteFrameWithTexture(texture, Rect(i*eachWidth, 0, eachWidth, this->getContentSize().height));
	}
	animation->setDelayPerUnit(0.03f);//�������÷��򲻻ᶯ̬����
	animation->setRestoreOriginalFrame(true);//�Ƿ�ص���һ֡
	animation->setLoops(-1);//�ظ����� ��-1:����ѭ����
	auto animate = CCAnimate::create(animation);
	this->runAction(animate);

}

