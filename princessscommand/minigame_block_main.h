#ifndef DEF_MINIGAME_BLOCK_MAIN_H
#define DEF_MINIGAME_BLOCK_MAIN_H
#include<DxLib.h>
#include"struct.h"
#include"func.h"

enum MINIGAME_BLOCK_SCREENMODE{
	MINIGAME_BLOCK_START,
	MINIGAME_BLOCK_STANDBY,
	MINIGAME_BLOCK_PLAY,
	MINIGAME_BLOCK_PAUSE,
	MINIGAME_BLOCK_GAMEOVER,
};

//int Block_main_Func()
//戻り値: スコアの値
//
int Minigame_Block_Main_Func(
	System_t system_t,
	Option_t option_t,
	Speak_t speak_t,
	Save_t save_t,
	Battle_chara_t battle_chara_t,
	Battle_info_t battle_info_t,
	Menu_t menu_t);

void Minigame_Block_Draw();
void Minigame_Block_Update();

//タイトル画面の処理に使う関数
void Minigame_Block_Start_Draw();
void Minigame_Block_Start_Update();
#endif
