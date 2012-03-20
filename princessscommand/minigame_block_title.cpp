#include"minigame_block_func.h"
#include"minigame_block_keyboard.h"
#include"minigame_block_enum.h"
#include"minigame_block_define.h"
#include"minigame_block_debug.h"

namespace Minigame{
	namespace Block{
//�^�C�g����ʂ̓���
void Title_Update(Gamedata &gameData){

	//�S�Ẵ{�[���̈ړ�����
	MoveAllBalls(gameData);

	UpdateBombBits(gameData);
	UpdateBlockBits(gameData);
	gameData.intervalVisibleObjs["title_logo"].Update();
	CharaObjs& blocks = gameData.charaInfo.blocks;

	//�G���^�[�L�[�������ꂽ�玟�̃V�[����
	if( IsPressedOK() ){
		gameData.sm = STANDBY;
		gameData.charaInfo.bomb_bits.clear();
		GoNextStage(gameData);
	}

	//�u���b�N���O�ɂȂ�΃X�e�[�W���������i�u���b�N�����ɖ߂�)����
	if(blocks.size() == 0){
		InitBlocks(gameData);
	}
	
}

void Title_Draw(Gamedata &gameData){
	DrawBlocks(gameData);
	DrawAllBalls(gameData);
	DrawBombBits(gameData);
	DrawBlockBits(gameData);
	PictureMap& g = gameData.graphicData;
	switch(gameData.gm){
		case RANKINGMODE:
			break;
		case RETRYMODE:
			break;
	}
	if(DrawGraph(TITLE_X, TITLE_Y, g[TITLE_STR], TRUE) == -1){
		pd(CANT_DRAW_GRAPHIC_STR);
	}
	
	//if( DrawGraph(RANKINGMODE_X, RANKINGMODE_Y, g["rankingmode"], TRUE) ){
	//}
	//if( DrawGraph(RETRYMODE_X, RETRYMODE_Y, g["retrymode"], TRUE) ){
	//}

	if( DrawGraph(TITLE_PLUS_X, TITLE_PLUS_Y, g[PLUS_STR], TRUE)){}
	if( DrawGraph(VERSION_X, VERSION_Y, g[VERSION_STR], TRUE) ){
	}
	if(gameData.intervalVisibleObjs["title_logo"].Visible()){
		if(DrawGraph(PRESS_ENTER_KEY_X, PRESS_ENTER_KEY_Y, g[PRESS_ENTER_KEY_STR], TRUE) == -1){
		}
		
	}
	const char* message = "���̃Q�[���͖{�҂ɂ��Ă���\��̐���r���̃~�j�Q�[���ł��BEnter�L�[ or Space�L�[ or �}�E�X�N���b�N�� \
��ɐi�ނ��Ƃ��ł��܂��B����: �Ђł܂���D�搶";
	DrawString( (200 + SCREEN_SIZE_HEIGHT - gameData.totalFrameCount % 800 * 3), 500, message, GetColor(255,255,255));
}


	}
}