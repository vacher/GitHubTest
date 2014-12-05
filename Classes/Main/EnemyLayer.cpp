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

	//缓存图片
	//SpriteFrameCache::getInstance()->addSpriteFramesWithFile("monster.plist");

	//创建敌怪逻辑（创建间隔1秒）
	this->schedule(schedule_selector(EnemyLayer::logic), 1);

	return true;
}

void EnemyLayer::logic(float delta)
{
	int randomCount = CCRANDOM_0_1() * 10;//随机本次创建enemy的个数
	for (int i = 0; i < randomCount; i++)
	{
		int random = CCRANDOM_0_1() * 10;
		DEnemy* enemy = nullptr;
		int randomType = CCRANDOM_0_1() * 10;

		//随机怪的贴图
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
		//随机类型
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
	//从vector删除
	m_enemyVec.eraseObject(enemy);
	//从节点删除
	this->getParent()->removeChild(enemy, true);
}