//
//  config.h
//
#ifndef  __GLOBALDEFINE_H__
#define  __GLOBALDEFINE_H__

#include <sstream>
using namespace std;

//Sence ID
enum EnSceneId 
{
	SCENE_ID_LOADING,
	SCENE_ID_MENU,
	SCENE_ID_WORLD,
	SCENE_ID_UPWQ,
	SCENE_ID_ABOUT,
	SCENE_ID_OVER,
	SCENE_ID_PASS
};

//设计分辨率
static const float SCREEN_DEFAULT_WIDTH = 320.0;
static const float SCREEN_DEFAULT_HEIGHT = 480.0;

//bannaergao'du
#define BANNAER_HEIHT 50
//hud高度
#define HUDLAYER_HEIHT 50
//定时器时间
#define  GAME_RUNTIME 2.5
//hud
#define  HUD_WIDTH_DELTA 60
#define  HUD_HEIGHT_DELTA 10
//分数加权
#define  MIN_SCORE_UNIT 1
//最大甜点数
#define  MAX_SWEETS_NUM 18
//最大位置
#define MAX_POSITION_NUM 9

//分享/广告/游戏中心定义
//#define  USE_SHARESDK
//#define  USE_COMM_BANNER
//#define  USE_COMM_SCREEN
//#define  USE_GAMECENTER
//#define  USE_GAMESMS

//字符转换
template<typename T>
string Convert2String (const T & value)
{
	stringstream ss ;
	ss << value ;
	return ss .str();
}

//色彩定义
#define ccc4fBlue ccc4f(0.549,0.7412,0.9921,1)
#define ccc4fOrange ccc4f(1,0.6745,0,1)
#define ccc4fRed ccc4f(0.9137,0.3686,0.298,1)
#define ccc4fPurple ccc4f(0.6,0.3765,0.7019,1)
#define ccc4fGreen ccc4f(0.5529,0.9098,0.5803,1)
#define ccc4fYellow ccc4f(0.902,0.851,0.2391,1)

//状态定义
typedef enum 
{
	tooltime = 0,
	toolDisappearAll = 1,
	toolDisappearOne = 2,
}PLAYERTOOLTYPE;

//对象标签
enum tag_LAYER
{
	ObjectTag_Background = 100,
	ObjectTag_Player = 101,
	ObjectTag_Border = 102,
	ObjectTag_Food = 103,
	ObjectTag_FoodLayer = 103,
	ObjectTag_Monster = 104
};

#endif