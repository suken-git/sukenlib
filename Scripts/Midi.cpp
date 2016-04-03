#include "Midi.h"

CMidi::CMidi(){
	//Midiを開く
	midiOutOpen(&hMidiOut, MIDI_MAPPER, 0, 0, 0);
}
CMidi::~CMidi(){
	//Midiを閉じる
	midiOutReset(hMidiOut);                 //全チャンネルをノートオフ											
	midiOutClose(hMidiOut);                 // MIDI出力デバイスを閉じる
}
//この関数を呼び出すと鳴らすことが出来る
//BYTE は整数で0~127を受け付けると考えるといい。
//_Heightは音の高さ(0~127)
//_Velocityは音の強さ(0~127)
//_channel は鳴らすチャンネル、複数の楽器パートを使いたいときに使う
void CMidi::Lang(BYTE _Height, BYTE _Velocity, BYTE _channnel = 0x0){
	if (_Height < 0)_Height = 0; if (_Height > 0x7f)_Height = 0x7f;
	if (_Velocity < 0)_Velocity = 0; if (_Velocity > 0x7f)_Velocity = 0x7f;
	midiOutShortMsg(hMidiOut, MIDIMSG(0x9, _channnel, _Height, _Velocity)); //0x3c(C3ド) 0x3D(ド#)
}
//その高さの音の再生を止める
void CMidi::Stop(BYTE _Height, BYTE _channnel = 0x0){
	midiOutShortMsg(hMidiOut, MIDIMSG(0x9, _channnel, _Height, 0));
}
//楽器を変える
void CMidi::ChangeTimble(BYTE _Timble, BYTE _channnel = 0x0){
	if (_Timble < 0)_Timble = 0; if (_Timble > 0x7f)_Timble = 0x7f;
	midiOutShortMsg(hMidiOut, MIDIMSG(0xc, _channnel, _Timble, 0));
}
