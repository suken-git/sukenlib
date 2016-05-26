#include "Midi.h"

CMidi::CMidi(){
	//Midi���J��
	midiOutOpen(&hMidiOut, MIDI_MAPPER, 0, 0, 0);
}
CMidi::~CMidi(){
	//Midi�����
	midiOutReset(hMidiOut);                 //�S�`�����l�����m�[�g�I�t											
	midiOutClose(hMidiOut);                 // MIDI�o�̓f�o�C�X�����
}
//���̊֐����Ăяo���Ɩ炷���Ƃ��o����
//BYTE �͐�����0~127���󂯕t����ƍl����Ƃ����B
//_Height�͉��̍���(0~127)
//_Velocity�͉��̋���(0~127)
//_channel �͖炷�`�����l���A�����̊y��p�[�g���g�������Ƃ��Ɏg��
void CMidi::Lang(BYTE _Height, BYTE _Velocity, BYTE _channnel = 0x0){
	if (_Height < 0)_Height = 0; if (_Height > 0x7f)_Height = 0x7f;
	if (_Velocity < 0)_Velocity = 0; if (_Velocity > 0x7f)_Velocity = 0x7f;
	midiOutShortMsg(hMidiOut, MIDIMSG(0x9, _channnel, _Height, _Velocity)); //0x3c(C3�h) 0x3D(�h#)
}
//���̍����̉��̍Đ����~�߂�
void CMidi::Stop(BYTE _Height, BYTE _channnel = 0x0){
	midiOutShortMsg(hMidiOut, MIDIMSG(0x9, _channnel, _Height, 0));
}
//�y���ς���
void CMidi::ChangeTimble(BYTE _Timble, BYTE _channnel = 0x0){
	if (_Timble < 0)_Timble = 0; if (_Timble > 0x7f)_Timble = 0x7f;
	midiOutShortMsg(hMidiOut, MIDIMSG(0xc, _channnel, _Timble, 0));
}
