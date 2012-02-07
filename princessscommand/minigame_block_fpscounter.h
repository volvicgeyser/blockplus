#ifndef DEF_MINIGAME_BLOCK_FPSCOUNTER_H
#define DEF_MINIGAME_BLOCK_FPSCOUNTER_H

#include"DxLib.h"

//dx���C�u�����Ɉˑ��B
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

	//Update()�����o�֐��͏������ɌĂяo��
	void Update();
};
	}
}
#endif