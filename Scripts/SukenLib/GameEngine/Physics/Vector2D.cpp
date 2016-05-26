#include"Vector2D.h"
#include <Utility/Utility.h>
using namespace suken;
suken::Vector2D::Vector2D( float _x , float _y )
{
	x = _x;
	y = _y;
    }
suken::Vector2D::Vector2D()
{
	x = 0.0f;
	y = 0.0f;
}
void suken::Vector2D::Set( float _x , float _y)
{
	x = _x;
	y = _y;
    }
void suken::Vector2D::Set(Vector2D _vec)
{
	x = _vec.x;
	y = _vec.y;
}     
suken::Vector2D suken::Vector2D::Add( float _x , float _y)
{
	x += _x;
	y += _y;
	return *this;
}
suken::Vector2D suken::Vector2D::Add(Vector2D _vec)
{
	x += _vec.x;
	y += _vec.y;
        
	return *this;
}
// +���Z�q�I�[�o�[���[�h
suken::Vector2D suken::Vector2D::operator+(const Vector2D &obj)
{
	Vector2D tmp;
	tmp.x = x + obj.x;
	tmp.y = y + obj.y;
	return tmp;
}
// +=���Z�q�I�[�o�[���[�h
suken::Vector2D& suken::Vector2D::operator+=(const Vector2D &obj)
{
	x += obj.x;
	y += obj.y;
	return *this;
}    
// -���Z�q�I�[�o�[���[�h
suken::Vector2D suken::Vector2D::operator-(const Vector2D &obj)
{
	Vector2D tmp;
	tmp.x = x - obj.x;
	tmp.y = y - obj.y;
	return tmp;
}
// -=���Z�q�I�[�o�[���[�h
suken::Vector2D& suken::Vector2D::operator-=(const Vector2D &obj)
{
	x -= obj.x;
	y -= obj.y;
	return *this;
}
//*���Z�q�I�[�o�[���[�h
suken::Vector2D suken::Vector2D::operator*(const float _num)
{
	Vector2D tmp;
	tmp.x = x * _num;
	tmp.y = y * _num;
	return tmp;
}
//*=���Z�q�I�[�o�[���[�h
suken::Vector2D& suken::Vector2D::operator*=(const float _num)
{
	x*=_num;
	y*=_num;
	return *this;
}
//  /���Z�q�I�[�o�[���[�h
suken::Vector2D suken::Vector2D::operator/(const float _num)
{
	Vector2D tmp;
	tmp.x = x / _num;
	tmp.y = y / _num;
	return tmp;
}
///=���Z�q�I�[�o�[���[�h
suken::Vector2D& suken::Vector2D::operator/=(const float _num)
{
	x/=_num;
	y/=_num;
	return *this;
}
///==���Z�q�I�[�o�[���[�h
bool suken::Vector2D::operator==(const Vector2D &obj)
{
	if(x==obj.x&&y==obj.y)
{
		return true;
	}
	return false;
}
///=���Z�q�I�[�o�[���[�h
suken::Vector2D& suken::Vector2D::operator =(const Vector2D &obj) 
{
	this->x = obj.x;
	this->y = obj.y;

	//*this��Ԃ����ƂŁuA=B�v�̂悤�ȋL�q�����łȂ��uA=B=C�v�̂悤�ȋL�q�ɂ��Ή��ł���
	return *this;
}
//operator*�̃I�[�o�[���[�h�ɂ����͂�s�v�Ȋ֐�
void suken::Vector2D::Multiple(float _num)
{
	x = x*_num;
	y = y*_num;
}
float suken::Vector2D::GetLength()
{
	return sqrt((x*x)+(y*y));
}

//�x�W�F�Ȑ�

//�x�W�F�Ȑ����_�f�[�^�̍쐬
////�x�W�F�Ȑ��̌v�Z���}�C�t���[������͖̂��ʂȂ̂Ōv�Z�ς݂̃f�[�^���쐬����
//����
// In�@�@�@�@: ����_�iVector2D�^�j���w�肷��i2�ȏ�j
// vertexNum : �쐬����f�[�^�ׂ̍������w��i�x�W�F�Ȑ��̍\�����_�̐��j
BEZIER GetBezier(std::vector<suken::Vector2D> &In , unsigned int vertexNum )
{
	
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
//�x�W�F�Ȑ��̕`��i GetBezier�֐��ō쐬�����f�[�^���K�v�@�j
////GetBezier�֐��ō쐬�����f�[�^��p���ăx�W�F�Ȑ���`�悷��
//����
// data  : GetBezier�֐��ō쐬�����x�W�F�Ȑ��f�[�^
// color : �`��F���w��
void DrawBezier( BEZIER &data ,  int color )
{
	for(unsigned int i = 0; i < data.size() - 1; i++){
		DrawLine( (int)data[ i ].x ,(int)data[ i ].y , (int)data[ i+1 ].x , (int)data[ i+1 ].y , color );
	}
}

