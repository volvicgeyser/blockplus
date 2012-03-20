#ifndef DEF_MINIGAME_BLOCK_LINE_H
#define DEF_MINIGAME_BLOCK_LINE_H


//未使用
//線のクラス



namespace Minigame{
	namespace Block{
		
template <typename T> struct GenericLine{
	Point p1;
	Point p2;
};
typedef GenericLine<int> Line;
typedef GenericLine<float> LineF;
	}
}

#endif