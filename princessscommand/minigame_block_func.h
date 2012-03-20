#ifndef DEF_MINIGAME_BLOCK_FUNC_H
#define DEF_MINIGAME_BLOCK_FUNC_H

//ゲームの動作に関する関数やインクルード

//必要最低限のものだけインクルード
#define WIN32_LEAN_AND_MEAN 

#include<DxLib.h>
#include<tchar.h>
#include<map>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
#include<numeric>
#include<functional>
#include<fstream>
#include<stdexcept>
#include"func.h"
#include<windows.h>
#include"minigame_block_math_helper.h"
#include"minigame_block_typedef.h"
#include"minigame_block_struct.h"
#include"minigame_block_define.h"
#include"minigame_block_fpscounter.h"
#include"minigame_block_load_stage.h"
#include"minigame_block_keyboard.h"
#include"minigame_block_point.h"
#include"minigame_block_line.h"
#include"minigame_block_enum.h"
#include<iostream>
#include<shlwapi.h>
#include<boost/shared_ptr.hpp>
#include<boost/bind.hpp>
#include<boost/unordered_map.hpp>
#include<boost/ref.hpp>
#include<boost/function.hpp>
#include<boost/cast.hpp>
#include<boost/range/algorithm/for_each.hpp>
#include<boost/lexical_cast.hpp>
#include "minigame_block_debug.h"
#pragma comment(lib, "shlwapi.lib")

namespace Minigame{
	namespace Block{

enum DIRECTION8;

int Main_Func(
	System_t *system_t,
	Option_t *option_t,
	Speak_t *speak_t,
	Save_t *save_t,
	Battle_chara_t *battle_chara_t,
	Battle_info_t *battle_info_t,
	Menu_t *menu_t);

//衝突チェック
bool IsCrashed(int x1, int y1, int x2, int y2, int size);
bool IsCrashed(CharaObj &c1, CharaObj &c2);
bool IsCrashed(CharaObj &c1, CharaObj &c2, float cs1, float cs2);
bool IsCrashed(float x1, float y1, float x2, float y2, float size);
bool IsCrashed(float x1, float y1, float x2, float y2, int size);
bool IsCrashed(float x1, float y1, float x2, float y2, int s1, int s2);
bool IsCrashed(float x1, float y1, float x2, float y2, float xs1, float ys1, float xs2, float ys2);
bool IsCrashedOn1D(float x1, float x2, float xs1, float xs2);


bool IsCrashedVerticalWall(float x, float dx, int objSize);
bool IsCrashedHorizontalWall(float y, float dy, int objSize);

float ToChangeDegree0To360(float deg);
void ConvertPolarToCartesian(PointF& buf, Polar& pl);
void ConvertCartesianToPolar(Polar& buf, PointF& p);

void AngleReflect(CharaObj &c1, CharaObj &c2, float cxs1, float cxs2, float cys1, float cys2);
void AngleReflect(CharaObj &c1, CharaObj &c2, float cs1, float cs2);

float GetAngleFromTwoPointF(PointF& start, PointF& end);
float AngleReflectX(float angle);
float AngleReflectY(float angle);

void GetVirutalPos(PointF& p, const CharaObj& c1);

DIRECTION8 ConvertDegreeToDirection8(float angle);
DIRECTION8 ConvertDegreeToDireciton4(float angle);
DIRECTION8 ReverceDirection8(DIRECTION8 d);

float GetAngleFromTwoPointF(const PointF& start, const PointF& end);
void GetCharaCenter(PointF& buf, const PointF& p, float size);

void GoNextStage(Gamedata &gameData);
void Title_Draw(Gamedata &gameData);
void Title_Update(Gamedata &gameData);

//readyと表示されているボール発射前の画面
void Standby_Draw(Gamedata& gameData);
void Standby_Update(Gamedata& gameData);
void UpdateReadyLogo(Gamedata& gameData);

void Draw_Playing(Gamedata& gameData);
void Update_Playing(Gamedata& gameData);

void Drop_Draw(Gamedata& gameData);
void Drop_Update(Gamedata& gameData);

void Draw_StageClear(Gamedata &gameData);
void Update_StageClear(Gamedata &gameData);

void Draw_Gameover(Gamedata& gameData);
void Update_Gameover(Gamedata& gameData);

void Draw_Ending(Gamedata& gameData);
void Update_Ending(Gamedata& gameData);

void Init(Gamedata &gameData);


//ステージの初期化
void InitStage(Gamedata &gameData);

//ゲームデータの初期化
void InitGameData(Gamedata &gameData);

void DrawBlocks(Gamedata &gameData);
void InitBlocks(Gamedata &gamedata);
void InitCharaInfo(Gamedata &gamedata);
void InitBar(Gamedata& gameData);
void ResetAllCharaObj(Gamedata &gameData);
void DrawBars(Gamedata& gameData);
void UpdateBars(Gamedata& gameData);

void DrawBombBit(CharaObj& c, PictureMap& g);
void DrawBombBits(Gamedata &gameData);
void UpdateBombBit(CharaObj& c);
void UpdateBombBits(Gamedata& gameData);
void MakeFirstBall(CharaObj& c);
void MoveAllBalls(Gamedata& gameData);
void DrawAllBalls(Gamedata &gameData);

void DrawChallengeChange(Gamedata& gameData);

void BreakBlock(Gamedata& gameData);

void DrawBlockBit(CharaObj& c, PictureMap& g);
void UpdateBlockBit(CharaObj& c);
void DrawBlockBits(Gamedata& gameData);
void UpdateBlockBits(Gamedata& gameData);

void EffectBlock(CharaObj& block, Gamedata& gameData);
float ReflectFromDirection(float angle, DIRECTION8 d);

void MakeItem(CharaObj& block, Gamedata& gameData);
void DrawItem(CharaObj& c, PictureMap& g);
void UpdateItem(CharaObj& c);
void DrawItems(Gamedata& gameData);
void UpdateItems(Gamedata& gameData);

//氷ブロックから出てきたビットを描画
void DrawFreezeBit(CharaObj& c, PictureMap& g);

bool IsDropObj(CharaObj& c, int size);

void CreateVirtualPos(PointF& buf, CharaObj& c);


//スコアの描画
void DrawScore(Gamedata& gameData);
	}
}

#endif