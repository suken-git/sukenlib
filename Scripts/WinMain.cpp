#include"Suken.h"
#include<windows.h>
using namespace suken;




int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInst, LPSTR lpszCmdLine, int nCmdShow){

	
	//////////////////////////////////////////////////////////////////////////////////////////
	

	//�����ݒ�@��������//////////////////////////////////////////////
	
	DxLib::SetWindowStyleMode(0) ;/*�O�F���܂łǂ���̕��ʂ̃E�C���h�E �P�F�^�C�g���o�[�Ȃ��A������ �Q�F�^�C�g���o�[�������Ȃ�*/
	DxLib::SetMainWindowText("SukenLib");
	System.SetWindowSize(900,600);							//�E�C���h�E�T�C�Y��ݒ�
	System.SetTargetFps(60.0);								//�ڕW�̃t���[�����[�g��ݒ�
	System.SetLoadingGraph("SukenLibAsset/LOGO/LOGO.png");	//���[�f�B���O��ʂɕ\������摜�̃A�h���X���w��
	System.SetUseThread_Awake(false);						//void Awake()�̎��s���o�b�N�O���E���h�ōs�����ǂ���
	System.SetLoadingMinimalTime(0);						//Loading��ʂ̍Œ�\�����Ԃ��~���b�Őݒ�
	//�����ݒ�@�����܂�//////////////////////////////////////////////
	System.Awake();
	debug.Awake(hInstance,hPreInst,nCmdShow);

	mce.Awake("MCE/");										//mce�t�@�C���̑��݂���ꏊ��o�^

	///////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////
	
	if(System.GetUseThread_Awake()){
		System.CreateNewThread(Awake);
	}else{
		Awake();
	}
	System.Wait_Loading();

	while(!ProcessMessage() &&!System.GetEscapeFlag()){
		ScreenFlip();
		ClearDrawScreen();
		System.Update();
		GameLoopEnter();
		Game.Loop();
		GameLoopExit();
		Game.ExecuteCommand();
		System.ExitFrame();
		debug.Loop();
		System.Wait();
	}
        
	System.End();
	return 0;
} 



