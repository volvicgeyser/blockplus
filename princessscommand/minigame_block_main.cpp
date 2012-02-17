#include"minigame_block_func.h"

//デバッグモード
#define DEBUGMODE

//#include"mybug.h"
using namespace std;

namespace Minigame{
namespace Block{
int Minigame::Block::Main_Func(
	System_t *system_t,
	Option_t *option_t,
	Speak_t *speak_t,
	Save_t *save_t,
	Battle_chara_t *battle_chara_t,
	Battle_info_t *battle_info_t,
	Menu_t *menu_t)
{
	Gamedata gameData;
	SetDrawScreen(DX_SCREEN_BACK);
	InitGameData(gameData);
	gameData.fpsCounter.Init();

	//バグベアード様降臨
	//MyBugInit();
	
	while(ScreenFlip()==0 && ProcessMessage()==0 && ClearDrawScreen()==0 && Keyboard_Get( KEY_INPUT_ESCAPE ) == 0 ){
		Keyboard_Update();
		UpdateMouse();
		switch(gameData.sm){
			case INIT:
				Init(gameData);
				break;
			case TITLE:
				Title_Draw(gameData);
				Title_Update(gameData);
				break;
			case STANDBY:
				Standby_Draw(gameData);
				Standby_Update(gameData);
				break;
			case DROP:
				Drop_Draw(gameData);
				Drop_Update(gameData);
				break;
			case PLAYING:
				Draw_Playing(gameData);
				Update_Playing(gameData);
				break;
			case STAGE_CLEAR:
				Draw_StageClear(gameData);
				Update_StageClear(gameData);
				break;
			case GAMEOVER:
				Draw_Gameover(gameData);
				Update_Gameover(gameData);
				break;
			case ENDING:
				Draw_Ending(gameData);
				Update_Ending(gameData);
				break;
		}
		gameData.totalFrameCount++;

		//常に描画されるデバッグ表示
#ifdef DEBUGMODE
		gameData.fpsCounter.Update();
		DWORD color = GetColor(255,255,255);
		DrawFormatString(0,0, color,"FPS:%lf", gameData.fpsCounter.GetFPS());
		DrawFormatString(0,30, color, "blocks.size():%d", gameData.charaInfo.blocks.size());
		DrawFormatString(0,60, color, "balls.size():%d", gameData.charaInfo.balls.size());
		if(gameData.charaInfo.balls.size() != 0){
			DrawFormatString(0,90, color, "balls[0].p.x:%f", gameData.charaInfo.balls[0].p.x());
			DrawFormatString(0,120, color, "balls[0].p.y:%f", gameData.charaInfo.balls[0].p.y());
			//DrawFormatString(0,150, color, "balls[0].pl.angle:%f", gameData.charaInfo.balls[0].pl.angle);
		}
		DrawFormatString(0,180, color, "bars.size():%d", gameData.charaInfo.bars.size());
		if(gameData.charaInfo.bars.size() != 0){
			DrawFormatString(0,210, color, "bars[0].p.x:%f", gameData.charaInfo.bars[0].p.x());
			DrawFormatString(0,240, color, "bars[0].p.y:%f", gameData.charaInfo.bars[0].p.y());
		}
		DrawFormatString(0,270, color, "bomb_bits.size():%d", gameData.charaInfo.bomb_bits.size());
#endif

	}
	return gameData.score;
}




//ボールの描画
void DrawBall(CharaObj& c, PictureMap& g){
	if(DrawGraph(static_cast<int>(c.p.x()), static_cast<int>(c.p.y()), g["ball3"], TRUE) == -1){
		pd(CANT_DRAW_GRAPHIC_STR);
	}
}

//全てのボールの描画
void DrawAllBalls(Gamedata &gameData){
	PictureMap &g = gameData.graphicData;
	CharaObjs &balls = gameData.charaInfo.balls;
	for_each(balls.begin(), balls.end(), boost::bind(DrawBall, _1, g));
}


//|------------------------------------オブジェクトの移動に関する関数-----------------------------------------------------|
float ToChangeDegree0To360(float deg){
	if(360 < deg){
		deg = deg - floor(deg / 360) * 360;
	}
	if(deg < 0){
		deg = 360 + deg;
	}
	return deg;
}

float ToChangeRad0To2PI(float rad){
	if(2 * PI < rad){
		rad = rad - floorf(rad / (2 * PI_F)) * 2 * PI_F;
	}
	if(rad < 0){
		rad = 2 * PI_F + rad;
	}
	return rad;
}

//角度 = π - 入射角
float AngleReflectX(float angle){
	return ToChangeDegree0To360(MAX_DEG / 2 - angle);
}
//角度 = 2π - 入射角
float AngleReflectY(float angle){
	return ToChangeDegree0To360(MAX_DEG - angle);
}

//極座標から直交座標に変換
void ConvertPolarToCartesian(PointF& buf, float angle, float speed){
	buf.x(f_cos_deg(angle) * speed);
	buf.y(-f_sin_deg(angle) * speed);
}

void ConvertPolarToCartesian(PointF& buf, Polar& pl){
	ConvertPolarToCartesian(buf, pl.angle, pl.speed);
}

//直交座標から極座標に変換　　動作がおかしいかも
//void ConvertCartesianToPolar(Polar& buf, PointF& p){
//        float radAngle = atan2f(p.y(), p.x());
//        float r = 1.0f / cosf(radAngle);
//        buf.speed = r * p.y();
//        buf.angle = ConvertRadToDeg(radAngle);
//}

void GetCharaCenter(PointF& buf, const PointF& p, float size){
	float half_size = size / (float)2;
	buf.x(half_size + p.x() );
	buf.y(half_size + p.y() );
}
COORDINATE_AREA GetCoordinateArea(PointF p){
	//++
	COORDINATE_AREA area;
	if(p.x() > 0 && p.y() > 0)	area = FIRST;
	//-+
	if(0 > p.x() && p.y() > 0)	area = SECOND;
	//--
	if(0 > p.x() && 0 > p.y())	area = THIRD;
	//+-
	if(p.x() > 0 && 0 > p.y())	area = FORTH;
	return area;
}
float GetAngleFromTwoPointF(PointF& start, PointF& end){
	PointF d = end - start;
	return atan2(-d.y(), d.x());
}
DIRECTION8 ReverceDirection8(DIRECTION8 d){
	DIRECTION8 r;
	switch(d){
		case UP:
			r = DOWN;
			break;
		case UPLEFT:
			r = DOWNRIGHT;
			break;
		case LEFT:
			r = RIGHT;
			break;
		case DOWNLEFT:
			r = UPRIGHT;
			break;
		case DOWN:
			r = UP;
			break;
		case DOWNRIGHT:
			r = UPLEFT;
			break;
		case RIGHT:
			r = LEFT;
			break;
		case UPRIGHT:
			r = DOWNLEFT;
			break;
	}
	return r;
}

DIRECTION8 ConvertDegreeToDireciton4(float angle){
	DIRECTION8 d;
	if(45 <= angle && angle <= 135){
		d = UP;
	}
	else if(135 <= angle && angle <= 225){
		d = LEFT;
	}
	else if(225 <= angle && angle <= 315){
		d = DOWN;
	}
	else{
		d = RIGHT;
	}
	return d;
}
DIRECTION8 ConvertDegreeToDirection8(float angle){
	DIRECTION8 d;
	if(50 <= angle && angle <= 130){
		d = UP;
	}
	else if(130 <= angle && angle <= 135){
		d = UPLEFT;
	}
	else if(135 <= angle && angle <= 220){
		d = LEFT;
	}
	else if(220 <= angle && angle <= 225){
		d = DOWNLEFT;
	}
	else if(225 <= angle && angle <= 310){
		d = DOWN;
	}
	else if(310 <= angle && angle <= 315){
		d = DOWNRIGHT;
	}
	else if( (315 <= angle && angle <= 360) || (0 <= angle && angle <= 45) ){
		d = RIGHT;
	}
	else{
		d = UPRIGHT;
	}
	return d;
}

void DrawBombBit(CharaObj& c, PictureMap& g){
	//PictureMap& g = gameData.graphicData;
	DrawGraph(static_cast<int>(c.p.x()), static_cast<int>(c.p.y()), g["bombbit"], TRUE);
}
void DrawBombBits(Gamedata& gameData){
	CharaObjs& bits = gameData.charaInfo.bomb_bits;
	boost::for_each(bits, boost::bind(DrawBombBit, _1, gameData.graphicData));
}
//void UpdateBombBit(CharaObj& c){
//	PointF dp;
//	ConvertPolarToCartesian(dp, c.pl.angle, c.pl.speed);
//	if(IsCrashedVerticalWall(c.p.x, dp.x, BOMB_BIT_SIZE)){
		
//	}
//}
void UpdateBombBits(Gamedata& gameData){
	CharaObjs& bits = gameData.charaInfo.bomb_bits;
	CharaObjs& blocks = gameData.charaInfo.blocks;
	//boost::for_each(bits, UpdateBombBit);
	for(int i = 0; i < boost::numeric_cast<int>(bits.size()); i++){
		CharaObj& bit = bits[i];
		//PointF dp;
		//ConvertPolarToCartesian(dp, bit.pl.angle, bit.pl.speed);

		bool erase_flag = false;
		bit.p.x();
		bit.p.y();
		bit.v.x();
		bit.v.y();
		if(IsCrashedVerticalWall(bit.p.x(), bit.v.x(), BOMB_BIT_SIZE) || IsCrashedHorizontalWall(bit.p.y(), bit.v.y(), BOMB_BIT_SIZE)){
			erase_flag = true;	
		}
	
		//ブロックとの当たり判定
		if(erase_flag == false){
			//if(erase_flag == true)
			//	throw;
			for(int j = 0; j < boost::numeric_cast<int>(blocks.size()); j++){
				
				//要素が増えた時に参照先が変更されても大丈夫なようにする
				//bit = bits[i];

				CharaObj& block = blocks[j];
				//DrawString(bit.p.x(), bit.p.y(), "", GetColor(255,255,255));

				bool IsCrashedBomb_bit = IsCrashed(block.p.x(), block.p.y(), bit.p.x(), bit.p.y(), BALL_SIZE, BALL_SIZE, BOMB_BIT_SIZE, BOMB_BIT_SIZE);
				if(IsCrashedBomb_bit){
					erase_flag = true;
					EffectBlock(block, gameData);
					if(block.type != UNBREAKABLE){
						if(gameData.sm== PLAYING){
							gameData.score++;
							gameData.stageInfo.breakableBlockN--;
						}
					}
					blocks.erase(blocks.begin() + j);
				}
			}
		}
		if(erase_flag){
			bits.erase(bits.begin() + i);
		}
		else	bit.p += bit.v;
	}
}
//ブロックの描画
void DrawBlocks(Gamedata &gamedata){
	PictureMap& g = gamedata.graphicData;
	//StageInfo& si = gamedata.stageInfo;
	CharaObjs& blocks = gamedata.charaInfo.blocks;
	//StageVec& s = si.default_stagesVec[si.currentStage];
	for(int i = 0; i  < (int)blocks.size(); i++){
		//vector<char>& line = s[i];
		//for(int j = 0; j < (int)blocks.size(); j++){
		CharaObj& block = blocks[i];
			int blockType = block.type;//(int)line[j];
			switch(blockType){
				case NOTHING:
					//何もしない
					break;
				case NORMAL:
//					BUG_puts(BUG_VAL(i));
//					BUG_puts(BUG_VAL(j));
					DrawGraph(static_cast<int>(block.p.x()), static_cast<int>(block.p.y()), g["block0"], TRUE);
					break;
				case UNBREAKABLE:
					DrawGraph(static_cast<int>(block.p.x()), static_cast<int>(block.p.y()), g["block1"], TRUE);
					break;
				case EXPLOSION:
					DrawGraph(static_cast<int>(block.p.x()), static_cast<int>(block.p.y()), g["block2"], TRUE);
					break;
				case FREEZE:
					DrawGraph(static_cast<int>(block.p.x()), static_cast<int>(block.p.y()), g["block3"], TRUE);
					break;
				default:
					pd("マップデータに無効な文字が入っています");
					break;
			}
	}
}


//ready

void DrawBar(CharaObj c){
	if(DrawBox(c.p.x(), c.p.y(), c.p.x() + c.size.x(), c.p.y() + c.size.y(), GetColor(230,230,230), FALSE) == -1){
		pd("can't display bar.");
	}
}
void DrawBars(Gamedata& gameData){
	CharaObjs& bars = gameData.charaInfo.bars;
	for_each(bars.begin(), bars.end(), boost::bind(DrawBar, _1));
}
void DrawScore(Gamedata& gameData){
	PictureMap g = gameData.graphicData;
	//DrawGraph(SCORE_X, SCORE_Y, g["score"], TRUE);
	DrawFormatString(SCORE_X, SCORE_Y, GetColor(255,255,255), "Score: %d", gameData.score);
}

void UpdateBars(Gamedata& gameData){
	CharaObjs& bars = gameData.charaInfo.bars;
	int x,y;
	GetMousePoint(&x, &y);
	if(0 < bars.size()){

		//マウスの中央にバーの中央くるようにする
		int vx = x - bars[0].size.x() / 2.0f;


		static int prev_vx = vx;

		//スクリーンの横からでないようにする
		if(vx < 0) vx = 0;
		else if (SCREEN_SIZE_WIDTH - bars[0].size.x() < vx ) vx = SCREEN_SIZE_WIDTH - bars[0].size.x();	

		float speed;

		speed = static_cast<float>(vx) - prev_vx;
		
		prev_vx = vx;
		
		bars[0].v.x(speed);
		bars[0].p.x(vx);
	}
}

void DrawChallengeChange(Gamedata& gameData){
	DrawString(CHALLENGE_CHANCE_X, CHALLENGE_CHANCE_Y, "Continue: ∞", GetColor(255,255,255));
}

void UpdateBlockBit(CharaObj& c){


}

void UpdateBlockBits(Gamedata& gameData){
	CharaObjs& block_bits = gameData.charaInfo.block_bits;
	for(int i = 0; i < boost::numeric_cast<int>(block_bits.size()); i++){
		CharaObj& block_bit = block_bits[i];
		block_bit.v.y( block_bit.v.y() + GRAVITY);
	
		if(IsCrashedVerticalWall(block_bit.p.x(), block_bit.v.x(), BLOCK_BIT_SIZE) || IsCrashedHorizontalWall(block_bit.p.y(), block_bit.v.y(), BLOCK_BIT_SIZE)){
			block_bit.p.x( block_bit.p.x() + block_bit.v.x() );
			block_bits.erase( block_bits.begin() + i);
		}
		else{
			block_bit.p += block_bit.v;
		}
	}
}

void DrawBlockBit(CharaObj& c, PictureMap& g){
	if( DrawGraph(c.p.x(),  c.p.y(), g["blockbit"], TRUE) == -1){
		pd("can't draw block_bit");
	}
}

void DrawBlockBits(Gamedata& gameData){
	PictureMap& g = gameData.graphicData;
	boost::for_each( gameData.charaInfo.block_bits, boost::bind(DrawBlockBit, _1, g) );
}


void GoNextStage(Gamedata& gameData){
	if(gameData.score != MAP_NUMBER_TITLE_STAGE){
		gameData.score += boost::numeric_cast<int>(gameData.charaInfo.balls.size());
	}
	InitStage(gameData);

	gameData.ltdDrawableObjs.clear();
	if(gameData.stageInfo.currentStage != 5){
			gameData.stageInfo.currentStage++;
			InitBlocks(gameData);
			gameData.sm = STANDBY;
	}else{
			gameData.sm = ENDING;
	}
}

void InitStage(Gamedata& gameData){
	CharaObjs& balls = gameData.charaInfo.balls;
	CharaObjs& block_bits = gameData.charaInfo.block_bits;
	CharaObjs& bomb_bits = gameData.charaInfo.bomb_bits;
	CharaObjs& freeze_bits = gameData.charaInfo.freeze_bits;
	CharaObjs& items = gameData.charaInfo.items;
	CharaObjs& bars = gameData.charaInfo.bars;

	InitBar(gameData);
	
	balls.clear();
	block_bits.clear();
	bomb_bits.clear();
	items.clear();
	
	InitBlocks(gameData);
}

void MakeItem(CharaObj& block, Gamedata& gameData){
	
}

}
}
