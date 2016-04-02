#pragma once
#include "DxLib.h"
#include <string>


#define RED GetColor( 255 , 0 , 0 )
#define GREEN GetColor( 0 , 255 , 0 )
#define BLUE GetColor( 0 , 0 , 255 )
#define BLACK GetColor( 0 , 0 , 0 )
#define WHITE GetColor( 255 , 255 , 255 )
#define GRAY GetColor( 128 , 128 , 128 )
#define LIGHTBLUE GetColor( 128 , 128 , 255 )
#define LIGHTGREEN GetColor( 128 , 255 , 128 )
#define M_PINK GetColor( 255 , 128 , 128 )
#define YELLOW GetColor( 255 , 255 , 0)








/**
*	@brief ダイアログを開いて、。
*	マップエディタなどを作るときに便利かも
*	@param  filename 開きたいファイル名を格納した文字列
*	@param filetype 現在無効
* @return true
*/
bool SelectOpenFile( char *filename , char *filetype = "all file(*.*)\0*.*\0\0");
/**
*	@brief ダイアログを開いて、ファイルを保存する。
*	マップエディタなどを作るときに便利かも
*	@param  filename 保存したいファイル名を格納した文字列
*	@param filetype 現在無効
* @return true
*/
bool SaveFile(char *filename ,char *filetype =  "all file(*.*)\0*.*\0\0");
/*
原因不明エラーのためコメントアウト
void GetHttpFile(char *&Buf,char *Http,unsigned long ReadSize = 65536);
*/



/////FROM NUNULIB
//現在時刻取得関数///////////////////////////////////////////
SYSTEMTIME GetNowSystemTime();  //SYSTEMTIME型で日本時刻を取得
std::string GetNowSystemTimeString();  //string型(00/00/00 00:00:00 000)で現在日本時刻を取得

inline int DrawCenterString(int cx, int y, const TCHAR *String, int color, bool centerY=false){ //xを左右の中心にしてDrawStringで文字描画（※yは上下中心ではなく上辺）
    if (centerY){
        return DxLib::DrawString(cx-GetDrawStringWidth(String, strlen(String))/2, y-GetFontSize()/2, String, color);    //あくまで目安 
    }else{
        return DxLib::DrawString(cx-GetDrawStringWidth(String, strlen(String))/2, y, String, color); 
    }
}
int DrawCenterString(int cx, int y, int color, const TCHAR* format, ...);
int DrawCenterString(int cx, int y, int color, bool centerY, const TCHAR* format, ...);

/////////////////////////////////////////////////////////////

//////////////////////////////////////

void AddFontFromPath(char *path);


void SukenExecute(char *URL);

unsigned int fanctorial(unsigned int num);			//
unsigned int combination(unsigned int n , unsigned int r);					//nCrとかやるあれ。組み合わせ

