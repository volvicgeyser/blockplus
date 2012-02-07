#ifndef DEF_MINIGAME_BLOCK_STRUCT_H
#define DEF_MINIGAME_BLOCK_STRUCT_H
#include<vector>
#include<boost/unordered_map.hpp>
#include"minigame_block_fpscounter.h"
#include"minigame_block_point.h"
#include"minigame_block_interval_visible_obj.h"


//boostのハッシュ関数によるmap
typedef boost::unordered_map<std::string, int> PictureMap;
typedef boost::unordered_map<std::string, Minigame::Block::IntervalVisibleObj> IntervalVisibleObjMap;
namespace Minigame{
	namespace Block{

enum SCREENMODE;
enum GAMEMODE;

typedef struct{
	int count;
	int limit;
	int type;
	Point p;
}LtdDrawableObj;

typedef std::vector<LtdDrawableObj> LtdDrawableObjs;

typedef struct{
	float angle;
	float speed;
}Polar;

typedef struct {
	PointF p;
	Point size;	
	//Polar pl;
	PointF v;
	
	//キャラクターのタイプ（キャラクターごとに使い道が違う）
	int type;

	//キャラクターが生成されたフレーム
	long appearanceFrame;
}CharaObj;

typedef std::vector<CharaObj> CharaObjs;

typedef boost::shared_ptr<CharaObj> CharaObj_Ptr;
typedef std::vector<CharaObj_Ptr> CharaObj_Ptrs;
typedef std::vector<CharaObj_Ptrs> AllCharaObj_Ptrs;


class GameTime{
public:
	double getFPS();
	int getTotalMinutes();
private:
};

typedef struct{
	int currentStage;
	int breakableBlockN;
	int completedStage;
	StagesVec default_stagesVec;
}StageInfo;

typedef struct{
	CharaObjs balls;
	CharaObjs blocks;
	CharaObjs bars;
	CharaObjs items;
	CharaObjs glass_bits;
	CharaObjs block_bits;
	CharaObjs bomb_bits;
	CharaObjs freeze_bits;
}CharaInfo;

typedef struct{
	PictureMap graphicData;
	IntervalVisibleObjMap intervalVisibleObjs;
	FPSCounter fpsCounter;
	StageInfo stageInfo;
	CharaInfo charaInfo;
	SCREENMODE sm;
	GAMEMODE gm;
	LtdDrawableObjs ltdDrawableObjs;
	int score;
	long totalFrameCount;
	int challenge_chance;
}Gamedata;
	}
}
#endif
