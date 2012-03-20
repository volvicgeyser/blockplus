#include"minigame_block_func.h"
#include"minigame_block_define.h"
#include"minigame_block_enum.h"
#include"minigame_block_keyboard.h"

//ƒ{[ƒ‹‚ª—‚¿‚½‚Ìˆ—
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