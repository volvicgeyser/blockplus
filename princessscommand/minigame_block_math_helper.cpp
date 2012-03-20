#include"minigame_block_func.h"
#include"minigame_block_math_helper.h"

namespace Minigame{
	namespace Block{

		float ConvertDegToRad(float deg){
			return deg / MATH_HELPER_D180 * MATH_HELPER_PI;
		}
		float ConvertRadToDeg(float rad){
			return rad * MATH_HELPER_D180 / MATH_HELPER_PI;
		}
		float f_cos_deg(float deg){
			return std::cos(ConvertDegToRad(deg));
		}
		float f_sin_deg(float deg){
			return std::sin(ConvertDegToRad(deg));
		}
		float f_tan_deg(float deg){
			return std::tan(ConvertDegToRad(deg));
		}
		float f_atan(float y_divided_by_x){
			return std::atan(y_divided_by_x);
		}
		float f_cos(float rad){
			return std::cos(rad);
		}
		float f_sin(float rad){
			return std::sin(rad);
		}
		bool IsAreaFirst(float deg){
			bool r;
			if(0 <= deg, deg <= 90){ r = true; }
			else{ r = false; }
			return r;
		}
		bool IsAreaSecond(float deg){
			bool r;
			if(90 <= deg, deg < 180) { r = true;}
			else{ r = false; }
			return r;
		}
		bool IsAreaThird(float deg){
			bool r;
			if(180 <= deg, deg < 270){ r = true;}
			else{r = false; }
			return r;
		}
		bool IsAreaForth(float deg){
			bool r;
			if(270 <= deg, deg < 360){r = true;}
			else{r = false;}
			return r;
		}

	}
}