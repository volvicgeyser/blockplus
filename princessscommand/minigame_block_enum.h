#ifndef DEF_MINIGAME_BLOCK_ENUM_H
#define DEF_MINIGAME_BLOCK_ENUM_H

namespace Minigame{
	namespace Block{
enum SCREENMODE{
	INIT,
	TITLE,
	STANDBY,
	PLAYING,
	DROP,
	STAGE_CLEAR,
	ENDING,
	GAMEOVER
};

enum BLOCK_TYPE{
	NOTHING,
	NORMAL,
	UNBREAKABLE,
	EXPLOSION,
	FREEZE,
	ITEM_BLOCK
};

enum DIRECTION8{
	UP,
	UPRIGHT,
	RIGHT,
	DOWNRIGHT,
	DOWN,
	DOWNLEFT,
	LEFT,
	UPLEFT
};

enum ITEM_TYPE{
	MAKE_BALL
};
enum COORDINATE_AREA{
	FIRST,
	SECOND,
	THIRD,
	FORTH
};

enum LTD_DRAWABLE_OBJ_TYPE{
	LTD_DRAWABLE_OBJ_EXPLOSION
};

enum GAMEMODE{
	RANKINGMODE,
	RETRYMODE
};


	}
}

#endif