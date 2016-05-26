#pragma once
#include <vector>
#include "DxLib.h"
#include <Manager.h>

namespace suken{

class CSystem{
public:
/**
*	@brief �R���X�g���N�^�@�����o�ϐ��Ȃǂ̏��������s��
*/
	CSystem();
/**
*	@brief �f�X�g���N�^�@DxLib�̌�Еt����
*/
	~CSystem();
/**
*	@brief DxLib�̏������A�����ݒ�Ȃǂ�S��
*/
	void Awake();
/**
*	@brief exe�������オ���Ă���̎��Ԃ��}�C�N���b�ŕԂ�
* @return exe�������オ���Ă���̎���[�}�C�N���b]
*/
	int  GetLocalStandardTime();
/**
*	@brief void Awake()���o�b�N�O���E���h�Ŏ��s���邩�ǂ�����ݒ�
*	@param flag true:void Awake()���o�b�N�O���E���h�Ŏ��s���� false:�ʏ�ʂ�i�����l�j
*/
	void SetUseThread_Awake(bool flag);
/**
*	@brief void Awake()���o�b�N�O���E���h�Ŏ��s���邩�ǂ������擾
* @return true:void Awake()���o�b�N�O���E���h�Ŏ��s���� false:�ʏ�ʂ�i�����l�j
*/
	bool GetUseThread_Awake();
/**
*	@brief ���[�f�B���O���ɕ\������摜���w�肷��
*	@param path �摜�̃p�X 
*/
	void SetLoadingGraph(const std::string path);
/**
*	@brief ���[�f�B���O�̍Œ᎞�Ԃ��}�C�N���b�Őݒ�
*	@param time ���[�f�B���O�̍Œ᎞��[�}�C�N���b] 
*/
	void SetLoadingMinimalTime(int time);
/**
*	@brief �V�X�e���p�֐�
*/
	void Wait_Loading();
/**
*	@brief �V�X�e���p�֐�
*/
	void Update();
/**
*	@�V�X�e���p�֐�
*/
	void Wait();
/**
*	@brief �V�X�e���p�֐�
*/
	void End();
/**
*	@brief �X�N���[���V���b�g������͂��̊֐��i�������j
*/
	void TakeScreenShot();
/**
*	@brief �X�N���[���V���b�g������͂��̊֐��i�������j
*	@param  GrHandleAdress�@�X�N���[���V���b�g�̉摜�n���h�����i�[�������int�^�|�C���^
*/
	void GetScreenShot(int *GrHandleAdress);
/**
*	@brief ���̊֐������s���邱�Ƃ�exe���I������
*/
	void Escape();
/**
*	@brief exe���I�����邩�ǂ����𓾂�i�V�X�e���֐��j
* @return true:exe�����t���[���ŏI������@false:exe���s��
*/
	bool GetEscapeFlag();
/**
*	@brief exe�������オ���Ă���̃t���[�������擾
* @return exe�������オ���Ă���̃t���[����
*/
	int GetFrame();
/**
*	@brief ���t���[���̎n�܂������Ԃ��}�C�N���b�Ŏ擾�i�t���[�����Ŏ��Ԃ𓝈ꂵ�����Ƃ��ɃI�X�X���j
* @return ���t���[���̎n�܂�������[�}�C�N���b]
*/
	int GetNow();
/**
*	@brief ���݂̃t���[�����[�g���擾�i60�t���[���ɂP��X�V�j
* @return �t���[�����[�g
*/
	float GetFps();
/**
*	@brief �g�p���̃f�B�X�v���C�̍X�V���P�b�Ԃɉ���s���邩���擾
* @return �f�B�X�v���C�̃��t���b�V�����[�g
*/
	int GetRefreshRate();
/**
*	@brief ���z�ƂȂ�t���[�����[�g���w�肷��i�������d���ꍇ��A�w�肵���t���[�����[�g���f�B�X�v���C�̍X�V�p�x��荂���ꍇ�͎w�肵���t���[�����[�g���x���Ȃ�܂��j
*	@param _fps�@���z�̃t���[�����[�g
*/
	void SetTargetFps(float _fps);
/**
*	@brief ���z�ƂȂ�t���[�����[�g���擾����
*	@param value ����
* @return �߂�l
*/
	float GetTargetFps();
/**
*	@brief �V�����X���b�h�����iexe�I�����ɐ���ɉ������܂��j
*	@param pFunc �쐬�����X���b�h�Ŏ��s�����֐��̃|�C���^ 
*/
	void CreateNewThread( void(*pFunc)() );
/**
*	@brief �f�B�X�v���C�̃f�o�C�X�R���e�N�X�g���擾�i�V�X�e���֐��j
* @return �f�B�X�v���C�̃f�o�C�X�R���e�N�X�g
*/
	HDC GetDisplayDC();
#ifdef USE_LUA
/**
*	@brief ������
* @return 
*/
	lua_State* GetLua();
#endif
/**
*	@brief �E�C���h�E�̑傫����ݒ�iWinMain.h�̏����ݒ藓�Ŏg�p����j
*	@param width �E�C���h�E��
*	@param height �E�C���h�E����
*/
	void SetWindowSize( int width , int height );
/**
*	@brief �E�C���h�E�̕��𓾂�
*	@return �E�C���h�E�̕�
*/
	int GetWindowX();
/**
*	@brief �E�C���h�E�̍����𓾂�
*	@return �E�C���h�E�̍���
*/
	int GetWindowY();
private:
	int window_w;///<  @brief	�E�C���h�E��
	int window_h;///<  @brief	�E�C���h�E����
	HDC display ;///<  @brief �f�B�X�v���C�f�o�C�X�R���e�N�X�g���i�[
	int frame;///<  @brief exe�J�n������̃t���[�������i�[
	int count;///<  @brief �t���[�����[�g�Z�o�p�ϐ�
	int startTime;///<  @brief �t���[�����[�g�Z�o�p�ϐ�
	int localStandardTime;///<  @brief exe�J�n������̎��Ԃ��}�C�N���b�Ŋi�[
	int N;		///<  @brief �t���[�����[�g�Z�o�p�ϐ� (N�t���[���Ɉ��fps���Z�o����)
	float fps;///<  @brief �t���[�����[�g���i�[
	float targetFps;///<  @brief ���z�Ƃ���t���[�����[�g���i�[�i�����l�F�U�O�j
	int now;///<  @brief ���t���[�����n�܂������Ԃ��i�[
	int refreshRate;///<  @brief �g�p���̃f�B�X�v���C�̂P�b�Ԃ̍X�V�񐔂��i�[
	std::vector<HANDLE> handleChild;///<  @brief �쐬�����X���b�h�̃n���h�����i�[
	bool escapeFlag;///<  @brief exe���I�����邩�ǂ����̃t���O
	int screenShot;///<  @brief �X�N���[���V���b�g�̉摜�n���h�����i�[���邽�߂̓��ꕨ
	bool screenShotFlag;///<  @brief ���t���[���̃X�N���[���V���b�g���Ƃ邩�ǂ���
	int *screenShotGrHandleAdress;///<  @brief �X�N���[���V���b�g�̉摜�n���h�����i�[��̎���int�^�|�C���^���i�[
	std::string loadingImgPath;///<  @brief Loading��ʂɕ\������摜�̃p�X���i�[
	int loadingImg;///<  @brief Loading��ʂɕ\������摜�n���h�����i�[
	bool useThread_AwakeFlag;///<  @brief void Awake()���o�b�N�O���E���h�Ŏ��s���邩�ǂ����̃t���O
	int loadingMinimalTime;///<  @brief Loading�ɔ�₷�Œ᎞�Ԃ��i�[�i�}�C�N���b�j
#ifdef USE_LUA
	lua_State *Lua;///<  @brief ����
#endif
};
}
//Singleton
extern suken::CSystem System;///<  @brief 
