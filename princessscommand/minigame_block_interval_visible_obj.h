#ifndef DEF_MINIGAME_BLOCK_INTERVAL_VISIBLE_OBJ_H
#define DEF_MINIGAME_BLOCK_INTERVAL_VISIBLE_OBJ_H

namespace Minigame{
	namespace Block{
	
class IntervalVisibleObj{
private:
	bool visible_;
	int interval_;
	int count_;
public:
	IntervalVisibleObj() : count_(0), interval_(0), visible_(false){}
	bool Visible(){return this->visible_;}
	void SetInterval(int interval){this->interval_ = interval;}
	
	void Update(){
		if(this->count_ == this->interval_){
			if(this->interval_ == 0)
				throw "interval‚ª0‚Éİ’è‚³‚ê‚Ä‚¢‚Ü‚·";
			this->count_ = 0;
			if(this->visible_){
				this->visible_ = false;
			}
			else{
				this->visible_ = true;
			}
		}
		else{
			this->count_++;
		}
	}
};

	}
}

#endif