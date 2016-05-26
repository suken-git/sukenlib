#pragma once
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm")

class CMidi{
	
private:
	HMIDIOUT hMidiOut;///<  @brief ����
/**
*	@brief ����
*	@param value ����
* @return �߂�l
*/
	DWORD MIDIMSG(BYTE _status, BYTE _channel, BYTE  _data1, BYTE _data2){
		return (DWORD)((_status << 4) | _channel | (_data1 << 8) | (_data2 << 16));
	}
public:
/**
*	@brief ����
*/
	CMidi();
/**
*	@brief ����
*/
	~CMidi();
/**
*	@brief ���̊֐����Ăяo���Ɩ炷���Ƃ��o����
*	BYTE �͐�����0~127���󂯕t����ƍl����Ƃ����B
*	@param _Height ���̍���(0~127)
*	@param _Velocity ���̋���(0~127)

*/
	void Lang(BYTE _Height, BYTE _Velocity, BYTE _channnel);
	
/**
*	@brief ���̍����̉��̍Đ����~�߂�
*	BYTE �͐�����0~127���󂯕t����ƍl����Ƃ����B
*	@param _Height ���̍���(0~127)
*	@param _channel  �炷�`�����l���A�����̊y��p�[�g���g�������Ƃ��Ɏg��
*/
	void Stop(BYTE _Height, BYTE _channnel);
/**
*	@brief �y���ς���
*	BYTE �͐�����0~127���󂯕t����ƍl����Ƃ����B
*	@param value ����
*/
	void ChangeTimble(BYTE _Timble, BYTE _channnel);

};
//�Ⴆ�� MD.Lang(100, 72)��Midi��点��B
