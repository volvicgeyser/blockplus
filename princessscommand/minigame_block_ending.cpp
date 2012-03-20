#include"minigame_block_func.h"


//Endingの描画

namespace Minigame{
	namespace Block{
	
		void Draw_Ending(Gamedata& gameData){
			DWORD color = GetColor(255,255,255);
			DrawString(10, 10, "短い間でしたが、ありがとうございます！", color);
			DrawString(10, 30, "画像制作:　D先生", color);
			DrawString(10, 60, "プログラム：　D先生", color);
			DrawFormatString(10, 90, color, "スコア: %d", gameData.score, color);
		}
		void Update_Ending(Gamedata& gameData){
			if( IsPressedOK() ){
				gameData.stageInfo.currentStage = 0;
				
				InitCharaInfo(gameData);
				InitBlocks(gameData);
				gameData.sm = TITLE;
			}
		}

	
	}
}