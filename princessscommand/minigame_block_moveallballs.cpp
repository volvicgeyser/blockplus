#include"minigame_block_func.h"

namespace Minigame{
	namespace Block{
	
void MoveAllBalls(Gamedata &gameData){
	CharaObjs &balls = gameData.charaInfo.balls;
	CharaObjs &blocks = gameData.charaInfo.blocks;
	CharaObjs &bars = gameData.charaInfo.bars;
	CharaObjs &bomb_bits = gameData.charaInfo.bomb_bits;
	CharaObjs &freeze_bits = gameData.charaInfo.freeze_bits;
	for(int i = 0; i < boost::numeric_cast<int>(balls.size()); i++){
		CharaObj& ball = balls[i];

		//ConvertPolarToCartesian(d, ball.pl);

		//仮想位置
		//PointF v;
		//v = d + ball.p;
		
		PointF virtualP;
		virtualP = ball.v + ball.p;
		bool IsCrashedVW_flag = IsCrashedVerticalWall(ball.p.x(), ball.v.x(), BALL_SIZE);
		bool IsCrashedHW_flag = IsCrashedHorizontalWall(ball.p.y(), ball.v.y(), BALL_SIZE);
		bool block_delete_flag = false;
		bool ball_delete_flag = false;

		if(IsCrashedVW_flag){
			//dx = -dx;
			if(virtualP.x() < VERTICAL_WALL_MIN){
				//ball.p.x(static_cast<float>(VERTICAL_WALL_MIN));
			}else{
				//ball.p.x(static_cast<float>(SCREEN_SIZE_WIDTH - BALL_SIZE));
			}
			//アークタンジェントで求める場合は象限ごとに処理をわける必要がある
			//ball.pl.angle = ConvertRadToDeg(f_atan(d.y / d.x));

			//ball.pl.angle = AngleReflectX(ball.pl.angle);
			ball.v.x( ball.v.x() * -1.0f);
			//d.x(0);
		}
		if(IsCrashedHW_flag){
			//dy = - dy;
			if(virtualP.y() < HORIZONTAL_WALL_MIN){
				//ball.p.y(static_cast<float>(HORIZONTAL_WALL_MIN));
			}else{
				
				if(gameData.sm != TITLE){
					ball_delete_flag = true;
					//balls.erase( balls.begin() + i);
					//break;
				}
				else{
					//ball.p.y(static_cast<float>(SCREEN_SIZE_HEIGHT - BALL_SIZE));
				}
				
			}
			
			//アークタンジェントで求める
			//ball.pl.angle = ConvertRadToDeg(f_atan(d.y / d.x));

			//ball.pl.angle = AngleReflectY(ball.pl.angle);
			ball.v.y( ball.v.y() * -1.0f);
			//d.y(0);
		}

		//バーとの当たり判定
		for(int j = 0; j < boost::numeric_cast<int>(bars.size()); j++){

			CharaObj& bar = bars[j];
			//bool IsCrashedBar = IsCrashed(v.x(), v.y(), bar.p.x(), bar.p.y(), BALL_SIZE, BALL_SIZE,BAR_SIZE_X, BAR_SIZE_Y);
			bool IsCrashedLR = IsCrashed(virtualP.x(), ball.p.y(), bar.p.x(), bar.p.y(), BALL_SIZE, BALL_SIZE, BAR_SIZE_X, BAR_SIZE_Y);
			bool IsCrashedUD = IsCrashed(ball.p.x(), virtualP.y(), bar.p.x(), bar.p.y(), BALL_SIZE, BALL_SIZE, BAR_SIZE_X, BAR_SIZE_Y);
			bool IsCrashed_flag = IsCrashedLR || IsCrashedUD;
			if(IsCrashedLR){
				ball.v.x( ball.v.x() * -1.0f);
			}
			if(IsCrashedUD){
				ball.v.y( ball.v.y() * -1.0f);
			}
			if(IsCrashed_flag){
				//バーはX座標にしか移動しないのでspeedがそのままX座標の移動変化量になる
				float vx = bar.v.x();
				//PointF vp;
				//ball.pl.angle = 360 - ball.pl.angle;
				ball.v.x( ball.v.x() + bar.v.x() * BALL_SLIDE_COEFFECIENT );
				//d.x( d.x() + vx * BALL_SLIDE_COEFFECIENT);
				//f(0 < vx)
				//	ball.pl.angle -= vx * BALL_SLIDE_COEFFECIENT;
				//else
				//	ball.pl.angle += vx * BALL_SLIDE_COEFFECIENT;
				//ConvertPolarToCartesian(vp, 360 - ball.pl.angle);
				//d.x( d.x() + vx * BALL_SLIDE_COEFFECIENT); 

			}
		}
		
		



		//CharaObjs::iterator it = find_if(blocks.begin(), blocks.end(), boost::bind(IsCrashed, ball _1, BALL_SIZE, BLOCK_SIZE));

		for(int j = 0; j < static_cast<int>(blocks.size()); j++){
			CharaObj& block = blocks[j];
			//bool isCrashedBlock = IsCrashed(virtualP.x(), virtualP.y(), block.p.x(), block.p.y(), BALL_SIZE, BLOCK_SIZE);
			bool isCrashedLR = IsCrashed(virtualP.x(), ball.p.y(), block.p.x(), block.p.y(), BALL_SIZE, BALL_SIZE, BLOCK_SIZE, BLOCK_SIZE);
			bool isCrashedUD = IsCrashed(ball.p.x(), virtualP.y(), block.p.x(), block.p.y(), BALL_SIZE, BALL_SIZE, BLOCK_SIZE, BLOCK_SIZE);
			bool isCrashed_flag = isCrashedLR || isCrashedUD;

			if(isCrashedLR){
				ball.v.x( ball.v.x() * -1.0f);
			}
			if(isCrashedUD){
				ball.v.y( ball.v.y() * -1.0f);
			}
			if(isCrashed_flag){
				//CharaObjs& bomb_bits = gameData.charaInfo.bomb_bits;
				EffectBlock(block, gameData);

				if(block.type != UNBREAKABLE){
					blocks.erase(blocks.begin() + j);
					if(gameData.sm== PLAYING){
						gameData.score++;
						gameData.stageInfo.breakableBlockN--;
					}
				}
				
			}
			//if(isCrashedBlock){
				//PointF block_center;
				//PointF ball_center;
				//GetCharaCenter(block_center, block.p, static_cast<float>(BLOCK_SIZE));
				//GetCharaCenter(ball_center, ball.p, static_cast<float>(BALL_SIZE));
				//float angle = ToChangeDegree0To360( ConvertRadToDeg( GetAngleFromTwoPointF(ball_center, block_center) ) );
				//角度から4方向を取得
				//DIRECTION8 d = ConvertDegreeToDireciton4(angle);
				
				//方向を元に角度反射
				//ball.pl.angle = ReflectFromDirection(ball.pl.angle, d);

				//CharaObjs& bomb_bits = gameData.charaInfo.bomb_bits;

				//ブロック効果発動
				//EffectBlock(block, bomb_bits, gameData);	

				//BlockがUnbreakableかどうか
				//if(block.type != UNBREAKABLE){
				//	blocks.erase(blocks.begin() + j);
				//	if(gameData.sm== PLAYING)
				//		gameData.score++;
				//		gameData.stageInfo.breakableBlockN--;
				//}
				//break;
			
		}
		if(ball_delete_flag)	balls.erase(balls.begin() + i);
		else	ball.p += ball.v;
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
		case NORMAL:
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
		case EXPLOSION:		
			for(int i = 0; i < BOMB_BITS_N; i++){
				CharaObj bomb_bit;
				Polar pl;

				//bomb_bit.appearanceFrame = gameData.totalFrameCount;
				
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
				//bomb_bit.pl.angle = 360 / BOMB_BITS_N * i;
				//bomb_bit.pl.speed = BOMB_BIT_MIN_SPEED + GetRand(BOMB_BIT_MAX_SPEED - BOMB_BIT_MIN_SPEED);
				ConvertPolarToCartesian(bomb_bit.v, pl);
				bomb_bit.p = block.p;
				gameData.charaInfo.bomb_bits.push_back(bomb_bit);
			}
			break;
		case FREEZE:
			for(int i = 0; i < FREEZE_BITS_N; i++){
				CharaObj freeze_bit;
				Polar pl;

				if(gameData.sm == PLAYING){
					//Freeze!の表示
				}
				pl.angle = MATH_HELPER_D360 / FREEZE_BITS_N * i;
				pl.speed = FREEZE_BIT_SPEED;
				ConvertPolarToCartesian(freeze_bit.v, pl);
				freeze_bit.p = block.p;
				gameData.charaInfo.freeze_bits.push_back(freeze_bit);
			}
			break;
		case ITEM_BLOCK:
			MakeItem(block, gameData);
			break;
	}

}



	}
}
