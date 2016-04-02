#include"Vector2D.h"


suken::Vector2D::Vector2D( float _x , float _y ){
	x = _x;
	y = _y;
    }
suken::Vector2D::Vector2D(){
	x = 0.0f;
	y = 0.0f;
}
void suken::Vector2D::Set( float _x , float _y){
	x = _x;
	y = _y;
    }
void suken::Vector2D::Set(Vector2D _vec){
	x = _vec.x;
	y = _vec.y;
}     
suken::Vector2D suken::Vector2D::Add( float _x , float _y){
	x += _x;
	y += _y;
	return *this;
}
suken::Vector2D suken::Vector2D::Add(Vector2D _vec){
	x += _vec.x;
	y += _vec.y;
        
	return *this;
}
// +演算子オーバーロード
suken::Vector2D suken::Vector2D::operator+(const Vector2D &obj){
	Vector2D tmp;
	tmp.x = x + obj.x;
	tmp.y = y + obj.y;
	return tmp;
}
// +=演算子オーバーロード
suken::Vector2D& suken::Vector2D::operator+=(const Vector2D &obj){
	x += obj.x;
	y += obj.y;
	return *this;
}    
// -演算子オーバーロード
suken::Vector2D suken::Vector2D::operator-(const Vector2D &obj){
	Vector2D tmp;
	tmp.x = x - obj.x;
	tmp.y = y - obj.y;
	return tmp;
}
// -=演算子オーバーロード
suken::Vector2D& suken::Vector2D::operator-=(const Vector2D &obj){
	x -= obj.x;
	y -= obj.y;
	return *this;
}
//*演算子オーバーロード
suken::Vector2D suken::Vector2D::operator*(const float _num){
	Vector2D tmp;
	tmp.x = x * _num;
	tmp.y = y * _num;
	return tmp;
}
//*=演算子オーバーロード
suken::Vector2D& suken::Vector2D::operator*=(const float _num){
	x*=_num;
	y*=_num;
	return *this;
}
//  /演算子オーバーロード
suken::Vector2D suken::Vector2D::operator/(const float _num){
	Vector2D tmp;
	tmp.x = x / _num;
	tmp.y = y / _num;
	return tmp;
}
///=演算子オーバーロード
suken::Vector2D& suken::Vector2D::operator/=(const float _num){
	x/=_num;
	y/=_num;
	return *this;
}
///==演算子オーバーロード
bool suken::Vector2D::operator==(const Vector2D &obj){
	if(x==obj.x&&y==obj.y){
		return true;
	}
	return false;
}
///=演算子オーバーロード
suken::Vector2D& suken::Vector2D::operator =(const Vector2D &obj) {
	this->x = obj.x;
	this->y = obj.y;

	//*thisを返すことで「A=B」のような記述だけでなく「A=B=C」のような記述にも対応できる
	return *this;
}
//operator*のオーバーロードによりもはや不要な関数
void suken::Vector2D::Multiple(float _num){
	x = x*_num;
	y = y*_num;
}
float suken::Vector2D::GetLength(){
	return sqrt((x*x)+(y*y));
}
