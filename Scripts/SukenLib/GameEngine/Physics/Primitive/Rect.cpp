#include"Rect.h"
#include <Utility\Utility.h>
#define _USE_MATH_DEFINES
#include "math.h"

suken::CRect::CRect()
{
	direction=0.0f;
	Set(1,1);
}
void suken::CRect::Set(int sizeX,int sizeY)
{
	size = VGet((float)sizeX,(float)sizeY);
	rad = atan2(size.y,size.x);
	radius = ( size.GetLength() / 2.0f );
}
suken::Vector2D suken::CRect::GetCenterPos()
{
	return center.position;						
}
suken::Vector2D suken::CRect::GetSize()
{			
	return size;								
}
float suken::CRect::GetArea()
{			
	return ( size.x * size.y );					
}
suken::Vector2D suken::CRect::GetRightTop()
{				
	return ( center.position + VScale(VGet((float)cos(direction+rad),(float)sin(direction+rad)),radius) );	
}
suken::Vector2D suken::CRect::GetLeftTop()
{				
	return ( center.position + VScale(VGet((float)cos(direction-rad),(float)sin(direction-rad)),radius) );	
}
suken::Vector2D suken::CRect::GetLeftBottom()
{		
	return ( center.position + VScale(VGet((float)cos(direction-M_PI+rad),(float)sin(direction-M_PI+rad)),radius) );	
}
suken::Vector2D suken::CRect::GetRightBottom()
{				
	return ( center.position + VScale(VGet((float)cos(direction+M_PI-rad),(float)sin(direction+M_PI-rad)),radius) );	
}
void suken::CRect::Draw(int color)
{
	DrawLine(GetLeftTop(),GetRightTop(),RED);
	DrawLine(GetRightTop(),GetRightBottom(),BLUE);
	DrawLine(GetRightBottom(),GetLeftBottom(),GREEN);
	DrawLine(GetLeftBottom(),GetLeftTop(),WHITE);
}
void suken::CRect::Loop()
{

	center.Loop();
#ifdef DEBUG_DRAW
	Draw(WHITE);
		
#endif
}
float suken::CRect::GetRadius()
{
	return radius;
}


