#pragma once
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm")

class CMidi{
	
private:
	HMIDIOUT hMidiOut;///<  @brief 説明
/**
*	@brief 説明
*	@param value 引数
* @return 戻り値
*/
	DWORD MIDIMSG(BYTE _status, BYTE _channel, BYTE  _data1, BYTE _data2){
		return (DWORD)((_status << 4) | _channel | (_data1 << 8) | (_data2 << 16));
	}
public:
/**
*	@brief 説明
*/
	CMidi();
/**
*	@brief 説明
*/
	~CMidi();
/**
*	@brief この関数を呼び出すと鳴らすことが出来る
*	BYTE は整数で0~127を受け付けると考えるといい。
*	@param _Height 音の高さ(0~127)
*	@param _Velocity 音の強さ(0~127)

*/
	void Lang(BYTE _Height, BYTE _Velocity, BYTE _channnel);
	
/**
*	@brief その高さの音の再生を止める
*	BYTE は整数で0~127を受け付けると考えるといい。
*	@param _Height 音の高さ(0~127)
*	@param _channel  鳴らすチャンネル、複数の楽器パートを使いたいときに使う
*/
	void Stop(BYTE _Height, BYTE _channnel);
/**
*	@brief 楽器を変える
*	BYTE は整数で0~127を受け付けると考えるといい。
*	@param value 引数
*/
	void ChangeTimble(BYTE _Timble, BYTE _channnel);

};
//例えば MD.Lang(100, 72)でMidiを鳴らせる。
