#include"minigame_block_func.h"
#include"minigame_block_math_helper.h"
#include"minigame_block_define.h"
#include"minigame_block_enum.h"
namespace Minigame{
	namespace Block{

//�{�[���̈ړ��֐�
	


//�߂��߂�
//�{�[���̈ړ�
//�E�ǂɂ�����
//�E�u���b�N�ɓ�����
//



//�{�[�������������
//�E���ɗ�����
//
//

		
//�u���b�N�����������
//�EUNBREAKABLE�ȊO�̃u���b�N�ɂԂ�������
//
//

//�u���b�N�̍폜�Ɏg���֐�(*���g�p)
//���q�֐�
bool BlockDeleter(CharaObj& block, const PointF virtualP, const PointF ball){
			const bool isCrashedLR = IsCrashed(virtualP.x(), ball.y(), block.p.x(), block.p.y(), BALL_SIZE, BALL_SIZE, BLOCK_SIZE, BLOCK_SIZE);
			const bool isCrashedUD = IsCrashed(ball.x(), virtualP.y(), block.p.x(), block.p.y(), BALL_SIZE, BALL_SIZE, BLOCK_SIZE, BLOCK_SIZE);
			const bool isCrashed_flag = isCrashedLR || isCrashedUD;
			return isCrashed_flag;
}


void MoveAllBalls(Gamedata &gameData){
	CharaObjs &balls = gameData.charaInfo.balls;
	CharaObjs &blocks = gameData.charaInfo.blocks;
	CharaObjs &bars = gameData.charaInfo.bars;
	CharaObjs &bomb_bits = gameData.charaInfo.bomb_bits;
	CharaObjs &freeze_bits = gameData.charaInfo.freeze_bits;

	for(int i = 0; i < boost::numeric_cast<int>(balls.size()); i++){
		//CharaObj& ball = balls[i];
		const PointF virtualP = balls[i].v + balls[i].p;
		const bool IsCrashedVW_flag = IsCrashedVerticalWall(balls[i].p.x(), balls[i].v.x(), BALL_SIZE);
		const bool IsCrashedHW_flag = IsCrashedHorizontalWall(balls[i].p.y(), balls[i].v.y(), BALL_SIZE);
		bool block_delete_flag = false;
		bool ball_delete_flag = false;

		if(IsCrashedVW_flag){
			balls[i].v.x( balls[i].v.x() * -1.0f);
		}
		if(IsCrashedHW_flag){
			if(virtualP.y() < HORIZONTAL_WALL_MIN){
				//���������ĂȂ���c	
			}
		
			//�{�[�������ɗ��������̏���
			else{
				
				if(gameData.sm != TITLE){
					ball_delete_flag = true;
				}
				
			}
			
			balls[i].v.y( balls[i].v.y() * -1.0f);
		}

		//�o�[�Ƃ̓����蔻��
		for(int j = 0; j < boost::numeric_cast<int>(bars.size()); j++){

			CharaObj& bar = bars[j];
			const bool IsCrashedLR = IsCrashed(virtualP.x(), balls[i].p.y(), bar.p.x(), bar.p.y(), BALL_SIZE, BALL_SIZE, BAR_SIZE_X, BAR_SIZE_Y);
			const bool IsCrashedUD = IsCrashed(balls[i].p.x(), virtualP.y(), bar.p.x(), bar.p.y(), BALL_SIZE, BALL_SIZE, BAR_SIZE_X, BAR_SIZE_Y);
			const bool IsCrashed_flag = IsCrashedLR || IsCrashedUD;
			
			//���Ȃ�Â߂̓����蔻��
			if(IsCrashedLR){
				balls[i].v.x( balls[i].v.x() * -1.0f);
			}
			if(IsCrashedUD){
				balls[i].v.y( balls[i].v.y() * -1.0f);
			}
			if(IsCrashed_flag){
				//�o�[��X���W�ɂ����ړ����Ȃ��̂�speed�����̂܂�X���W�̈ړ��ω��ʂɂȂ�
				float vx = bar.v.x();
				balls[i].v.x( balls[i].v.x() + bar.v.x() * BALL_SLIDE_COEFFECIENT );

			}
		}
		//boost::for_each(blocks, boost::bind(
		//
		
		//�Փ˂����u���b�N�̍폜
		//CharaObjs::iterator it = std::remove_if(blocks.begin(), blocks.end() , boost::bind(BlockDeleter, _1, virtualP, balls[i].p));
		//blocks.erase(it, blocks.end());

		for(int j = 0; j < static_cast<int>(blocks.size()); j++){
			CharaObj& block = blocks[j];
			const bool isCrashedLR = IsCrashed(virtualP.x(), balls[i].p.y(), block.p.x(), block.p.y(), BALL_SIZE, BALL_SIZE, BLOCK_SIZE, BLOCK_SIZE);
			const bool isCrashedUD = IsCrashed(balls[i].p.x(), virtualP.y(), block.p.x(), block.p.y(), BALL_SIZE, BALL_SIZE, BLOCK_SIZE, BLOCK_SIZE);
			const bool isCrashed_flag = isCrashedLR || isCrashedUD;

			if(isCrashedLR){
				balls[i].v.x( balls[i].v.x() * -1.0f);
			}
			if(isCrashedUD){
				balls[i].v.y( balls[i].v.y() * -1.0f);
			}
			if(isCrashed_flag){
				EffectBlock(block, gameData);

				if(block.type != UNBREAKABLE){
					blocks.erase(blocks.begin() + j);
					if(gameData.sm== PLAYING){
						gameData.score++;
						gameData.stageInfo.breakableBlockN--;
					}
				}
				
			}
		}
		if(ball_delete_flag)	balls.erase(balls.begin() + i);
		else	balls[i].p += balls[i].v;
	}
}

float ReflectFromDirection(float angle, DIRECTION8 d){
	switch(d){
		case UP:
			angle = 360 - angle;
			break;
		case UPLEFT:
			break;
		case LEFT:
			if(IsAreaSecond(angle))	angle = 180 - angle;
			else angle = 360 - angle + 180;
			break;
		case DOWNLEFT:
			break;
		case DOWN:
			angle = 360 - angle;
			break;
		case DOWNRIGHT:
			break;
		case RIGHT:
			if(IsAreaFirst(angle)) angle = 180 - angle;	
			else angle = 360 - angle + 180;
			break;
		case UPRIGHT:
			break;
	}
	return angle;
}
void EffectBlock(CharaObj& block, Gamedata& gameData){
	switch(block.type){
		//�m�[�}���u���b�N�ɓ����������̏���
		case NORMAL:
			//�m�[�}���u���b�N�̔j�Ђ̐�������
			for(int i = 0; i < BLOCK_BITS_N; i++){
				CharaObj block_bit;
				Polar pl;
				pl.angle = GetRand(BLOCK_BIT_ANGLE_END - BLOCK_BIT_ANGLE_BEGIN) + BLOCK_BIT_ANGLE_BEGIN;
				pl.speed = GetRand(BLOCK_BIT_MAX_SPEED - BLOCK_BIT_MIN_SPEED) + BLOCK_BIT_MIN_SPEED;
				block_bit.p = block.p;
				ConvertPolarToCartesian(block_bit.v, pl);
				gameData.charaInfo.block_bits.push_back(block_bit);
			}
			break;
		//�����u���b�N�ɓ����������̏���
		case EXPLOSION:		
			for(int i = 0; i < BOMB_BITS_N; i++){
				CharaObj bomb_bit;
				Polar pl;

				if(gameData.sm == PLAYING){
					LtdDrawableObj ltdDrawableObj;
					ltdDrawableObj.count = 0;
					ltdDrawableObj.type = LTD_DRAWABLE_OBJ_EXPLOSION;
					ltdDrawableObj.limit = EXPLOSION_DISPLAY_FRAME;
					ltdDrawableObj.p.x( block.p.x() );
					ltdDrawableObj.p.y( block.p.y() );
					gameData.ltdDrawableObjs.push_back(ltdDrawableObj);
				}
				pl.angle = MATH_HELPER_D360 / BOMB_BITS_N * i;
				pl.speed = BOMB_BIT_MIN_SPEED + GetRand(BOMB_BIT_MAX_SPEED - BOMB_BIT_MIN_SPEED);
				ConvertPolarToCartesian(bomb_bit.v, pl);
				bomb_bit.p = block.p;
				gameData.charaInfo.bomb_bits.push_back(bomb_bit);
			}
			break;
		//�t���[�Y�u���b�N�ɓ����������̏���
		case FREEZE:
			for(int i = 0; i < FREEZE_BITS_N; i++){
				CharaObj freeze_bit;
				Polar pl;

				if(gameData.sm == PLAYING){
					//Freeze!�̕\��
				}
				pl.angle = MATH_HELPER_D360 / FREEZE_BITS_N * i;
				pl.speed = FREEZE_BIT_SPEED;
				ConvertPolarToCartesian(freeze_bit.v, pl);
				freeze_bit.p = block.p;
				gameData.charaInfo.freeze_bits.push_back(freeze_bit);
			}
			break;
		//�A�C�e���u���b�N�ɓ����������̏���
		case ITEM_BLOCK:
			MakeItem(block, gameData);
			break;
	}

}



	}
}
