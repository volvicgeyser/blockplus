#ifndef MINIGAME_BLOCK_POINT
#define MINIGAME_BLOCK_POINT


//X座標とY座標を持つPointクラス

namespace Minigame{
	namespace Block{
template <typename T>
class GenericPoint{
private:	
	T x_;
	T y_;
public:

	T x() const {return this->x_;}
	T y() const {return this->y_;}
	void x(T x){this->x_ = x;}
	void y(T y){this->y_ = y;}
	GenericPoint() : x_(0),  y_(0){}
	GenericPoint(T t1, T t2) : x_(t1), y_(t2){}
	GenericPoint<T> operator + (const GenericPoint<T>& p) const{
		GenericPoint<T> result;
		result.x_ = this->x_ + p.x_;
		result.y_ = this->y_ + p.y_;
		return result;
	}
	
	GenericPoint<T> operator-(const GenericPoint<T>& p) const{

		GenericPoint<T> result;
		result.x_ = this->x_ - p.x_;
		result.y_ = this->y_ - p.y_;
		return result;
	}
	template<typename S>GenericPoint<T> operator*(const S s) const{
		GenericPoint<T> result;
		result.x_  = result.x_ * s;
		result.y_ = result.y_ * s;
		return result;
	}
	template<typename S>GenericPoint<T> operator/(const S s) const{
		GenericPoint<T> result;
		result.x_ = result.x_ / s;
		result.y_ = result.y_ / s;
		return result;
	}
	void operator+=(const GenericPoint<T>& p){
		this->x_ = p.x_ + this->x_;
		this->y_ = p.y_ + this->y_;
	}
	void operator-=(const GenericPoint<T>& p){
		this->x_ = this->x_ - p.x_;
		this->y_ = this->y_ - p.y_;
	}
	template<typename S>void operator*=(S s){
		this->x_ = this->x_ * s;
		this->y_ = this->y_ * s;
	}
	template<typename S>void operator/=(S s){
		this->x_ = this->x_ * s;
		this->y_ = this->y_ * s;
	}
	void operator=(const GenericPoint<T>& p){
		this->x_ = p.x_;
		this->y_ = p.y_;
	}
	void Reset(){
		this->x_ = 0;
		this->y_ = 0;
	}
};

typedef GenericPoint<int> Point;
typedef GenericPoint<float> PointF;

	}
}
#endif
