#pragma once
#include"../Manager.h"
#include "DxLib.h"
#include <string>

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
