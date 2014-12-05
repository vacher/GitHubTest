#include "EnemyLayer.h"
#include "Entity/DEnemy.h"
#include "Basic/GameConfigures.h"

EnemyLayer::EnemyLayer()
{

}

EnemyLayer::~EnemyLayer()
{
	//SpriteFrameCache::getInstance()->removeSpriteFramesFromFile("monster.plist");
}

bool EnemyLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	//����ͼƬ
	//SpriteFrameCache::getInstance()->addSpriteFramesWithFile("monster.plist");

	//�����й��߼����������1�룩
	this->schedule(schedule_selector(EnemyLayer::logic), 1);

	return true;
}

void EnemyLayer::logic(float delta)
{
	int randomCount = CCRANDOM_0_1() * 10;//������δ���enemy�ĸ���
	for (int i = 0; i < randomCount; i++)
	{
		int random = CCRANDOM_0_1() * 10;
		DEnemy* enemy = nullptr;
		int randomType = CCRANDOM_0_1() * 10;

		//����ֵ���ͼ
		const char* name;
		if (random >= 0 && random <= 2)
		{
			name = "enemy_bug.png";
		}
		else if (random >= 3 && random <= 6)
		{
			name = "enemy_duck.png";
		}
		else if (random >= 7 && random <= 10){
			name = "enemy_pig.png";
		}
		//�������
		if (randomType % 2 == 0)
		{
			randomType = 0;
		}
		else
		{
			randomType = 1;
		}
		enemy = DEnemy::createEnemy(name, randomType);
		m_enemyVec.pushBack(enemy);
		
		auto node = this->getParent();
		node->addChild(enemy);
	}
}

void EnemyLayer::removeEnemy(DEnemy *enemy)
{
	//��vectorɾ��
	m_enemyVec.eraseObject(enemy);
	//�ӽڵ�ɾ��
	this->getParent()->removeChild(enemy, true);
}