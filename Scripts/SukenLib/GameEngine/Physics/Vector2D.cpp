#include"Vector2D.h"
#include <Utility/Utility.h>
using namespace suken;
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

//ベジェ曲線

//ベジェ曲線頂点データの作成
////ベジェ曲線の計算をマイフレームするのは無駄なので計算済みのデータを作成する
//引数
// In　　　　: 制御点（Vector2D型）を指定する（2つ以上）
// vertexNum : 作成するデータの細かさを指定（ベジェ曲線の構成頂点の数）
BEZIER GetBezier(std::vector<suken::Vector2D> &In , unsigned int vertexNum ){
	
	const int N = In.size();
	BEZIER vertexes;
	vertexes.push_back(In[0]);
	float t = 0.0f;

	for(unsigned int j = 0; j < vertexNum; j++){

		 t += ( 1.0f / (float)vertexNum ) ;

		suken::Vector2D vertex ;
		
		for( int i = 0; i < N; i++ ){
			
			float temp = (float)( combination( N-1 , i ) * pow( 1-t , N-i-1  ) * pow( t , i ) );

			vertex += In[i] * temp;

		}

		vertexes.push_back(vertex);
	}
	
	return vertexes;
}
//ベジェ曲線の描画（ GetBezier関数で作成したデータが必要　）
////GetBezier関数で作成したデータを用いてベジェ曲線を描画する
//引数
// data  : GetBezier関数で作成したベジェ曲線データ
// color : 描画色を指定
void DrawBezier( BEZIER &data ,  int color ){
	for(unsigned int i = 0; i < data.size() - 1; i++){
		DrawLine( (int)data[ i ].x ,(int)data[ i ].y , (int)data[ i+1 ].x , (int)data[ i+1 ].y , color );
	}
}

