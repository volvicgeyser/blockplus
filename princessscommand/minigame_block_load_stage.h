#ifndef DEF_MINIGAME_BLOCK_LOAD_STAGE_H
#define DEF_MINIGAME_BLOCK_LOAD_STAGE_H
#include"minigame_block_func.h"

//ステージデータの読み込みを行う

using namespace std;
namespace Minigame{
	namespace Block{
void LoadAllStage(StagesVec &buf, string folderpath);
	}
}
#endif