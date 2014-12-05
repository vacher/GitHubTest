#include "FoodLayer.h"
#include "Entity/DFood.h"
#include "Basic/GameConfigures.h"

FoodLayer::FoodLayer()
{

}

FoodLayer::~FoodLayer()
{
	//SpriteFrameCache::getInstance()->removeSpriteFramesFromFile("monster.plist");
}

bool FoodLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	//缓存图片
	//SpriteFrameCache::getInstance()->addSpriteFramesWithFile("monster.plist");

	//加载配置
	loadMonstersFromTmxConf();

	//开启定时器
	this->schedule(schedule_selector(FoodLayer::logic));

	return true;
}

void FoodLayer::logic(float delta)
{
	/* 计时 */
	m_fTimeCounter += delta;

	/* 记录本次出场的怪物 */
	Vector<DFood*> deleteVec;

	/* 让达到出场时间的怪物添加到物理世界 */

	for (auto food : m_foodVec)
	{
		/* 达到时间，可以出场了 */
// 		if (m_fTimeCounter >= monster->getfShowTime())
// 		{
			auto parentNode = this->getParent();
			food->joinToWorld(parentNode);

			/* 记录本次出场的怪物，然后删除掉 */
			deleteVec.pushBack(food);

//		}
	}

	/* 删除已经添加到物理世界的怪物，避免重复出场 */
	for (auto monster : deleteVec)
	{
		m_foodVec.eraseObject(monster, false);
	}
}

void FoodLayer::loadMonstersFromTmxConf()
{
	/* 加载地图 */
	TMXTiledMap * map = TMXTiledMap::create("foodOject.tmx");
	this->addChild(map);

	/* 加载怪物对象层的所有对象 */

	TMXObjectGroup* objGroup = map->getObjectGroup("foodobject");
	ValueVector objects = objGroup->getObjects();

	/* 遍历所有对象 */
	for (const auto v : objects)
	{
		const ValueMap dict = v.asValueMap();
		int id = dict.at("id").asInt();
		//float fShowTime = dict.at("showtime").asFloat();
		int iPosX = dict.at("x").asInt();
		int iPosY = dict.at("y").asInt();


		/* 创建怪物对象，并保存起来 */
		DFood* monster = DFood::create(id);
		monster->setID(id);
		//monster->setfShowTime(fShowTime);
		monster->setiPosX(iPosX);
		monster->setiPosY(iPosY);

		/* 保存怪物对象 */
		m_foodVec.pushBack(monster);
	}
}