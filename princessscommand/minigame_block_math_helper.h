#ifndef DEF_MINIGAME_BLOCK_MATH_HELPER_H
#define DEF_MNIGAME_BLOCK_MATH_HELPER_H
#include<cmath>

//主に計算の補助
//高速な三角関数を実装する予定だったが、
//思ったより早くならなかったので標準の関数を使用

namespace Minigame{
	namespace Block{

const float MATH_HELPER_PI = static_cast<float>(3.14);
const float MATH_HELPER_D30 = 30;
const float MATH_HELPER_D45 = 45;
const float MATH_HELPER_D60 = 60;
const float MATH_HELPER_D180 = 180;
const float MATH_HELPER_R2PI = 2 * MATH_HELPER_PI;
const float MATH_HELPER_D360 = 360;

float f_cos_deg(float deg);
float f_sin_deg(float deg);
float f_cos(float rad);
float f_sin(float rad);
float f_tan(float rad);
float f_tan_deg(float deg);
float f_atan(float y_divided_by_x);
float ConvertDegToRad(float deg);
float ConvertRadToDeg(float rad);
bool IsAreaFirst(float deg);
bool IsAreaSecond(float deg);
bool IsAreaThird(float deg);
bool IsAreaForth(float deg);
	}
}
#endif