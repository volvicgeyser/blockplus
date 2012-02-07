#ifndef DEF_MINIGAME_BLOCK_FPSCOUNTER_H
#define DEF_MINIGAME_BLOCK_FPSCOUNTER_H

#include"DxLib.h"

//dxライブラリに依存。
namespace Minigame{
	namespace Block{

class FPSCounter{
private:
	int currentTime;
	int prevTime;
	int totalFrameTime;
	int frameCount;
	double fps;

	int GetFrameTime();
	void Count();
	void AddTotalFrameCount();
	void CalcFPS();


public:
	void Init();
	double GetFPS();

	//Update()メンバ関数は処理毎に呼び出す
	void Update();
};
	}
}
#endif