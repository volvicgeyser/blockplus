#ifndef DEF_MINIGAME_BLOCK_LINE_H
#define DEF_MINIGAME_BLOCK_LINE_H


//���g�p
//���̃N���X



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