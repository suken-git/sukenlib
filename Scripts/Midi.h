#pragma once
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm")

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
