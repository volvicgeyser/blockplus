#ifndef DEF_MINIGAME_BLOCK_STRUCT_H
#define DEF_MINIGAME_BLOCK_STRUCT_H
#include<vector>
#include<boost/unordered_map.hpp>
#include"minigame_block_fpscounter.h"
#include"minigame_block_point.h"
#include"minigame_block_interval_visible_obj.h"

//構造体
//boostのハッシュ関数によるmap
typedef boost::unordered_map<std::string, int> PictureMap;
typedef boost::unordered_map<std::string, Minigame::Block::IntervalVisibleObj> IntervalVisibleObjMap;

namespace Minigame{
	namespace Block{

enum SCREENMODE;
enum GAMEMODE;

//寿命尽きメッセージ等のオブジェクト
struct LtdDrawableObj{
	//寿命フレームカウント
	int count;
	
	//寿命フレーム	
	int limit;

	int type;

	//表示位置
	Point p;
};

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

//スマートポインタのtypedef
typedef std::vector<CharaObj> CharaObjs;
typedef boost::shared_ptr<CharaObj> CharaObj_Ptr;
typedef std::vector<CharaObj_Ptr> CharaObj_Ptrs;
typedef std::vector<CharaObj_Ptrs> AllCharaObj_Ptrs;

//Gameの時間に関する情報を保持するクラス
class GameTime{
public:
	//FPSを取得する
	double getFPS();

	//ゲームが起動してからのトータル時間を取得する
	int getTotalMinutes();
private:
};

//ゲームのステージ情報を保持する構造体
struct StageInfo{
	//現在のステージ
	int currentStage;

	//現在のステージで破壊可能なブロックの数
	int breakableBlockN;

	//過去に、最初のステージから開始し、どこまでのステージまでいけたか
	int completedStage;

	//ロードされたステージ情報
	StagesVec default_stagesVec;
};

//バー、ブロック、アイテム、ボールなどをキャラクターオブジェクトを保持する構造体
struct CharaInfo{
	CharaObjs balls;
	CharaObjs blocks;
	CharaObjs bars;
	CharaObjs items;

	//ガラス片
	CharaObjs glass_bits;

	//ブロック片
	CharaObjs block_bits;

	//爆弾ブロックから飛び出す破片
	CharaObjs bomb_bits;
	CharaObjs freeze_bits;
};

typedef struct{
	//全ての画像データを保持する連想配列
	PictureMap graphicData;

	//消えたり現れたりするメッセージ等のオブジェクト
	IntervalVisibleObjMap intervalVisibleObjs;
	
	//FPSに関する情報
	FPSCounter fpsCounter;

	//ステージの情報
	StageInfo stageInfo;
	
	//全てのキャラクター情報
	CharaInfo charaInfo;

	//ブロック崩しのゲームの流れ
	SCREENMODE sm;

	//タイトル画面で選べるゲームモード
	GAMEMODE gm;

	//寿命付きメッセージ表示オブジェクト
	LtdDrawableObjs ltdDrawableObjs;

	//ステージのスコア
	int score;

	//トータルスコア
	long totalFrameCount;

	//チャレンジモードは何度も復帰できるの不要？　仕様が固まり次第
	//int challenge_chance;
}Gamedata;
	}
}
#endif
