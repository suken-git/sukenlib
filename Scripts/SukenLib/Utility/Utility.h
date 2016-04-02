#pragma once
#include"Manager.h"
#include"../Utility/Utility.h"
#include"../GameEngine/Physics/Vector2D.h"
#include "wininet.h"


//セーフカラーについて
//0、51、102、153、204、255の6段階のRGBで計216使えます。

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
extern bool SelectOpenFile( char *filename , char *filetype = "all file(*.*)\0*.*\0\0");
/**
*	@brief ダイアログを開いて、ファイルを保存する。
*	マップエディタなどを作るときに便利かも
*	@param  filename 保存したいファイル名を格納した文字列
*	@param filetype 現在無効
* @return true
*/
extern bool SaveFile(char *filename ,char *filetype =  "all file(*.*)\0*.*\0\0");
/*
原因不明エラーのためコメントアウト
void GetHttpFile(char *&Buf,char *Http,unsigned long ReadSize = 65536);
*/
class CMidi{
	
private:
	HMIDIOUT hMidiOut;
	DWORD MIDIMSG(BYTE _status, BYTE _channel, BYTE  _data1, BYTE _data2){
		return (DWORD)((_status << 4) | _channel | (_data1 << 8) | (_data2 << 16));
	}
public:
	CMidi();
	~CMidi();
	//この関数を呼び出すと鳴らすことが出来る
	//BYTE は整数で0~127を受け付けると考えるといい。
	//_Heightは音の高さ(0~127)
	//_Velocityは音の強さ(0~127)
	//_channel は鳴らすチャンネル、複数の楽器パートを使いたいときに使う
	void Lang(BYTE _Height, BYTE _Velocity, BYTE _channnel);
	//その高さの音の再生を止める
	void Stop(BYTE _Height, BYTE _channnel);
	//楽器を変える
	void ChangeTimble(BYTE _Timble, BYTE _channnel);

};
//例えば MD.Lang(100, 72)でMidiを鳴らせる。



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

typedef vector<suken::Vector2D> BEZIER ;
//ベジェ曲線の描画（ GetBezier関数で作成したデータが必要　）
////GetBezier関数で作成したデータを用いてベジェ曲線を描画する
//引数
// data  : GetBezier関数で作成したベジェ曲線データ
// color : 描画色を指定
void DrawBezier( BEZIER &data ,  int color );
	//ベジェ曲線頂点データの作成
////ベジェ曲線の計算をマイフレームするのは無駄なので計算済みのデータを作成する
//引数
// In　　　　: 制御点（suken::Vector2D型）を指定する（2つ以上）
// vertexNum : 作成するデータの細かさを指定（ベジェ曲線の構成頂点の数）
BEZIER GetBezier(vector<suken::Vector2D> &In , unsigned int vertexNum );
