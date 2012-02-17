#ifndef DEF_MINIGAME_BLOCK_DEFINE_H
#define DEF_MINIGAME_BLOCK_DEFINE_H
namespace Minigame{
	namespace Block{

#define MEDIA_PATH_STR TEXT("minigame/block/media/")
#define DAT_PATH_STR TEXT("minigame/block/dat/")
#define CANT_OPEN_GRAPHIC_FILE_STR TEXT("Can't open graphic file")
#define CANT_LOAD_GRAPHIC_DATA_FROM_MEM_STR TEXT("Can't load graphic data from memory")
#define CANT_DRAW_GRAPHIC_STR TEXT("Can't draw graphic")
#define ERROR_STR TEXT("Error")

#define MAP_STR TEXT("map")

//�}�b�v�̊g���q
#define MP_STR TEXT(".mp")

//��ʃT�C�Y
const int SCREEN_SIZE_WIDTH = 800;
const int SCREEN_SIZE_HEIGHT = 600;

//explosion�̕\���t���[������
const int EXPLOSION_DISPLAY_FRAME = 30;

//�d�͉����x
const float GRAVITY = 0.5;

//�����̕ǂ̈ʒu
const int VERTICAL_WALL_MIN = 0;

//�㑤�̕ǂ̈ʒu
const int HORIZONTAL_WALL_MIN = 0;

//�^�C�g���X�e�[�W�̔ԍ�
const int MAP_NUMBER_TITLE_STAGE = 0;


//�����L���O���[�h
const int RANKINGMODE_X = 180;
const int RANKINGMODE_Y = 300;

//���g���C���[�h
const int RETRYMODE_X = 180;
const int RETRYMODE_Y = 400;


//�X�e�[�W�̌�
const int STAGE_N = 11;
const int STAGE_MAX_X = 64;
const int STAGE_MAX_Y = 64;

//�R���e�B�j���[��
const int CHALLENGE_CHANCE_X = 50;
const int CHALLENGE_CHANCE_Y = 80;

//�^�C�g���摜�̕\���ʒu
const int TITLE_X = 120;
const int TITLE_Y = 100;

//�X�R�A�摜�̕\���ʒu
const int SCORE_X = 50;
const int SCORE_Y = 50;

//plus�摜�̕\���ʒu
const int TITLE_PLUS_X = 500;
const int TITLE_PLUS_Y = 150;

//	�o�[�W�����摜�̕\���ʒu
const int VERSION_X = 200;
const int VERSION_Y = 250;

//press enter key.��\������ʒu
const int PRESS_ENTER_KEY_X = 200;
const int PRESS_ENTER_KEY_Y = 400;

const int PRESS_ENTER_KEY_INTERVAL = 60 / 2;

//ready��\������ʒu
const int READY_X = 200;
const int READY_Y = 200;

//stage clear
const int STAGE_CLEAR_X = 150;
const int STAGE_CLEAR_Y = 200;

//���S�̕\���Ԋu
const int READY_INTERVAL = 60 / 2;
const int STAGE_CLEAR_INTERVAL = 60 / 3;
const int DROP_INTERVAL = 60 /2;

//�R���e�B�j���[��
const int CONTINUE_N  = 5;

//�^�C�g����ʂŎg�p����{�[���̐�
const int TITLE_BALLS_N = 20;

const int MAX_DEG = 360;
const double PI = 3.14;
const float PI_F = 3.14f;
const double MAX_RAD = 2 * PI;

//�{�[���̍ő呬�x
const int BALL_MAX_SPEED = 10;

//�{�[���̍Œᑬ�x
const int BALL_MIN_SPEED = 5;


//�A�C�e���̃T�C�Y
const int ITEM_SIZE = 16;


//�u���b�N�̔j�А�
const int BLOCK_BITS_N = 50;

//�u���b�N�̔j�Ђ���юU��p�x
const int BLOCK_BIT_ANGLE_BEGIN = 180;
const int BLOCK_BIT_ANGLE_END = 359;
const int BLOCK_BIT_MIN_SPEED = 1;
const int BLOCK_BIT_MAX_SPEED = 5;

//�u���b�N�̔j�Ђ̑傫��
const int BLOCK_BIT_SIZE = 3;

//�h���b�v�̕\���ʒu
const int DROP_X = 200;
const int DROP_Y = 200;

//�o�[�̃T�C�Y
const int BAR_SIZE_X = 100;
const int BAR_SIZE_Y = 20;

//�o�[��y���W
const int BAR_Y = 500;

//�ŏ��Ƀo�[���甭�˂���{�[���̑��x
const int BALL_FIRST_SPEED = 6;

//�ŏ��Ƀo�[���甭�˂���{�[���̊p�x
//const int BALL_FIRST_ANGLE = 45;

//�ŏ��Ƀo�[���甭�˂���{�[���̌�
const int BALL_FIRST_N = 30;

const float BALL_SLIDE_COEFFECIENT = 0.8f;

//�ŏ��Ƀo�[���甭�˂���{�[���͈̔�
const int BALL_FIRST_ANGLE_BEGIN = 30;
const int BALL_FIRST_ANGLE_END = 150;

//�u���b�N��Width��Height
const int BLOCK_SIZE = 16;

//explosion�u���b�N���󂵂����̔�яo�������r�b�g��
const int BOMB_BITS_N = 60;

const int BOMB_BIT_MIN_SPEED = 5;
const int BOMB_BIT_MAX_SPEED = 10;
const int BOMB_BIT_SIZE = 10;

//�X�r�b�g�̐�
const int FREEZE_BITS_N = 50;
const int FREEZE_BIT_SPEED = 5;
const int FREEZE_BIT_SIZE = 10;

//�{�[����Width��Height
const int BALL_SIZE = 5;

//�L�[���L���ł���
const int KEY_IS_VALID = 0;

#define RETRYMODE_STR _T("retrymode")
#define RANKINGMODE_STR _T("rankingmode")
#define ITEM_STR _T("item");
#define DROP_STR _T("drop");
#define EXPLOSION_STR _T("explosion")
#define STAGE_CLEAR_STR _T("stage_clear")
#define PRESS_ENTER_KEY_STR _T("press_enter_key")
#define TITLE_STR _T("title")
#define VERSION_STR _T("ver0.06")
#define BALL_STR _T("ball")
#define PLUS_STR _T("plus")
#define BLOCK_STR _T("block")
#define PNG_STR _T(".png")
#define BMP_STR _T(".bmp")
#define JPG_STR _T(".jpg")

//#define FOR_SM(N) int i; i < N; i++;

	}
}
#endif
