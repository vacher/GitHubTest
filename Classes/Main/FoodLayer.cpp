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

	//����ͼƬ
	//SpriteFrameCache::getInstance()->addSpriteFramesWithFile("monster.plist");

	//��������
	loadMonstersFromTmxConf();

	//������ʱ��
	this->schedule(schedule_selector(FoodLayer::logic));

	return true;
}

void FoodLayer::logic(float delta)
{
	/* ��ʱ */
	m_fTimeCounter += delta;

	/* ��¼���γ����Ĺ��� */
	Vector<DFood*> deleteVec;

	/* �ôﵽ����ʱ��Ĺ�����ӵ��������� */

	for (auto food : m_foodVec)
	{
		/* �ﵽʱ�䣬���Գ����� */
// 		if (m_fTimeCounter >= monster->getfShowTime())
// 		{
			auto parentNode = this->getParent();
			food->joinToWorld(parentNode);

			/* ��¼���γ����Ĺ��Ȼ��ɾ���� */
			deleteVec.pushBack(food);

//		}
	}

	/* ɾ���Ѿ���ӵ���������Ĺ�������ظ����� */
	for (auto monster : deleteVec)
	{
		m_foodVec.eraseObject(monster, false);
	}
}

void FoodLayer::loadMonstersFromTmxConf()
{
	/* ���ص�ͼ */
	TMXTiledMap * map = TMXTiledMap::create("foodOject.tmx");
	this->addChild(map);

	/* ���ع�����������ж��� */

	TMXObjectGroup* objGroup = map->getObjectGroup("foodobject");
	ValueVector objects = objGroup->getObjects();

	/* �������ж��� */
	for (const auto v : objects)
	{
		const ValueMap dict = v.asValueMap();
		int id = dict.at("id").asInt();
		//float fShowTime = dict.at("showtime").asFloat();
		int iPosX = dict.at("x").asInt();
		int iPosY = dict.at("y").asInt();


		/* ����������󣬲��������� */
		DFood* monster = DFood::create(id);
		monster->setID(id);
		//monster->setfShowTime(fShowTime);
		monster->setiPosX(iPosX);
		monster->setiPosY(iPosY);

		/* ���������� */
		m_foodVec.pushBack(monster);
	}
}