#include"minigame_block_fpscounter.h"


namespace Minigame{
	namespace Block{
	int FPSCounter::GetFrameTime(){
		return this->currentTime - this->prevTime;
	}
	void FPSCounter::Count(){
		if(this->frameCount < 60){
			this->frameCount++;
			this->totalFrameTime += this->GetFrameTime();
		}else{
			this->CalcFPS();
			this->frameCount = 0;	
			this->totalFrameTime = 0;
		}
	}
	void FPSCounter::CalcFPS(){
		this->fps = 1000 / ((double)this->totalFrameTime / (double)60);
	}
	void FPSCounter::Update(){
		if(this->currentTime == 0 && this->prevTime == 0){
			this->prevTime = GetNowCount();
		}
		else{
			if(this->currentTime != 0){
				this->prevTime = this->currentTime;
			}
			this->currentTime = GetNowCount();
			this->Count();
		}
	}
	double FPSCounter::GetFPS(){
		return this->fps;
	}
	void FPSCounter::Init(){
		this->frameCount = 0;
		this->totalFrameTime = 0;
		this->prevTime = 0;
		this->currentTime = 0;
		this->fps = 0;
	}
}
}