#include"minigame_block_func.h"


//Ending�̕`��

namespace Minigame{
	namespace Block{
	
		void Draw_Ending(Gamedata& gameData){
			DWORD color = GetColor(255,255,255);
			DrawString(10, 10, "�Z���Ԃł������A���肪�Ƃ��������܂��I", color);
			DrawString(10, 30, "�摜����:�@D�搶", color);
			DrawString(10, 60, "�v���O�����F�@D�搶", color);
			DrawFormatString(10, 90, color, "�X�R�A: %d", gameData.score, color);
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