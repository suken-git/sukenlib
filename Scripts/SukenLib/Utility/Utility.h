#pragma once
#include"../Manager.h"
#include "DxLib.h"
#include <string>

namespace megademo  // http://www.demoscene.jp/?p=1460
{
	struct RGB
	{
	//	RGB(){}

	//	RGB( float r_, float g_, float b_ ) : r(r_),g(g_),b(b_){}

		float r,g,b;	// [0.0f, 1.0f]
	};

}

extern megademo::RGB rgb;

namespace suken{

const int RED = GetColor( 255 , 0 , 0 );///<  @brief 説明
const int GREEN = GetColor( 0 , 255 , 0 );///<  @brief 説明
const int BLUE = GetColor( 0 , 0 , 255 );///<  @brief 説明
const int BLACK = GetColor( 0 , 0 , 0 );///<  @brief 説明
const int WHITE = GetColor( 255 , 255 , 255 );///<  @brief 説明
const int GRAY = GetColor( 128 , 128 , 128 );///<  @brief 説明
const int LIGHTBLUE = GetColor( 128 , 128 , 255 );///<  @brief 説明
const int LIGHTGREEN = GetColor( 128 , 255 , 128 );///<  @brief 説明
const int M_PINK = GetColor( 255 , 128 , 128 );///<  @brief 説明
const int YELLOW = GetColor( 255 , 255 , 0);///<  @brief 説明

const int SHUIRO = GetColor(221,72,39);
const int ORANGE= GetColor(230,121,40);
const int HIIRO= GetColor(199,60,46);
const int KIMIDORI= GetColor(170,204,59);
const int NAVY= GetColor(23,37,64);
const int SCARLET= GetColor(223,84,69);
const int WAKAKUSA= GetColor(187,211,71);
const int KONNIRO= GetColor(29,49,86);
const int KURENAI= GetColor(189,66,90);
const int ROSE= GetColor(220,67,95);
const int AOMIDORI= GetColor(0,163,136);
const int SHIONIRO= GetColor(89,71,140);
const int CYAN= GetColor(0,163,219);
const int SKYBLUE= GetColor(142,209,224);
const int MIIRO= GetColor(5,102,184);
const int SAKURAIRO= GetColor(252,238,235);
const int SAKURA= GetColor(255,234,250);

int RainBow(int time=0);

#define RAINBOW RainBow()

#define RAINBOW_RGB (RainBow(),rgb.r*255),rgb.g*255,rgb.b*255

#define RAINBOW_RGB_TIME(time) (RainBow( time ),rgb.r*255),rgb.g*255,rgb.b*255

int GetColorHSV(int h,int s,int v);

#define HSV_TO_RGB(h,s,v) (GetColorHSV( h , s , v ),rgb.r*255),rgb.g*255rgb.b*255

/**
*	@brief ダイアログを開いて、。
*	マップエディタなどを作るときに便利かも
*	@param  filename 開きたいファイル名を格納した文字列
*	@param filetype 現在無効
* @return true
*/
bool SelectOpenFile(  char* filename ,  char* filetype = "all file(*.*)\0*.*\0\0");
/**
*	@brief ダイアログを開いて、ファイルを保存する。
*	マップエディタなどを作るときに便利かも
*	@param  filename 保存したいファイル名を格納した文字列
*	@param filetype 現在無効
* @return true
*/
bool SaveFile( char* filename , char* filetype =  "all file(*.*)\0*.*\0\0");
/*
原因不明エラーのためコメントアウト
void GetHttpFile(std::string &Buf,std::string Http,unsigned long ReadSize = 65536);
*/



/////FROM NUNULIB
//現在時刻取得関数///////////////////////////////////////////

/**
*	@brief 説明
* @return 戻り値
*/
SYSTEMTIME GetNowSystemTime();  //SYSTEMTIME型で日本時刻を取得

/**
*	@brief 説明
* @return 戻り値
*/
std::string GetNowSystemTimeString();  //string型(00/00/00 00:00:00 000)で現在日本時刻を取得

/**
*	@brief 説明
*	@param value 引数
* @return 戻り値
*/
inline int DrawCenterString(int cx, int y, const TCHAR *String, int color, bool centerY=false)
{ //xを左右の中心にしてDrawStringで文字描画（※yは上下中心ではなく上辺）
    if (centerY){
        return DxLib::DrawString(cx-GetDrawStringWidth(String, strlen(String))/2, y-GetFontSize()/2, String, color);    //あくまで目安 
    }else{
        return DxLib::DrawString(cx-GetDrawStringWidth(String, strlen(String))/2, y, String, color); 
    }
}

/**
*	@brief 説明
*	@param value 引数
* @return 戻り値
*/
int DrawCenterString(int cx, int y, int color, const TCHAR* format, ...);

/**
*	@brief 説明
*	@param value 引数
* @return 戻り値
*/
int DrawCenterString(int cx, int y, int color, bool centerY, const TCHAR* format, ...);

/////////////////////////////////////////////////////////////

//////////////////////////////////////

/**
*	@brief 説明
*	@param value 引数
*/
void AddFontFromPath(std::string path);

/**
*	@brief 説明
*	@param value 引数
*/
void SukenExecute(std::string URL);


/**
*	@brief 説明
*	@param value 引数
* @return 戻り値
*/
unsigned int fanctorial(unsigned int num);			//

/**
*	@brief 説明
*	@param value 引数
* @return 戻り値
*/
unsigned int combination(unsigned int n , unsigned int r);					//nCrとかやるあれ。組み合わせ


}
