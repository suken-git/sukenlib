#pragma once
#include <vector>
#include "DxLib.h"

namespace suken{


///////////////////////////////////////////////////////////////////////
///二次元座標用クラス（速度などに便利）///////////////////////////////////
///演算子オーバーロードとDxLibのVECTOR用関数と同じように使える関数群も/////
///////////////////////////////////////////////////////////////////////

class Vector2D{  //宣言と同時に定義を書いているのはインライン化するため
public:
/**
*	@brief 説明
*	@param value 引数
*/
    Vector2D( float _x , float _y );
/**
*	@brief 説明
*/
    Vector2D();

    float x;///<  @brief 説明
    float y;///<  @brief 説明
 /**
*	@brief 説明
*	@param value 引数
*/
    void Set( float _x , float _y);
/**
*	@brief 説明
*	@param value 引数
*/
    void Set(Vector2D _vec);
/**
*	@brief 説明
*	@param value 引数
* @return 戻り値
*/
    Vector2D Add( float _x , float _y);
/**
*	@brief 説明
*	@param value 引数
* @return 戻り値
*/
    Vector2D Add(Vector2D _vec);
/**
*	@brief 説明  +演算子オーバーロード
*	@param value 引数
* @return 戻り値
*/    
    Vector2D operator+(const Vector2D &obj);
/**
*	@brief 説明// +=演算子オーバーロード
*	@param value 引数
* @return 戻り値
*/    
    Vector2D& operator+=(const Vector2D &obj);
/**
*	@brief 説明// -演算子オーバーロード
*	@param value 引数
* @return 戻り値
*/   
    Vector2D operator-(const Vector2D &obj);
/**
*	@brief 説明// -=演算子オーバーロード
*	@param value 引数
* @return 戻り値
*/    
    Vector2D& operator-=(const Vector2D &obj);
/**
*	@brief 説明 //*演算子オーバーロード
*	@param value 引数
* @return 戻り値
*/   
    Vector2D operator*(const float _num);
/**
*	@brief 説明//*=演算子オーバーロード
*	@param value 引数
* @return 戻り値
*/    
    Vector2D& operator*=(const float _num);
/**
*	@brief 説明//  /演算子オーバーロード
*	@param value 引数
* @return 戻り値
*/	
    Vector2D operator/(const float _num);
/**
*	@brief 説明///=演算子オーバーロード
*	@param value 引数
* @return 戻り値
*/  
    Vector2D& operator/=(const float _num);
/**
*	@brief 説明///==演算子オーバーロード
*	@param value 引数
* @return 戻り値
*/	
    bool operator==(const Vector2D &obj);

/**
*	@brief 説明///=演算子オーバーロード
*	@param value 引数
* @return 戻り値
*/
	Vector2D& operator =(const Vector2D &obj);
/**
*	@brief 説明//operator*のオーバーロードによりもはや不要な関数
*	@param value 引数
*/
    void Multiple(float _num);
/**
*	@brief 説明
* @return 戻り値
*/
    float GetLength();

private:
};

//////////////////////////////////////////////
//////DxLibのVECTOR用関数のオーバーロード///////
//////////////////////////////////////////////
/**
*	@brief 説明
*	@param value 引数
* @return 戻り値
*/
__inline Vector2D VGet(float _x,float _y){
	Vector2D temp;
	temp.x=_x;
	temp.y=_y;
	return temp;
}
/**
*	@brief 説明
*	@param value 引数
* @return 戻り値
*/
__inline Vector2D VAdd(Vector2D v1,Vector2D v2){
	Vector2D temp;
	temp.x=v1.x+v2.x;
	temp.y=v1.y+v2.y;
	return temp;
}
/**
*	@brief 説明
*	@param value 引数
* @return 戻り値
*/
__inline Vector2D VSub(Vector2D v1,Vector2D v2){
	Vector2D temp;
	temp.x=v1.x-v2.x;
	temp.y=v1.y-v2.y;
	return temp;
}
/**
*	@brief 説明
*	@param value 引数
* @return 戻り値
*/
__inline float VDot(Vector2D v1,Vector2D v2){
	return (v1.x*v2.x+v1.y*v2.y);
}
/**
*	@brief 説明
*	@param value 引数
* @return 戻り値
*/
__inline VECTOR VCross(Vector2D v1,Vector2D v2){
	VECTOR temp;
	temp.z=(float)v1.x*v2.y-v1.y*v2.x;
	return temp;
}
/**
*	@brief 説明
*	@param value 引数
* @return 戻り値
*/
__inline float VCrossLength(Vector2D v1,Vector2D v2){
	return ((v1.x*v2.y)-(v1.y*v2.x));
}
/**
*	@brief 説明
*	@param value 引数
* @return 戻り値
*/
__inline Vector2D VScale(Vector2D v1,float scale){
	Vector2D temp;
	temp.x=v1.x*scale;
	temp.y=v1.y*scale;
	return temp;
}
/**
*	@brief 説明
*	@param value 引数
* @return 戻り値
*/
__inline float VSize(Vector2D v1){
	return sqrt( (float)(v1.x * v1.x + v1.y * v1.y) ) ;
}
/**
*	@brief 説明
*	@param value 引数
* @return 戻り値
*/
__inline float VSquareSize(Vector2D v1){
	return  (v1.x * v1.x + v1.y * v1.y);
}
/**
*	@brief 説明
*	@param value 引数
* @return 戻り値
*/
__inline Vector2D VNorm(Vector2D v1){
	float size=VSize(v1);
	Vector2D temp;
	temp.x=v1.x/size;
	temp.y=v1.y/size;
	return temp;
}
/**
*	@brief 説明
*	@param value 引数
* @return 戻り値
*/
__inline float GetDistance(Vector2D v1 ,Vector2D v2){
	
	return sqrt(pow(abs(v1.x-v2.x),2.0f)+pow(abs(v1.y-v2.y),2.0f));
	
}
/**
*	@brief 説明
*	@param value 引数
* @return 戻り値
*/
__inline float GetSquareDistance(Vector2D v1 ,Vector2D v2){
	
	return pow(abs(v1.x-v2.x),2.0f)+pow(abs(v1.y-v2.y),2.0f);
	
}
/**
*	@brief 説明
*	@param value 引数
* @return 戻り値
*/
__inline int DrawLine(Vector2D &v1 , Vector2D &v2 ,int color){
	return DxLib::DrawLine((int)v1.x,(int)v1.y,(int)v2.x,(int)v2.y,color);
}
/**
*	@brief 説明
*	@param value 引数
* @return 戻り値
*/
__inline int DrawCircle(Vector2D &v,int r,int color,bool fillFlag){
	return DxLib::DrawCircle((int)v.x,(int)v.y,r,color,fillFlag);
}
/**
*	@brief 説明
*	@param value 引数
* @return 戻り値
*/
__inline int DrawBox(suken::Vector2D &v1,suken::Vector2D &v2,int color,bool fillFlag){
	return DxLib::DrawBox((int)v1.x,(int)v1.y,(int)v2.x,(int)v2.y,color,fillFlag);
}
/**
*	@brief 説明
*	@param value 引数
* @return 戻り値
*/
_inline int DrawOval(suken::Vector2D &v,suken::Vector2D &r,int color,bool fillFlag){
	return DxLib::DrawOval((int)v.x,(int)v.y,(int)r.x,(int)r.y,color,fillFlag);
}
/**
*	@brief 説明
*	@param value 引数
* @return 戻り値
*/
_inline int DrawOval(suken::Vector2D &v,int rx,int ry,int color,bool fillFlag){
	return DxLib::DrawOval((int)v.x,(int)v.y,rx,ry,color,fillFlag);
}
/**
*	@brief 説明
*	@param value 引数
* @return 戻り値
*/
_inline int DrawTriangle(suken::Vector2D &v1,suken::Vector2D &v2,suken::Vector2D &v3,int color,bool fillFlag){
	return DxLib::DrawTriangle((int)v1.x,(int)v1.y,(int)v2.x,(int)v2.y,(int)v3.x,(int)v3.y,color,fillFlag);
}
/**
*	@brief 説明
*	@param value 引数
* @return 戻り値
*/
_inline int DrawPixel(suken::Vector2D &v,int color){
	return DxLib::DrawPixel((int)v.x,(int)v.y,color);
}



typedef std::vector<suken::Vector2D> BEZIER ;
//ベジェ曲線の描画（ GetBezier関数で作成したデータが必要　）
////GetBezier関数で作成したデータを用いてベジェ曲線を描画する
//引数
// data  : GetBezier関数で作成したベジェ曲線データ
// color : 描画色を指定
/**
*	@brief 説明
*	@param value 引数
*/
void DrawBezier( BEZIER &data ,  int color );
//ベジェ曲線頂点データの作成
////ベジェ曲線の計算をマイフレームするのは無駄なので計算済みのデータを作成する
//引数
// In　　　　: 制御点（suken::Vector2D型）を指定する（2つ以上）
// vertexNum : 作成するデータの細かさを指定（ベジェ曲線の構成頂点の数）
/**
*	@brief 説明
*	@param value 引数
* @return 戻り値
*/
BEZIER GetBezier(std::vector<suken::Vector2D> &In , unsigned int vertexNum );

}//namespace suken end

