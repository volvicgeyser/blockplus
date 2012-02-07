#include"minigame_block_func.h"

namespace Minigame{
	namespace Block{
	
void Standby_Draw(Gamedata& gameData){
	PictureMap& g = gameData.graphicData;
	DrawBlocks(gameData);
	if(gameData.intervalVisibleObjs["ready_logo"].Visible()){
		if(DrawGraph(READY_X, READY_Y, g["ready"], TRUE) == -1){
			pd("ready_logo");
		}
	}
	DrawBars(gameData);
	DrawScore(gameData);
}
void Standby_Update(Gamedata& gameData){
	gameData.intervalVisibleObjs["ready_logo"].Update();
	CharaObjs& balls = gameData.charaInfo.balls;
	CharaObjs& bars = gameData.charaInfo.bars;
	if( IsPressedOK() ){
		
		if(0 < bars.size() ){
			
			CharaObj ball;
			/*ball.p = bars[0].p;
			ball.p.y(ball.p.y() - 50);
			ball.pl.angle = 45;
			ball.pl.speed = BALL_FIRST_SPEED;	
			gameData.charaInfo.balls.push_back(ball);
			*/
			
			for(int i = 0; i < BALL_FIRST_N; i++){
				CharaObj ball;
				Polar pl;

				ball.p = bars[0].p;
				ball.p.y(ball.p.y() - 50);
				
				pl.speed = BALL_FIRST_SPEED;
				
				//Š„‚èŽZ‚µ‚½‚Æ‚«‚É0‚ÅŠ„‚Á‚Ä‚µ‚Ü‚¤‚Ì‚ð–h‚®
				if(i == 0){
					pl.angle = BALL_FIRST_ANGLE_END - BALL_FIRST_ANGLE_BEGIN;
					ConvertPolarToCartesian(ball.v, pl);
					//ball.pl.angle = BALL_FIRST_ANGLE_END - BALL_FIRST_ANGLE_BEGIN;
				}
				else{
					pl.angle = (BALL_FIRST_ANGLE_END - BALL_FIRST_ANGLE_BEGIN) / static_cast<float>(i) + BALL_FIRST_ANGLE_BEGIN;
					ConvertPolarToCartesian(ball.v, pl);
					//ball.pl.angle = (BALL_FIRST_ANGLE_END - BALL_FIRST_ANGLE_BEGIN) / static_cast<float>(i) + BALL_FIRST_ANGLE_BEGIN;
				}

				int fp_state = _fpclass(pl.angle);

				if(fp_state == _FPCLASS_SNAN || fp_state == _FPCLASS_QNAN || fp_state == _FPCLASS_NINF || fp_state == _FPCLASS_PINF){
					throw std::runtime_error("Maybe, It diveded by 0.");
				}

				//ball.pl.speed = BALL_FIRST_SPEED;	
				
				gameData.charaInfo.balls.push_back(ball);
			}
			
			//ball.pl.angle = BALL_FIRST_ANGLE;
			//ball.pl.speed = BALL_FIRST_SPEED;	
		}
		gameData.sm = PLAYING;
	}
	UpdateBars(gameData);
}

	}
}