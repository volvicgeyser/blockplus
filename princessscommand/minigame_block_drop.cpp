#include"minigame_block_func.h"

//ボールが落ちた時の処理
namespace Minigame{
	namespace Block{

void Drop_Draw(Gamedata& gameData){
	DrawBlocks(gameData);
	PictureMap g = gameData.graphicData;

	DrawGraph(DROP_X, DROP_Y, g["drop"], TRUE);
}

void Drop_Update(Gamedata& gameData){
	if( IsPressedOK() ){
		gameData.sm = STANDBY;
	}
}





	}
}