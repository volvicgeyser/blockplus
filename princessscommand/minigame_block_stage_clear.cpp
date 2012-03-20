#include"minigame_block_func.h"

namespace Minigame{
	namespace Block{

//ステージクリアの画面を表示
void Draw_StageClear(Gamedata& gameData){
	PictureMap& g = gameData.graphicData;
	DrawBlocks(gameData);
	DrawAllBalls(gameData);
	DrawBombBits(gameData);
	DrawBars(gameData);
	if(gameData.intervalVisibleObjs["stage_clear_logo"].Visible()){
		if(DrawGraph(READY_X, READY_Y, g["stage_clear"], TRUE) == -1){

		}
	}
	//DrawGraph(STAGE_CLEAR_X, STAGE_CLEAR_Y, g["stage_clear"], TRUE);
}

void Update_StageClear(Gamedata& gameData){
	gameData.intervalVisibleObjs["stage_clear_logo"].Update();
	if( IsPressedOK() ){
		GoNextStage(gameData);
	}
}







	}
}