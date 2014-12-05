#include "DFood.h"
#include "Basic/GameConfigures.h"
#include "Basic/GameResouces.h"
#include "Json/json.h"
#include "Main/GamePlayLayer.h"

DFood::DFood()
{
	
}

DFood::~DFood()
{

}

DFood* DFood::create(int ID)
{
	auto monster = new DFood();
	if (monster && monster->init(ID))
	{
		monster->autorelease();
	}
	else
	{
		CC_SAFE_DELETE(monster);
	}
	return monster;
}

bool DFood::init(int ID)
{

	bool bRet = false;
	do{
		CC_BREAK_IF(!Node::init());

		//1 保存值
		this->m_ID = ID;

		//2 读配置
		readJsonValue("foodconf.plist");

		//3 主逻辑
		this->scheduleUpdate();

		bRet = true;
	} while (0);
	
	return bRet;
}

void DFood::setActive(bool bAct)
{
	if (bAct)
	{
		m_bActived = true;
		this->setVisible(true);
	}
	else
	{
		m_bActived = false;
		this->setVisible(false);
	}
}

bool DFood::isActived()
{
	return m_bActived;
}

/*************************** ******************************/
void DFood::readJsonValue(const char *filename)
{
	/* ----------- 读取怪物配置文件 ------------ */
	/* 读取配置文件字符串数据 */
	std::string sData = FileUtils::getInstance()->getStringFromFile(filename);

	/* 用于解析Json */
	Json::Reader reader;

	/* 解析Json后的根节点 */
	Json::Value root;

	/* 开始解析 */
	if (!reader.parse(sData, root, false))
	{
		log("解析Json失败");
		return;
	}

	/* 在这里，根节点是一个数组，遍历数组，找到我们要的ID */
	int size = root.size();
	for (int i = 0; i < size; ++i)
	{
		int id = root[i]["id"].asInt();
		if (id == m_ID)
		{
			m_sModelPath = root[i]["model"].asCString();
			break;
		}
	}

	//设置分数/test
	m_iValueScore = 5;
}

void DFood::joinToWorld(Node* parent)
{
	m_spEnity = Sprite::createWithSpriteFrameName(m_sModelPath.asString().c_str());
	
	/* 精灵居中 */
	m_spEnity->setPosition(Point(m_spEnity->getContentSize().width * 0.5f, m_spEnity->getContentSize().height * 0.5f));

	/* 精灵作为Monster的表现，添加到Monster身上 */
	this->addChild(m_spEnity);

	/* 设置Tag类型 */
	this->setTag(ObjectTag_Food);

	/* 精灵作为food的表现，Monster本身没有大小，所以要设置一下大小 */
	this->setContentSize(m_spEnity->getContentSize());

	/* 设置坐标 */
	this->setPosition(Point(getiPosX(), getiPosY()));

	/* Monster加入到物理世界 */
	parent->addChild(this);
	setActive(true);

}

void DFood::update(float time)
{
	bool bGameRun = UserDefault::getInstance()->getBoolForKey(KEY_GAMERUNNING,false);
	if (!bGameRun)
	{//游戏未运行
		log("DFood game not run");
		return;
	}

	if (!isActived())
	{//未激活
		return;
	}
	
	GamePlayLayer * sLayer = (GamePlayLayer*)getParent();
	auto player = sLayer->getPlayer();
	if (player->getBoundingBox().intersectsRect(this->getBoundingBox()))
	{
		foodBeEat();
	}
}

void DFood::foodBeEat()
{
	//播放声音

	//加分
	GamePlayLayer * sLayer = (GamePlayLayer*)getParent(); 
	sLayer->addScore(m_iValueScore,this->getPosition());

	//取消激活
	this->setActive(false);
}