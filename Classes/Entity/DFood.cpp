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

		//1 ����ֵ
		this->m_ID = ID;

		//2 ������
		readJsonValue("foodconf.plist");

		//3 ���߼�
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
	/* ----------- ��ȡ���������ļ� ------------ */
	/* ��ȡ�����ļ��ַ������� */
	std::string sData = FileUtils::getInstance()->getStringFromFile(filename);

	/* ���ڽ���Json */
	Json::Reader reader;

	/* ����Json��ĸ��ڵ� */
	Json::Value root;

	/* ��ʼ���� */
	if (!reader.parse(sData, root, false))
	{
		log("����Jsonʧ��");
		return;
	}

	/* ��������ڵ���һ�����飬�������飬�ҵ�����Ҫ��ID */
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

	//���÷���/test
	m_iValueScore = 5;
}

void DFood::joinToWorld(Node* parent)
{
	m_spEnity = Sprite::createWithSpriteFrameName(m_sModelPath.asString().c_str());
	
	/* ������� */
	m_spEnity->setPosition(Point(m_spEnity->getContentSize().width * 0.5f, m_spEnity->getContentSize().height * 0.5f));

	/* ������ΪMonster�ı��֣���ӵ�Monster���� */
	this->addChild(m_spEnity);

	/* ����Tag���� */
	this->setTag(ObjectTag_Food);

	/* ������Ϊfood�ı��֣�Monster����û�д�С������Ҫ����һ�´�С */
	this->setContentSize(m_spEnity->getContentSize());

	/* �������� */
	this->setPosition(Point(getiPosX(), getiPosY()));

	/* Monster���뵽�������� */
	parent->addChild(this);
	setActive(true);

}

void DFood::update(float time)
{
	bool bGameRun = UserDefault::getInstance()->getBoolForKey(KEY_GAMERUNNING,false);
	if (!bGameRun)
	{//��Ϸδ����
		log("DFood game not run");
		return;
	}

	if (!isActived())
	{//δ����
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
	//��������

	//�ӷ�
	GamePlayLayer * sLayer = (GamePlayLayer*)getParent(); 
	sLayer->addScore(m_iValueScore,this->getPosition());

	//ȡ������
	this->setActive(false);
}