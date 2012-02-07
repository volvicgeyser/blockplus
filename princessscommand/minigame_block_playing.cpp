#include"minigame_block_func.h"

namespace Minigame{
	namespace Block{
	
void Update_Playing(Gamedata& gameData){
	UpdateBars(gameData);
	MoveAllBalls(gameData);
	UpdateBombBits(gameData);
	if(gameData.stageInfo.breakableBlockN <= 0){
		gameData.sm = STAGE_CLEAR;
	}
	UpdateBlockBits(gameData);
	Update ltdDrawObjs
	for(int i = 0; i < boost::numeric_cast<int>(gameData.ltdDrawableObjs.size()); i++){
		LtdDrawableObj& obj = gameData.ltdDrawableObjs[i];
		if(obj.limit <= obj.count){
			gameData.ltdDrawableObjs.erase( gameData.ltdDrawableObjs.begin() + i);
		}
		else{
			obj.count++;
		}
	}
#ifdef DEBUGMODE
	if(IsKeyPressed(Keyboard_Get(KEY_INPUT_B))){
	CharaObj c;
	Polar pl;
	c.p.x(100);
	c.p.y(100);
	pl.angle = GetRand(360);
	pl.speed = GetRand(5) + 3;
	ConvertPolarToCartesian(c.v, pl);
	gameData.charaInfo.balls.push_back(c);
	}
#endif

}
void Draw_Playing(Gamedata& gameData){
	PictureMap& g = gameData.graphicData;
	DrawBlocks(gameData);
	DrawBars(gameData);
	DrawAllBalls(gameData);
	DrawBombBits(gameData);
	DrawBlockBits(gameData);
	DrawScore(gameData);
	
	for(int i = 0; i < boost::numeric_cast<int>(gameData.ltdDrawableObjs.size()); i++){
		LtdDrawableObj& obj = gameData.ltdDrawableObjs[i];
		switch(obj.type){
			case LTD_DRAWABLE_OBJ_EXPLOSION:
				if(obj.count < 30){
					DrawRotaGraph(obj.p.x(), obj.p.y(), 1, ConvertDegToRad(obj.count * 24), g["explosion"], TRUE);
				}
				else
					DrawRotaGraph(obj.p.x(), obj.p.y(), 1, 0, g["explosion"], TRUE);
				break;
		}
	}

	if(gameData.charaInfo.balls.size() == 0){
		gameData.sm = DROP;
	}
}
	}
}