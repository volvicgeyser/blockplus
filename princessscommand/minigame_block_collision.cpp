#include"minigame_block_func.h"
#include"minigame_block_struct.h"
#include"minigame_block_define.h"
namespace Minigame{
	namespace Block{
//|------------------------------------オブジェクトの当たり判定に関する関数-----------------------------------------------------|


bool IsCrashedWall(float p, float dp, int screenSize, int objSize){
	float vp = p + dp;
	bool result;
	if(vp < 0 || (screenSize - objSize) < vp) result = true;
	else result = false;
	return result;
}
bool IsCrashedVerticalWall(float x, float dx, int objSize){
	return IsCrashedWall(x, dx, SCREEN_SIZE_WIDTH, objSize);
}
bool IsCrashedHorizontalWall(float y, float dy, int objSize){
	return IsCrashedWall(y, dy, SCREEN_SIZE_HEIGHT, objSize);
}
bool IsCrashed(CharaObj &c1, CharaObj &c2){
	return IsCrashed(c1.p.x(), c1.p.y(), c2.p.x(), c2.p.y(), c1.size.x(), c1.size.y(), c2.size.x(), c2.size.y());
}
bool IsCrashed(CharaObj &c1, CharaObj &c2, float cs1, float cs2){
	return IsCrashed(c1.p.x(), c1.p.y(), c2.p.x(), c2.p.y(), c1.size.x(), c1.size.y(), cs1, cs2);
}
bool IsCrashed(float x1, float y1, float x2, float y2, float xs1, float ys1, float xs2, float ys2){
	if(IsCrashedOn1D(x1, x2, xs1, xs2) && IsCrashedOn1D(y1, y2, ys1, ys2)){
		return true;
	}
	return false;
}
bool IsCrashed(float x1, float y1, float x2, float y2, int s1, int s2){
	if(IsCrashedOn1D(x1, x2, s1, s2) && IsCrashedOn1D(y1, y2, s1, s2)){
		return true;
	}
	return false;
}
bool IsCrashedOn1D(float x1, float x2, float xs1, float xs2){
	if(x1 < x2 + xs2 && x2 < x1 + xs1){
		return true;
	}
	return false;
}


	}
}