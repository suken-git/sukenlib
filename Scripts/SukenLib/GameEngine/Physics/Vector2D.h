#pragma once
#include <vector>
#include "DxLib.h"

namespace suken{


///////////////////////////////////////////////////////////////////////
///�񎟌����W�p�N���X�i���x�Ȃǂɕ֗��j///////////////////////////////////
///���Z�q�I�[�o�[���[�h��DxLib��VECTOR�p�֐��Ɠ����悤�Ɏg����֐��Q��/////
///////////////////////////////////////////////////////////////////////

class Vector2D{  //�錾�Ɠ����ɒ�`�������Ă���̂̓C�����C�������邽��
public:
/**
*	@brief ����
*	@param value ����
*/
    Vector2D( float _x , float _y );
/**
*	@brief ����
*/
    Vector2D();

    float x;///<  @brief ����
    float y;///<  @brief ����
 /**
*	@brief ����
*	@param value ����
*/
    void Set( float _x , float _y);
/**
*	@brief ����
*	@param value ����
*/
    void Set(Vector2D _vec);
/**
*	@brief ����
*	@param value ����
* @return �߂�l
*/
    Vector2D Add( float _x , float _y);
/**
*	@brief ����
*	@param value ����
* @return �߂�l
*/
    Vector2D Add(Vector2D _vec);
/**
*	@brief ����  +���Z�q�I�[�o�[���[�h
*	@param value ����
* @return �߂�l
*/    
    Vector2D operator+(const Vector2D &obj);
/**
*	@brief ����// +=���Z�q�I�[�o�[���[�h
*	@param value ����
* @return �߂�l
*/    
    Vector2D& operator+=(const Vector2D &obj);
/**
*	@brief ����// -���Z�q�I�[�o�[���[�h
*	@param value ����
* @return �߂�l
*/   
    Vector2D operator-(const Vector2D &obj);
/**
*	@brief ����// -=���Z�q�I�[�o�[���[�h
*	@param value ����
* @return �߂�l
*/    
    Vector2D& operator-=(const Vector2D &obj);
/**
*	@brief ���� //*���Z�q�I�[�o�[���[�h
*	@param value ����
* @return �߂�l
*/   
    Vector2D operator*(const float _num);
/**
*	@brief ����//*=���Z�q�I�[�o�[���[�h
*	@param value ����
* @return �߂�l
*/    
    Vector2D& operator*=(const float _num);
/**
*	@brief ����//  /���Z�q�I�[�o�[���[�h
*	@param value ����
* @return �߂�l
*/	
    Vector2D operator/(const float _num);
/**
*	@brief ����///=���Z�q�I�[�o�[���[�h
*	@param value ����
* @return �߂�l
*/  
    Vector2D& operator/=(const float _num);
/**
*	@brief ����///==���Z�q�I�[�o�[���[�h
*	@param value ����
* @return �߂�l
*/	
    bool operator==(const Vector2D &obj);

/**
*	@brief ����///=���Z�q�I�[�o�[���[�h
*	@param value ����
* @return �߂�l
*/
	Vector2D& operator =(const Vector2D &obj);
/**
*	@brief ����//operator*�̃I�[�o�[���[�h�ɂ����͂�s�v�Ȋ֐�
*	@param value ����
*/
    void Multiple(float _num);
/**
*	@brief ����
* @return �߂�l
*/
    float GetLength();

private:
};

//////////////////////////////////////////////
//////DxLib��VECTOR�p�֐��̃I�[�o�[���[�h///////
//////////////////////////////////////////////
/**
*	@brief ����
*	@param value ����
* @return �߂�l
*/
__inline Vector2D VGet(float _x,float _y)
{
	Vector2D temp;
	temp.x=_x;
	temp.y=_y;
	return temp;
}
/**
*	@brief ����
*	@param value ����
* @return �߂�l
*/
__inline Vector2D VAdd(Vector2D v1,Vector2D v2)
{
	Vector2D temp;
	temp.x=v1.x+v2.x;
	temp.y=v1.y+v2.y;
	return temp;
}
/**
*	@brief ����
*	@param value ����
* @return �߂�l
*/
__inline Vector2D VSub(Vector2D v1,Vector2D v2)
{
	Vector2D temp;
	temp.x=v1.x-v2.x;
	temp.y=v1.y-v2.y;
	return temp;
}
/**
*	@brief ����
*	@param value ����
* @return �߂�l
*/
__inline float VDot(Vector2D v1,Vector2D v2)
{
	return (v1.x*v2.x+v1.y*v2.y);
}
/**
*	@brief ����
*	@param value ����
* @return �߂�l
*/
__inline VECTOR VCross(Vector2D v1,Vector2D v2)
{
	VECTOR temp;
	temp.z=(float)v1.x*v2.y-v1.y*v2.x;
	return temp;
}
/**
*	@brief ����
*	@param value ����
* @return �߂�l
*/
__inline float VCrossLength(Vector2D v1,Vector2D v2)
{
	return ((v1.x*v2.y)-(v1.y*v2.x));
}
/**
*	@brief ����
*	@param value ����
* @return �߂�l
*/
__inline Vector2D VScale(Vector2D v1,float scale)
{
	Vector2D temp;
	temp.x=v1.x*scale;
	temp.y=v1.y*scale;
	return temp;
}
/**
*	@brief ����
*	@param value ����
* @return �߂�l
*/
__inline float VSize(Vector2D v1)
{
	return sqrt( (float)(v1.x * v1.x + v1.y * v1.y) ) ;
}
/**
*	@brief ����
*	@param value ����
* @return �߂�l
*/
__inline float VSquareSize(Vector2D v1)
{
	return  (v1.x * v1.x + v1.y * v1.y);
}
/**
*	@brief ����
*	@param value ����
* @return �߂�l
*/
__inline Vector2D VNorm(Vector2D v1)
{
	float size=VSize(v1);
	Vector2D temp;
	temp.x=v1.x/size;
	temp.y=v1.y/size;
	return temp;
}
/**
*	@brief ����
*	@param value ����
* @return �߂�l
*/
__inline float GetDistance(Vector2D v1 ,Vector2D v2)
{
	
	return sqrt(pow(abs(v1.x-v2.x),2.0f)+pow(abs(v1.y-v2.y),2.0f));
	
}
/**
*	@brief ����
*	@param value ����
* @return �߂�l
*/
__inline float GetSquareDistance(Vector2D v1 ,Vector2D v2)
{
	
	return pow(abs(v1.x-v2.x),2.0f)+pow(abs(v1.y-v2.y),2.0f);
	
}
/**
*	@brief ����
*	@param value ����
* @return �߂�l
*/
__inline int DrawLine(Vector2D &v1 , Vector2D &v2 ,int color)
{
	return DxLib::DrawLine((int)v1.x,(int)v1.y,(int)v2.x,(int)v2.y,color);
}
/**
*	@brief ����
*	@param value ����
* @return �߂�l
*/
__inline int DrawCircle(Vector2D &v,int r,int color,bool fillFlag)
{
	return DxLib::DrawCircle((int)v.x,(int)v.y,r,color,fillFlag);
}
/**
*	@brief ����
*	@param value ����
* @return �߂�l
*/
__inline int DrawBox(suken::Vector2D &v1,suken::Vector2D &v2,int color,bool fillFlag)
{
	return DxLib::DrawBox((int)v1.x,(int)v1.y,(int)v2.x,(int)v2.y,color,fillFlag);
}
/**
*	@brief ����
*	@param value ����
* @return �߂�l
*/
_inline int DrawOval(suken::Vector2D &v,suken::Vector2D &r,int color,bool fillFlag)
{
	return DxLib::DrawOval((int)v.x,(int)v.y,(int)r.x,(int)r.y,color,fillFlag);
}
/**
*	@brief ����
*	@param value ����
* @return �߂�l
*/
_inline int DrawOval(suken::Vector2D &v,int rx,int ry,int color,bool fillFlag)
{
	return DxLib::DrawOval((int)v.x,(int)v.y,rx,ry,color,fillFlag);
}
/**
*	@brief ����
*	@param value ����
* @return �߂�l
*/
_inline int DrawTriangle(suken::Vector2D &v1,suken::Vector2D &v2,suken::Vector2D &v3,int color,bool fillFlag)
{
	return DxLib::DrawTriangle((int)v1.x,(int)v1.y,(int)v2.x,(int)v2.y,(int)v3.x,(int)v3.y,color,fillFlag);
}
/**
*	@brief ����
*	@param value ����
* @return �߂�l
*/
_inline int DrawPixel(suken::Vector2D &v,int color)
{
	return DxLib::DrawPixel((int)v.x,(int)v.y,color);
}



typedef std::vector<suken::Vector2D> BEZIER ;
//�x�W�F�Ȑ��̕`��i GetBezier�֐��ō쐬�����f�[�^���K�v�@�j
////GetBezier�֐��ō쐬�����f�[�^��p���ăx�W�F�Ȑ���`�悷��
//����
// data  : GetBezier�֐��ō쐬�����x�W�F�Ȑ��f�[�^
// color : �`��F���w��
/**
*	@brief ����
*	@param value ����
*/
void DrawBezier( BEZIER &data ,  int color );
//�x�W�F�Ȑ����_�f�[�^�̍쐬
////�x�W�F�Ȑ��̌v�Z���}�C�t���[������͖̂��ʂȂ̂Ōv�Z�ς݂̃f�[�^���쐬����
//����
// In�@�@�@�@: ����_�isuken::Vector2D�^�j���w�肷��i2�ȏ�j
// vertexNum : �쐬����f�[�^�ׂ̍������w��i�x�W�F�Ȑ��̍\�����_�̐��j
/**
*	@brief ����
*	@param value ����
* @return �߂�l
*/
BEZIER GetBezier(std::vector<suken::Vector2D> &In , unsigned int vertexNum );

}//namespace suken end

