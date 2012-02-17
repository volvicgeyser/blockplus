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

//マップの拡張子
#define MP_STR TEXT(".mp")

//画面サイズ
const int SCREEN_SIZE_WIDTH = 800;
const int SCREEN_SIZE_HEIGHT = 600;

//explosionの表示フレーム時間
const int EXPLOSION_DISPLAY_FRAME = 30;

//重力加速度
const float GRAVITY = 0.5;

//左側の壁の位置
const int VERTICAL_WALL_MIN = 0;

//上側の壁の位置
const int HORIZONTAL_WALL_MIN = 0;

//タイトルステージの番号
const int MAP_NUMBER_TITLE_STAGE = 0;


//ランキングモード
const int RANKINGMODE_X = 180;
const int RANKINGMODE_Y = 300;

//リトライモード
const int RETRYMODE_X = 180;
const int RETRYMODE_Y = 400;


//ステージの個数
const int STAGE_N = 11;
const int STAGE_MAX_X = 64;
const int STAGE_MAX_Y = 64;

//コンティニュー回数
const int CHALLENGE_CHANCE_X = 50;
const int CHALLENGE_CHANCE_Y = 80;

//タイトル画像の表示位置
const int TITLE_X = 120;
const int TITLE_Y = 100;

//スコア画像の表示位置
const int SCORE_X = 50;
const int SCORE_Y = 50;

//plus画像の表示位置
const int TITLE_PLUS_X = 500;
const int TITLE_PLUS_Y = 150;

//	バージョン画像の表示位置
const int VERSION_X = 200;
const int VERSION_Y = 250;

//press enter key.を表示する位置
const int PRESS_ENTER_KEY_X = 200;
const int PRESS_ENTER_KEY_Y = 400;

const int PRESS_ENTER_KEY_INTERVAL = 60 / 2;

//readyを表示する位置
const int READY_X = 200;
const int READY_Y = 200;

//stage clear
const int STAGE_CLEAR_X = 150;
const int STAGE_CLEAR_Y = 200;

//ロゴの表示間隔
const int READY_INTERVAL = 60 / 2;
const int STAGE_CLEAR_INTERVAL = 60 / 3;
const int DROP_INTERVAL = 60 /2;

//コンティニュー回数
const int CONTINUE_N  = 5;

//タイトル画面で使用するボールの数
const int TITLE_BALLS_N = 20;

const int MAX_DEG = 360;
const double PI = 3.14;
const float PI_F = 3.14f;
const double MAX_RAD = 2 * PI;

//ボールの最大速度
const int BALL_MAX_SPEED = 10;

//ボールの最低速度
const int BALL_MIN_SPEED = 5;


//アイテムのサイズ
const int ITEM_SIZE = 16;


//ブロックの破片数
const int BLOCK_BITS_N = 50;

//ブロックの破片が飛び散る角度
const int BLOCK_BIT_ANGLE_BEGIN = 180;
const int BLOCK_BIT_ANGLE_END = 359;
const int BLOCK_BIT_MIN_SPEED = 1;
const int BLOCK_BIT_MAX_SPEED = 5;

//ブロックの破片の大きさ
const int BLOCK_BIT_SIZE = 3;

//ドロップの表示位置
const int DROP_X = 200;
const int DROP_Y = 200;

//バーのサイズ
const int BAR_SIZE_X = 100;
const int BAR_SIZE_Y = 20;

//バーのy座標
const int BAR_Y = 500;

//最初にバーから発射するボールの速度
const int BALL_FIRST_SPEED = 6;

//最初にバーから発射するボールの角度
//const int BALL_FIRST_ANGLE = 45;

//最初にバーから発射するボールの個数
const int BALL_FIRST_N = 30;

const float BALL_SLIDE_COEFFECIENT = 0.8f;

//最初にバーから発射するボールの範囲
const int BALL_FIRST_ANGLE_BEGIN = 30;
const int BALL_FIRST_ANGLE_END = 150;

//ブロックのWidthとHeight
const int BLOCK_SIZE = 16;

//explosionブロックを壊した時の飛び出す爆発ビット数
const int BOMB_BITS_N = 60;

const int BOMB_BIT_MIN_SPEED = 5;
const int BOMB_BIT_MAX_SPEED = 10;
const int BOMB_BIT_SIZE = 10;

//氷ビットの数
const int FREEZE_BITS_N = 50;
const int FREEZE_BIT_SPEED = 5;
const int FREEZE_BIT_SIZE = 10;

//ボールのWidthとHeight
const int BALL_SIZE = 5;

//キーが有効である
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
