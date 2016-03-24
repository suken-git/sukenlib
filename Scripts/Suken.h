#pragma once

#include"Manager.h"

//�Z�[�t�J���[�ɂ���
//0�A51�A102�A153�A204�A255��6�i�K��RGB�Ōv216�g���܂��B

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
*	@brief �������C�u�����Ǝ��f�o�b�O�p�֐�
*	exe�̓�����ꎞ�I�Ɏ~�߁A�G���[���b�Z�[�W��\������B
*	��������̑�������邱�Ƃŕ����\�B
*	@param format �o�͂���x�����̏����t��������̃A�h���X
* @return �Ȃ�
*/

inline void WarningSK(const char* format, ...){
	 char tmpchar[256];
    sprintf_s(tmpchar, "�x�� : \n\n%s\n\n", format);
	printfDx(tmpchar);
	printfDx("PRESS ANY KEY TO CONTINUE...");
    ScreenFlip();
    WaitKey();
    clsDx();
    ClearDrawScreen();
}
/**
*	@brief �_�C�A���O���J���āA�B
*	�}�b�v�G�f�B�^�Ȃǂ����Ƃ��ɕ֗�����
*	@param  filename �J�������t�@�C�������i�[����������
*	@param filetype ���ݖ���
* @return true
*/
extern bool SelectOpenFile( char *filename , char *filetype = "all file(*.*)\0*.*\0\0");
/**
*	@brief �_�C�A���O���J���āA�t�@�C����ۑ�����B
*	�}�b�v�G�f�B�^�Ȃǂ����Ƃ��ɕ֗�����
*	@param  filename �ۑ��������t�@�C�������i�[����������
*	@param filetype ���ݖ���
* @return true
*/
extern bool SaveFile(char *filename ,char *filetype =  "all file(*.*)\0*.*\0\0");
class CPos{
public:
	CPos(){
		x=y=0;
	}
int x,y;
};

class CSystem{
public:
	CSystem(){
		startTime = 0;
		count = 0;
		fps = 60.0;		//0���Z��h������
		frame = 0;
		escapeFlag = false;
		targetFps = 0.0f;
		screenShotGrHandleAdress = NULL;
		loadingImgPath[0] = NULL;
	}
	~CSystem(){
	
	}
	void Awake(){
		//�Q�[���̒���{�ݒ�A���ʉ���������Ȃ�
		SetWindowIconID( 101 ) ;//�A�C�R���̂��
		SetGraphMode( WINDOW_WIDTH ,  WINDOW_HEIGHT , 32 ) ;//SetWindowSize(WINDOW_WIDTH , WINDOW_HEIGHT );
		ChangeWindowMode(TRUE);
		SetAlwaysRunFlag(TRUE);//�펞�N������̂�TRUE
		SetOutApplicationLogValidFlag( FALSE );//���O�o�͗}������̂�FALSE
		DxLib_Init(); 
		SetDrawScreen( DX_SCREEN_BACK );
		SetTransColor( 255 , 0 , 255 );	//�}�[���^����
		if(loadingImgPath[0] != NULL){
			loadingImg = LoadGraph(loadingImgPath);
		}
		DrawExtendGraph(0,0,WINDOW_WIDTH,WINDOW_HEIGHT,loadingImg,true);
			//���t���b�V�����[�g�̎擾
		HDC hdc;
		hdc = GetDC( GetMainWindowHandle() );//�f�o�C�X�R���e�L�X�g�̎擾
		refreshRate = GetDeviceCaps( hdc , VREFRESH );//���t���b�V�����[�g�̎擾
		ReleaseDC( GetMainWindowHandle() , hdc );//�f�o�C�X�R���e�N�X�g�̉��


		display = CreateDC(TEXT("DISPLAY") , NULL , NULL , NULL);


#ifdef USE_LUA
	Lua = luaL_newstate();
#endif
		ScreenFlip();

		N = refreshRate;//1�b�Ɉ��fps���Z�o

		now = GetNowCount();
		localStandardTime = now;

	}
	int  GetLocalStandardTime(){
		return localStandardTime;
	}
	void SetUseThread_Awake(bool flag){
		useThread_AwakeFlag = flag;
	}
	bool GetUseThread_Awake(){
		return useThread_AwakeFlag;
	}
	void SetLoadingGraph(const char *path){
		strcpy(loadingImgPath,path);
	}
	void SetLoadingMinimalTime(int time){
		loadingMinimalTime = time;
	}
	void Wait_Loading(){
		int restTime = loadingMinimalTime - (GetNowCount()-localStandardTime);
		if(restTime > 0){
			WaitTimer(restTime);
		}
	}
	void Update(){
		//�Վ�
		//N = (int)(GetFps()+0.5);
		//
		now = GetNowCount();
		if( count == 0 ){ //1�t���[���ڂȂ玞�����L��
			startTime = now;
		}
		if( count == N ){ //�K��t���[���ɒB�����畽�ς��v�Z����
			
			fps = 1000/((now-startTime)/(double)N);
			count = 0;
			startTime = now;

		}

		count++;
		frame++;
	}
	void Wait(){
		
#ifdef DEBUG_DRAW
		DrawFormatString(0, 5, WHITE, "%.1f", fps);
#endif
		if(targetFps != 0.0f){
			int tookTime = now - startTime;	//������������
			int waitTime = count*1000/targetFps - tookTime;	//�҂ׂ�����
			if( waitTime > 0 ){
			Sleep(waitTime);	//�ҋ@

			}
		}else{
			Sleep(0);	//�]�����^�C���X���C�X��j��
		}
		
	}
	void End(){
		DxLib_End();	
		ShellExecute(GetMainWindowHandle() , "open" , "Launcher.exe" , NULL , NULL , SW_SHOW);
	}
	void TakeScreenShot(){
		if(screenShotFlag){
			screenShotFlag = false;
			if(screenShotGrHandleAdress != NULL){
				*screenShotGrHandleAdress = GetDrawScreen();
			}
			screenShotGrHandleAdress = NULL;
		}
	}
	void GetScreenShot(int *GrHandleAdress){
		screenShotFlag = true;
		screenShotGrHandleAdress = GrHandleAdress;
	}
	void Escape(){
		escapeFlag = true;
	}
	bool GetEscapeFlag(){
		
		return escapeFlag;
	}
	int GetFrame(){
		return frame;
	}
	int GetNow(){
		return now;
	}
	float GetFps(){
		return fps;
	}
	int GetRefreshRate(){
		return refreshRate;
	}
	void SetTargetFps(float _fps){
		targetFps = _fps;
	}
	float GetTargetFps(){
		return targetFps;
	}

	//�V�����X���b�h�����B
	void CreateNewThread( void(*pFunc)() ){
		if(handleChild.empty()){				
			DxLib::SetMultiThreadFlag( true );			//���̂܂܂ł�DxLib��DirectX�̊֌W�Ń}���`�X���b�h�ɂł��Ȃ��̂Őݒ肵�Ă��K�v������
		}
		//�V�����X���b�h���쐬�i�^�uHANDLE�v�̓|�C���^�Ȃ̂�System::CreateNewThread���\�b�h���I�����Ă������I�ɔj������Ȃ��j
		HANDLE handle = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)pFunc, NULL, 0, LPDWORD());

		handleChild.push_back(handle);
	}
	HDC GetDisplayDC(){
		return display;
	}
#ifdef USE_LUA
	lua_State *GetLua(){
		return Lua;
	}
#endif
private:
	HDC display ;//�f�B�X�v���C�h���C�o
	int frame;
	int count;
	int startTime;
	int localStandardTime;
	int N;			//N�t���[���Ɉ��fps���Z�o����
	float fps;
	float targetFps;
	int now;
	int refreshRate;
	vector<HANDLE> handleChild;
	bool escapeFlag;
	int screenShot;
	bool screenShotFlag;
	int *screenShotGrHandleAdress;
	char loadingImgPath[256];
	int loadingImg;
	bool useThread_AwakeFlag;
	int loadingMinimalTime;
#ifdef USE_LUA
	lua_State *Lua;
#endif
};
void SukenExecute(char *URL);
class CIntData{///�}�C�i�X�ɂ͖��Ή�

public:
	CIntData(char *_DataName);
	char *DataName;
	void NewMake();
	void WriteData();
	void ReadData();
	int RightData[2000];
	int LeftData[2000];

};
class CStrData {

public:
	CStrData(char *_DataName);
	char *DataName;
	void NewMake();
	void WriteData();
	void ReadData();
	char Data[1000][128];

};
class CCaesar{

public:
	CCaesar(char finame[],char imname[],int key);
	char *FileName;
	char *ImaginaryName;
	int Key;
	bool CaesarCode();
	bool CaesarDecode();
	bool CaesarToBMP();
	bool CaesarFromBMP();

};
class CBox{

public:
	CBox();

	int Left;
	int Top;
	int Width;
	int Height;
	int Color;

	void Draw();

private:
	
};
class CommandButton{

public:
	CommandButton();
	CommandButton( int _left , int _right , int _width , int _height );
	int Left;
	int Top;
	int Width;
	int Height;
	int ForeColor;
	int BGColor; //BackGroundColor
	int FontSize;

	char *Caption;

	void (*Func)();

	void Update();
	void Draw();
	void Judge();
	void Click();

private:

};
class CKeyPush{

public:
	char BACK;//KEY_INPUT_BACK  // �o�b�N�X�y�[�X�L�[ 
	char TAB;//KEY_INPUT_TAB  // �^�u�L�[ 
	char RETURN;//KEY_INPUT_RETURN  // �G���^�[�L�[
	char LSHIFT;//KEY_INPUT_LSHIFT  // ���V�t�g�L�[ 
	char RSHIFT;//KEY_INPUT_RSHIFT  // �E�V�t�g�L�[ 
	char LCONTROL;//KEY_INPUT_LCONTROL  // ���R���g���[���L�[ 
	char RCONTROL;//KEY_INPUT_RCONTROL  // �E�R���g���[���L�[ 
	char ESCAPE;//KEY_INPUT_ESCAPE  // �G�X�P�[�v�L�[ 
	char SPACE;//KEY_INPUT_SPACE  // �X�y�[�X�L�[ 
	char LEFT;//KEY_INPUT_LEFT  // ���L�[ 
	char UP;//KEY_INPUT_UP  // ��L�[ 
	char RIGHT;//KEY_INPUT_RIGHT  // �E�L�[ 
	char DOWN;//KEY_INPUT_DOWN  // ���L�[ 
	char INSERT;//KEY_INPUT_INSERT  // �C���T�[�g�L�[ 
	char Delete;//KEY_INPUT_DELETE  // �f���[�g�L�[
	char LALT;//KEY_INPUT_LALT  // ���`�k�s�L�[ 
	char RALT;//KEY_INPUT_RALT  // �E�`�k�s�L�[ 
	char SCROLL;//KEY_INPUT_SCROLL  // ScrollLock�L�[
	char CAPSLOCK;//KEY_INPUT_CAPSLOCK  // CaspLock�L�[ 
	char PAUSE;//KEY_INPUT_PAUSE  // PauseBreak�L�[
	char MINUS ; // �|�L�[ 
	char YEN ;  // ���L�[ 
	char PREVTRACK ; // �O�L�[ 
	char PERIOD ; // �D�L�[ 
	char SLASH ; // �^�L�[ 
	char SEMICOLON ; // �G�L�[ 
	char COLON ; // �F�L�[ 
	char LBRACKET ; // �m�L�[ 
	char RBRACKET ; // �n�L�[ 
	char AT ; // ���L�[ 
	char BACKSLASH ; // �_�L�[ 
	char COMMA ; // �C�L�[ 
	char F1 ; // �e�P�L�[ 
	char F2 ; // �e�Q�L�[ 
	char F3 ; // �e�R�L�[ 
	char F4 ; // �e�S�L�[ 
	char F5 ; // �e�T�L�[ 
	char F6 ; // �e�U�L�[ 
	char F7 ; // �e�V�L�[ 
	char F8 ; // �e�W�L�[ 
	char F9 ; // �e�X�L�[ 
	char F10 ; // �e�P�O�L�[ 
	char F11 ; // �e�P�P�L�[ 
	char F12 ; // �e�P�Q�L�[
	char A ; // �`�L�[ 
	char B ; // �a�L�[ 
	char C ; // �b�L�[ 
	char D ; // �c�L�[ 
	char E ; // �d�L�[ 
	char F ; // �e�L�[ 
	char G ; // �f�L�[ 
	char H ; // �g�L�[ 
	char I ; // �h�L�[ 
	char J ; // �i�L�[ 
	char K ; // �j�L�[ 
	char L ; // �k�L�[ 
	char M ; // �l�L�[ 
	char N ; // �m�L�[ 
	char O ; // �n�L�[ 
	char P ; // �o�L�[ 
	char Q ; // �p�L�[ 
	char R ; // �q�L�[ 
	char S ; // �r�L�[ 
	char T ; // �s�L�[ 
	char U ; // �t�L�[ 
	char V ; // �u�L�[ 
	char W ; // �v�L�[ 
	char X ; // �w�L�[ 
	char Y ; // �x�L�[ 
	char Z ; // �y�L�[ 
	char Key0 ; // �O�L�[ 
	char Key1 ; // �P�L�[ 
	char Key2 ; // �Q�L�[ 
	char Key3 ; // �R�L�[ 
	char Key4 ; // �S�L�[ 
	char Key5 ; // �T�L�[ 
	char Key6 ; // �U�L�[ 
	char Key7 ; // �V�L�[ 
	char Key8 ; // �W�L�[ 
	char Key9 ; // �X�L�[ 

	void ALLKEYCHECK();

};
void Awake();
void GameLoop();
int Clng( char *Str ,int n = 0) ;
int ClngTo ( char *Str ,char Word );
int ClngFrom ( char *Str ,char Word );
double Scos(int Angle);
double Ssin(int Angle);
double Stan(int Angle);
int AngleFromRad(double Angle);
int Power2(int x, int y);
bool CheckWord(char *Str ,char Word );
unsigned long FileGetSize(char *FileName);
void GetHttpFile(char *&Buf,char *Http,unsigned long ReadSize = 65536);

class CMidi{
	
private:
	HMIDIOUT hMidiOut;
	DWORD MIDIMSG(BYTE _status, BYTE _channel, BYTE  _data1, BYTE _data2){
		return (DWORD)((_status << 4) | _channel | (_data1 << 8) | (_data2 << 16));
	}
public:
	CMidi(){
		//Midi���J��
		midiOutOpen(&hMidiOut, MIDI_MAPPER, 0, 0, 0);
	}
	~CMidi(){
		//Midi�����
		midiOutReset(hMidiOut);                 //�S�`�����l�����m�[�g�I�t											
		midiOutClose(hMidiOut);                 // MIDI�o�̓f�o�C�X�����
	}
	//���̊֐����Ăяo���Ɩ炷���Ƃ��o����
	//BYTE �͐�����0~127���󂯕t����ƍl����Ƃ����B
	//_Height�͉��̍���(0~127)
	//_Velocity�͉��̋���(0~127)
	//_channel �͖炷�`�����l���A�����̊y��p�[�g���g�������Ƃ��Ɏg��
	void Lang(BYTE _Height, BYTE _Velocity, BYTE _channnel = 0x0){
		if (_Height < 0)_Height = 0; if (_Height > 0x7f)_Height = 0x7f;
		if (_Velocity < 0)_Velocity = 0; if (_Velocity > 0x7f)_Velocity = 0x7f;
		midiOutShortMsg(hMidiOut, MIDIMSG(0x9, _channnel, _Height, _Velocity)); //0x3c(C3�h) 0x3D(�h#)
	}
	//���̍����̉��̍Đ����~�߂�
	void Stop(BYTE _Height, BYTE _channnel = 0x0){
		midiOutShortMsg(hMidiOut, MIDIMSG(0x9, _channnel, _Height, 0));
	}
	//�y���ς���
	void ChangeTimble(BYTE _Timble, BYTE _channnel = 0x0){
		if (_Timble < 0)_Timble = 0; if (_Timble > 0x7f)_Timble = 0x7f;
		midiOutShortMsg(hMidiOut, MIDIMSG(0xc, _channnel, _Timble, 0));
	}

};
//�Ⴆ�� MD.Lang(100, 72)��Midi��点��B

/////FROM NUNULIB
//���ݎ����擾�֐�///////////////////////////////////////////
SYSTEMTIME GetNowSystemTime();  //SYSTEMTIME�^�œ��{�������擾
std::string GetNowSystemTimeString();  //string�^(00/00/00 00:00:00 000)�Ō��ݓ��{�������擾

inline int DrawCenterString(int cx, int y, const TCHAR *String, int color, bool centerY=false){ //x�����E�̒��S�ɂ���DrawString�ŕ����`��i��y�͏㉺���S�ł͂Ȃ���Ӂj
    if (centerY){
        return DxLib::DrawString(cx-GetDrawStringWidth(String, strlen(String))/2, y-GetFontSize()/2, String, color);    //�����܂Ŗڈ� 
    }else{
        return DxLib::DrawString(cx-GetDrawStringWidth(String, strlen(String))/2, y, String, color); 
    }
}
int DrawCenterString(int cx, int y, int color, const TCHAR* format, ...);
int DrawCenterString(int cx, int y, int color, bool centerY, const TCHAR* format, ...);

///�G���[&�f�o�b�O�o�͗p�֐�///////////////////////////////////////////////////////
#define ERRORDX(...)     ErrorDx(__LINE__, __FUNCTION__, __FILE__,  __VA_ARGS__)
#define WARNINGDX(...) WarningDx(__LINE__, __FUNCTION__, __FILE__,  __VA_ARGS__)
#define DEBUGDX(...)     DebugDx(__LINE__, __FUNCTION__, __FILE__,  __VA_ARGS__)
 
 
inline void myprintLog(const char* filename, const char* format, va_list args){
    #ifndef MYLOG_DISABLE
        FILE *fp;
        errno_t error;
        char txtfilename[1024];
        sprintf_s(txtfilename, "%s.txt", filename);
        if(error = fopen_s(&fp, txtfilename, "a") != 0){
            return;
        }else{
            char tmpchar[1024];
            vsprintf_s(tmpchar, format, args);
            fprintf_s(fp, "[%s]:%s\n", GetNowSystemTimeString().c_str(), tmpchar);
            fclose(fp);
        }
    #endif
}
inline void myLog(const char* format, ...){
    va_list args;
    va_start(args, format);
    myprintLog("MyLog", format, args);
    va_end(args);
}
inline void myLogf(const char* filename, const char* format, ...){
    va_list args;
    va_start(args, format);
    myprintLog(filename, format, args);
    va_end(args);
}
inline void myprintfDx(const char* format, va_list args, const char* filename=NULL, int line=0){
    char string[1024];
    vsprintf_s(string, format, args);   //va_start��va_end�͌Ăяo�����ł���
    if (filename!=NULL) sprintf_s(string, "%s\n->%s(%d)\n", string, filename, line);
 
    myLogf("MyLog_Printed", "PRINT: %s", string);
    printfDx(string);
    ScreenFlip();
    WaitKey();
    clsDx();
    ClearDrawScreen();
}
inline void ErrorDx(int line, const char* func, const char* filename, const char* format, ...){
    char tmpchar[256];
    va_list args;   va_start(args, format);
    sprintf_s(tmpchar, "Error->%s\n->%s", format, func);
    myprintfDx(tmpchar, args, filename, line);
    va_end(args);
}
inline void ErrorDx(const char* format, char* filename, int line, ...){
    va_list args;
    va_start(args, line);
    myprintfDx(format, args, filename, line);
    va_end(args);
}
inline void ErrorDx(const char* format, ...){
    va_list args;
    va_start(args, format);
    myprintfDx(format, args);
    va_end(args);
}
inline void WarningDx(int line, const char* func, const char* filename, const char* format, ...){
    #ifndef WARNINGDX_DISABLE 
        char tmpchar[256];
        va_list args;   va_start(args, format);
        sprintf_s(tmpchar, "Warning->%s\n->%s", format, func);
        myprintfDx(tmpchar, args, filename, line);
        va_end(args);
    #endif
}
inline void WarningDx(const char* format, char* filename, int line, ...){
    #ifndef WARNINGDX_DISABLE 
        va_list args;
        va_start(args, line);
        myprintfDx(format, args, filename, line);
        va_end(args);
    #endif
}
inline void WarningDx(const char* format, ...){
    #ifndef WARNINGDX_DISABLE 
        va_list args;
        va_start(args, format);
        myprintfDx(format, args);
        va_end(args);
    #endif
}
inline void DebugDx(int line, const char* func, const char* filename, const char* format, ...){
    #ifndef DEBUGDX_DISABLE 
        char tmpchar[256];
        va_list args;   va_start(args, format);
        sprintf_s(tmpchar, "Debug->%s\n->%s", format, func);
        myprintfDx(tmpchar, args, filename, line);
        va_end(args);
    #endif
}
inline void DebugDx(const char* format, char* filename, int line, ...){
    #ifndef DEBUGDX_DISABLE 
        va_list args;
        va_start(args, line);
        myprintfDx(format, args, filename, line);
        va_end(args);
    #endif
}
inline void DebugDx(const char* format, ...){
    #ifndef DEBUGDX_DISABLE 
        va_list args;
        va_start(args, format);
        myprintfDx(format, args);
        va_end(args);
    #endif
}
/////////////////////////////////////////////////////////////

//////////////////////////////////////

void AddFontFromPath(char *path);

namespace suken{
///////////////////////////////////////////////////////////////////////
///�񎟌����W�p�N���X�i���x�Ȃǂɕ֗��j///////////////////////////////////
///���Z�q�I�[�o�[���[�h��DxLib��VECTOR�p�֐��Ɠ����悤�Ɏg����֐��Q��/////
///////////////////////////////////////////////////////////////////////

class CVector{  //�錾�Ɠ����ɒ�`�������Ă���̂̓C�����C�������邽��
public:
    CVector( float _x , float _y ){
        x = _x;
        y = _y;
    }
 
    CVector(){
        x = 0.0f;
        y = 0.0f;
    }
 
    float x;
    float y;
 
    void Set( float _x , float _y){
        x = _x;
        y = _y;
    }
    void Set(CVector _vec){
        x = _vec.x;
        y = _vec.y;
    }
     
    CVector Add( float _x , float _y){
        x += _x;
        y += _y;
        return *this;
    }
    CVector Add(CVector _vec){
        x += _vec.x;
        y += _vec.y;
        return *this;
    }
 
    // +���Z�q�I�[�o�[���[�h
    CVector operator+(const CVector &obj){
        CVector tmp;
        tmp.x = x + obj.x;
        tmp.y = y + obj.y;
        return tmp;
    }
 
    // +=���Z�q�I�[�o�[���[�h
    CVector& operator+=(const CVector &obj){
        x += obj.x;
        y += obj.y;
        return *this;
    }
    CVector& operator+=(const float _num){
        x += _num;
        y += _num;
        return *this;
    }
     
    // -���Z�q�I�[�o�[���[�h
    CVector operator-(const CVector &obj){
        CVector tmp;
        tmp.x = x - obj.x;
        tmp.y = y - obj.y;
        return tmp;
    }
    // -=���Z�q�I�[�o�[���[�h
    CVector& operator-=(const CVector &obj){
        x -= obj.x;
        y -= obj.y;
        return *this;
    }
    CVector& operator-=(const float _num){
        x -= _num;
        y -= _num;
        return *this;
    }
    //*���Z�q�I�[�o�[���[�h
    CVector operator*(const float _num){
        CVector tmp;
        tmp.x = x * _num;
        tmp.y = y * _num;
        return tmp;
    }

    //*=���Z�q�I�[�o�[���[�h
    CVector& operator*=(const float _num){
        x*=_num;
        y*=_num;
        return *this;
    }

	//  /���Z�q�I�[�o�[���[�h
    CVector operator/(const float _num){
        CVector tmp;
        tmp.x = x / _num;
        tmp.y = y / _num;
        return tmp;
    }
    ///=���Z�q�I�[�o�[���[�h
    CVector& operator/=(const float _num){
        x/=_num;
        y/=_num;
        return *this;
    }
	///==���Z�q�I�[�o�[���[�h
    bool operator==(const CVector &obj){
		if(x==obj.x&&y==obj.y){
			return true;
		}
        return false;
    }
	
	///=���Z�q�I�[�o�[���[�h
	CVector& operator =(const CVector &obj) {
		this->x = obj.x;
		this->y = obj.y;

		//*this��Ԃ����ƂŁuA=B�v�̂悤�ȋL�q�����łȂ��uA=B=C�v�̂悤�ȋL�q�ɂ��Ή��ł���
		return *this;
	}
    //operator*�̃I�[�o�[���[�h�ɂ����͂�s�v�Ȋ֐�
    void Multiple(float _num){
        x = x*_num;
        y = y*_num;
    }
 
    float GetLength(){
        return sqrt((x*x)+(y*y));
    }
private:
};

//////////////////////////////////////////////
//////DxLib��VECTOR�p�֐��̃I�[�o�[���[�h///////
//////////////////////////////////////////////
__inline CVector VGet(float _x,float _y){
	CVector temp;
	temp.x=_x;
	temp.y=_y;
	return temp;
}
__inline CVector VAdd(CVector v1,CVector v2){
	CVector temp;
	temp.x=v1.x+v2.x;
	temp.y=v1.y+v2.y;
	return temp;
}
__inline CVector VSub(CVector v1,CVector v2){
	CVector temp;
	temp.x=v1.x-v2.x;
	temp.y=v1.y-v2.y;
	return temp;
}
__inline float VDot(CVector v1,CVector v2){
	return (v1.x*v2.x+v1.y*v2.y);
}
__inline VECTOR VCross(CVector v1,CVector v2){
	VECTOR temp;
	temp.z=(float)v1.x*v2.y-v1.y*v2.x;
	return temp;
}
__inline float VCrossLength(CVector v1,CVector v2){
	return ((v1.x*v2.y)-(v1.y*v2.x));
}
__inline CVector VScale(CVector v1,float scale){
	CVector temp;
	temp.x=v1.x*scale;
	temp.y=v1.y*scale;
	return temp;
}
__inline float VSize(CVector v1){
	return sqrt( (float)(v1.x * v1.x + v1.y * v1.y) ) ;
}
__inline float VSquareSize(CVector v1){
	return  (v1.x * v1.x + v1.y * v1.y);
}
__inline CVector VNorm(CVector v1){
	float size=VSize(v1);
	CVector temp;
	temp.x=v1.x/size;
	temp.y=v1.y/size;
	return temp;
}

__inline float GetDistance(CVector v1 ,CVector v2){
	
	return sqrt(pow(abs(v1.x-v2.x),2.0f)+pow(abs(v1.y-v2.y),2.0f));
	
}
__inline float GetSquareDistance(CVector v1 ,CVector v2){
	
	return pow(abs(v1.x-v2.x),2.0f)+pow(abs(v1.y-v2.y),2.0f);
	
}
__inline int DrawLine(CVector &v1 , CVector &v2 ,int color){
	return DxLib::DrawLine((int)v1.x,(int)v1.y,(int)v2.x,(int)v2.y,color);
}
__inline int DrawCircle(CVector &v,int r,int color,bool fillFlag){
	return DxLib::DrawCircle((int)v.x,(int)v.y,r,color,fillFlag);
}
__inline int DrawBox(CVector &v1,CVector &v2,int color,bool fillFlag){
	return DxLib::DrawBox((int)v1.x,(int)v1.y,(int)v2.x,(int)v2.y,color,fillFlag);
}
_inline int DrawOval(CVector &v,CVector &r,int color,bool fillFlag){
	return DxLib::DrawOval((int)v.x,(int)v.y,(int)r.x,(int)r.y,color,fillFlag);
}
_inline int DrawOval(CVector &v,int rx,int ry,int color,bool fillFlag){
	return DxLib::DrawOval((int)v.x,(int)v.y,rx,ry,color,fillFlag);
}
_inline int DrawTriangle(CVector &v1,CVector &v2,CVector &v3,int color,bool fillFlag){
	return DxLib::DrawTriangle((int)v1.x,(int)v1.y,(int)v2.x,(int)v2.y,(int)v3.x,(int)v3.y,color,fillFlag);
}
_inline int DrawPixel(CVector &v,int color){
	return DxLib::DrawPixel((int)v.x,(int)v.y,color);
}
}//namespace suken end

using namespace suken;

unsigned int fanctorial(unsigned int num);			//
unsigned int combination(unsigned int n , unsigned int r);					//nCr�Ƃ���邠��B�g�ݍ��킹

typedef vector<CVector> BEZIER ;
//�x�W�F�Ȑ��̕`��i GetBezier�֐��ō쐬�����f�[�^���K�v�@�j
////GetBezier�֐��ō쐬�����f�[�^��p���ăx�W�F�Ȑ���`�悷��
//����
// data  : GetBezier�֐��ō쐬�����x�W�F�Ȑ��f�[�^
// color : �`��F���w��
void DrawBezier( BEZIER &data ,  int color );
	//�x�W�F�Ȑ����_�f�[�^�̍쐬
////�x�W�F�Ȑ��̌v�Z���}�C�t���[������͖̂��ʂȂ̂Ōv�Z�ς݂̃f�[�^���쐬����
//����
// In�@�@�@�@: ����_�iCVector�^�j���w�肷��i2�ȏ�j
// vertexNum : �쐬����f�[�^�ׂ̍������w��i�x�W�F�Ȑ��̍\�����_�̐��j
BEZIER GetBezier(vector<CVector> &In , unsigned int vertexNum );

CVector GetIntersection( int a1 , int b1 , int a2 , int b2 );

class CTransform{
public:
	CTransform(){
		//prePosition = position = velocity = acceralate = VGet(0,0);
		rotation = 0;
		gravity = GRAVITY;
		airResistance = 0 ;
	}
	CVector position;
	CVector velocity;
	CVector acceralate;

	CVector prePosition;

	float rotation;
	/*static*/ float airResistance;
	/*static*/ CVector gravity;
	void transLate(CVector _v){
		position += _v;
	}
	void Loop(){
		
		//prePosition = position;
		
		///��C��R
		acceralate *= ( 1 - ( airResistance / System.GetFps() ));
		
		///���x
		velocity += (acceralate + gravity ) / System.GetFps();
		//velocity *= ( 1 - ( airResistance / System.GetFps() ));
		///�ʒu
		prePosition = position;
		position += velocity / System.GetFps();
	}
};
class CSuperGameObject{
public:
	CSuperGameObject(){
	
	}
	virtual void Awake(){
	
	}
	virtual void Loop(){
		transform.Loop();
		
	}

	CTransform transform;
};
class CRect{
public:
	CRect(){
		direction=0.0f;
		Set(1,1);
	}
	CTransform	center;
	float direction;
	
	static const int figureType = SHAPE_RECT; 
	void Set(int sizeX,int sizeY){
		size = VGet((float)sizeX,(float)sizeY);
		rad = atan2(size.y,size.x);
		radius = ( size.GetLength() / 2.0f );
	}
	CVector GetCenterPos(){		return center.position;						}
	CVector GetSize(){			return size;								}
	float GetArea(){			return ( size.x * size.y );					}
	CVector GetRightTop(){				return ( center.position + VScale(VGet((float)cos(direction+rad),(float)sin(direction+rad)),radius) );	}
	CVector GetLeftTop(){				return ( center.position + VScale(VGet((float)cos(direction-rad),(float)sin(direction-rad)),radius) );	}
	CVector GetLeftBottom(){			return ( center.position + VScale(VGet((float)cos(direction-M_PI+rad),(float)sin(direction-M_PI+rad)),radius) );	}
	CVector GetRightBottom(){			return ( center.position + VScale(VGet((float)cos(direction+M_PI-rad),(float)sin(direction+M_PI-rad)),radius) );	}
	void Draw(int color){
		DrawLine(GetLeftTop(),GetRightTop(),RED);
		DrawLine(GetRightTop(),GetRightBottom(),BLUE);
		DrawLine(GetRightBottom(),GetLeftBottom(),GREEN);
		DrawLine(GetLeftBottom(),GetLeftTop(),WHITE);
	}
	void Loop(){

		center.Loop();
#ifdef DEBUG_DRAW
		Draw(WHITE);
		
#endif
	}
	float GetRadius(){
		return radius;
	}
	void AddEventLisnerOnCollision(void (*pFunc)()){
		onCollisionTask.push_back(pFunc);
	}
	void RemoveEventLisnerOnCollision(void (*pFunc)()){

		if(!onCollisionTask.empty()){
			vector<void(*)()>::iterator it = onCollisionTask.begin();
			while( ( it != onCollisionTask.end() ) ){

				if( *it ==  pFunc  ){

					onCollisionTask.erase( it );
					break;
				}
				it++;
			}
		}	
	}
	void OnCollision(){
		if(!onCollisionTask.empty()){
			vector<void(*)()>::iterator it=onCollisionTask.begin();

			while( it != onCollisionTask.end() ) {

				(*it)();					
				it++;
			}

		}
	}
private:
	vector<void(*)()> onCollisionTask;
	float rad;
	float radius;
	CVector size;
};
class CCircle{
public:
	CCircle(){
		mass = 1.0f;
		radius = 1.0f;
		bound = 1.0f;
		IsKinematic = false;
	}
	CTransform center;
	float radius;
	float mass;
	float bound;
	bool IsKinematic;
	bool onCollision;
	static const int figureType = SHAPE_CIRCLE; 
	CVector GetCenterPos(){		return center.position;					}
	float GetArea(){			return (float)( M_PI * radius * radius );		}
	void Loop(){
		center.Loop();
//#ifdef DEBUG_DRAW
		DxLib::DrawCircle((int)(center.position.x +0.5), (int)(center.position.y+0.5) , (int)(radius+0.5) ,WHITE ,false );
//#endif
	}
	void AddEventLisnerOnCollision(void (*pFunc)()){
		onCollisionTask.push_back(pFunc);
	}
	void RemoveEventLisnerOnCollision(void (*pFunc)()){

		if(!onCollisionTask.empty()){
			vector<void(*)()>::iterator it = onCollisionTask.begin();
			while( ( it != onCollisionTask.end() ) ){

				if( *it ==  pFunc  ){

					onCollisionTask.erase( it );
					break;
				}
				it++;
			}
		}	
	}
	void OnCollisionFunc(){
		if(!onCollisionTask.empty()){
			vector<void(*)()>::iterator it=onCollisionTask.begin();

			while( it != onCollisionTask.end() ) {

				(*it)();					
				it++;
			}

		}
	}
private:
	vector<void(*)()> onCollisionTask;
};

class CCollisionManager{
public:
	CCollisionManager(){
	
	}
	~CCollisionManager(){
	
	}

	void Awake(){
	
	}

	void Loop(){
		
		for(unsigned int i=0;i<physicsCircle.size();i++){
			physicsCircle[i]->onCollision = false;
		}
		for(unsigned int i=0;i<physicsCircle.size();i++){
			physicsCircle[i]->Loop();
			for(unsigned int j=i+1;j<physicsCircle.size();j++){
				CollisionCircle(*physicsCircle[i],*physicsCircle[j]);
			}
			for(unsigned int j=0;j<fixedCircle.size();j++){
				CollisionCircle(*physicsCircle[i],*fixedCircle[j]);
			}
		}
		for(unsigned int i=0;i<physicsRect.size();i++){
			physicsRect[i]->Loop();
			for(unsigned int j=i+1;j<physicsRect.size();j++){
				if( !CollisionRect(*physicsRect[i],*physicsRect[j]) ){
					CollisionRect(*physicsRect[j],*physicsRect[i]);
				}
			}
			for(unsigned int j=0;j<fixedRect.size();j++){
				if( !CollisionRect(*physicsRect[i],*fixedRect[j]) ){
					CollisionRect(*fixedRect[j],*physicsRect[i]);
				}
			}
		}
		/*for(unsigned int i=0;i<physicsCircle.size();i++){
			if(physicsCircle[i]->center.position.x < 0){
				physicsCircle[i]->center.velocity.x = -(physicsCircle[i]->center.velocity.x);
				physicsCircle[i]->center.position.x = 0;
			}
			if(physicsCircle[i]->center.position.x > WINDOW_WIDTH ){
				physicsCircle[i]->center.velocity.x = -(physicsCircle[i]->center.velocity.x);
				physicsCircle[i]->center.position.x = WINDOW_WIDTH ;
			}
			if(physicsCircle[i]->center.position.y < 0){
				physicsCircle[i]->center.velocity.y = -(physicsCircle[i]->center.velocity.y);
				physicsCircle[i]->center.position.y = 0;
			}
			if(physicsCircle[i]->center.position.y > WINDOW_HEIGHT ){
				physicsCircle[i]->center.velocity.y = -(physicsCircle[i]->center.velocity.y);
				physicsCircle[i]->center.position.y = WINDOW_HEIGHT;
			}
		}*/
		
	}
	void DrawLoop(){
	
	}

	void CollisionCircleCalc(CCircle &A , CCircle &B ,float time){
		
		float totalWeight = A.mass + B.mass;				//���ʘa
		float reflectionRate = (1 + A.bound * B.bound );	// ������
		CVector C = VNorm( B.center.position - A.center.position ); // �Փˎ��x�N�g��
		float dot = VDot( ( A.center.velocity - B.center.velocity ), C ); // ���ώZ�o
		CVector constVec = C * ( reflectionRate * dot / totalWeight ); // �萔�x�N�g��

		//���x��������
		
		//if(!A.IsKinematic){
			A.center.velocity += constVec * (-B.mass);
		//}
		//if(!B.IsKinematic){
			B.center.velocity += constVec  * A.mass ;
		//}

		// �Փˌ�ʒu�̎Z�o
		A.center.position += (A.center.velocity) * 0.1f;
		B.center.position += (B.center.velocity) * 0.1f;

	}
	bool CollisionCircle(CCircle &A , CCircle &B){
		// �O�ʒu�y�ѓ��B�ʒu�ɂ�����p�[�e�B�N���Ԃ̃x�N�g�����Z�o
		CVector C0 = B.center.prePosition - A.center.prePosition;
		CVector C1 = B.center.position - A.center.position;
		CVector D = C1 - C0;

		// �Փ˔���p��2���֐��W���̎Z�o
	float P = VSquareSize( D ); 
	// ���������Ɉړ�
	if(P==0){ 
		return false; 
	}
	float Q = VDot( C0, D );
	float R = VSquareSize( C0 );

	// ����
	float r = A.radius + B.radius;

	 // �Փ˔��莮
		float Judge = Q*Q - P*(R-r*r);

		if( Judge < 0 ){
		// �Փ˂��Ă��Ȃ�
			return false;
		}

	// �Փˎ��Ԃ̎Z�o
	float t_plus = (-Q + sqrt( Judge ) ) / P;
	float t_minus = ( -Q - sqrt( Judge ) ) / P;

	// �Փˈʒu�̌���
	CVector pOut_colli_A = A.center.prePosition + ( A.center.position - A.center.prePosition) * t_minus;
	CVector pOut_colli_B = B.center.prePosition + ( B.center.position - B.center.prePosition) * t_minus;

   // �Փˎ��Ԃ̌���it_minus������ɍŏ��̏Փˁj
   float pOut_t0 = t_minus;
   float pOut_t1 = t_plus;

  // ���ԓ��Փ˂ł��邩�H
   // t_minus��1���傫���Ɠ͂����Փ˂��Ă��Ȃ�
   // t_plus�At_minus�������Ƃ��}�C�i�X���Ɣ��Ε����Ȃ̂ŏՓ˂��Ȃ�
   if( (t_minus > 1) || (t_minus < 0 && t_plus < 0) ){
      return false;
   }

   //�Փˏ���

   A.onCollision=true;
   B.onCollision=true;

   A.OnCollisionFunc();
   B.OnCollisionFunc();
#ifdef DEBUG_DRAW
   DxLib::DrawCircle((int)(A.center.position.x +0.5), (int)(A.center.position.y+0.5) , (int)(A.radius+0.5) ,GREEN ,true );
   DxLib::DrawCircle((int)(B.center.position.x +0.5), (int)(B.center.position.y+0.5) , (int)(B.radius+0.5) ,GREEN ,true );
#endif
   CollisionCircleCalc(A ,B ,pOut_t0);
   return true; // �Փ˕�

	}
	bool CollisionRect(CRect &A , CRect &B){
		if(pow((A.GetRadius()+B.GetRadius()),2.0f) > GetSquareDistance(A.center.position,B.center.position)){
		CVector v[4]={VSub(A.GetRightTop(),A.GetLeftTop()),VSub(A.GetRightBottom(),A.GetRightTop()),VSub(A.GetLeftBottom(),A.GetRightBottom()),VSub(A.GetLeftTop(),A.GetLeftBottom())};
		CVector s[4]={A.GetLeftTop(),A.GetRightTop(),A.GetRightBottom(),A.GetLeftBottom()};
		CVector vertex[4]={B.GetLeftTop(),B.GetRightTop(),B.GetRightBottom(),B.GetLeftBottom()};
		bool IsCollision[4]={true,true,true,true};
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				if( VCrossLength(v[j],VSub(vertex[i],s[j])) < 0 ){
					IsCollision[i]=false;
				}
			}
			if(IsCollision[i]){
				A.OnCollision();
				B.OnCollision();
#ifdef DEBUG_DRAW
				A.Draw(GREEN);
				B.Draw(GREEN);
				//DrawBox(A.center.position+VGet(20,20),A.center.position-VGet(20,20),RED,true);
#endif
				return true;
			}
		}
		
		}else{
#ifdef DEBUG_DRAW
			//DrawBox(A.center.position+VGet(20,20),A.center.position-VGet(20,20),BLUE,true);
#endif
		}
		return false;
	}
	void AddChild(CCircle *_circle , bool moveFlag){
		if(moveFlag){
			physicsCircle.push_back(_circle);
		}else{
			fixedCircle.push_back(_circle);
			_circle->mass = INF ;
		}
	}
	bool RemoveChild(CCircle *_circle){

		vector<CCircle*>::iterator it_p = physicsCircle.begin();
		for(unsigned int i=0;i<physicsCircle.size();i++){
			if( physicsCircle[i] == _circle ){
				physicsCircle.erase(it_p);
				return true;
			}
			it_p++;
		}

		vector<CCircle*>::iterator it_f = fixedCircle.begin();
		for(unsigned int i=0;i<fixedCircle.size();i++){
			if( fixedCircle[i] == _circle ){
				fixedCircle.erase(it_f);
				return true;
			}
			it_f++;
		}

		return false;
	}
	void AddChild(CRect *_rect , bool moveFlag){
		if(moveFlag){
			physicsRect.push_back(_rect);
		}else{
			fixedRect.push_back(_rect);
		}
	}
	bool RemoveChild(CRect *_rect){

		vector<CRect*>::iterator it_p = physicsRect.begin();
		for(unsigned int i=0;i<physicsRect.size();i++){
			if( physicsRect[i] == _rect ){
				physicsRect.erase(it_p);
				return true;
			}
			it_p++;
		}

		vector<CRect*>::iterator it_f = fixedRect.begin();
		for(unsigned int i=0;i<fixedRect.size();i++){
			if( fixedRect[i] == _rect ){
				fixedRect.erase(it_f);
				return true;
			}
			it_f++;
		}

		return false;
	}
	vector<CCircle*> physicsCircle;
	vector<CCircle*> fixedCircle;
	vector<CRect*> fixedRect;
	vector<CRect*> physicsRect;
};

//���͗p�f�[�^�N���X
class CKeyIn{
public:
	int keyCode;
	void (*pFunc)();
};
class CMouseIn{
public:
	CMouseIn(){
		
	}
	int x1,x2,y1,y2;
	void (*pFunc)();
	int type;
	
};
class CpMouseIn{
public:
	CpMouseIn(){
		
	}
	int *x1,*x2,*y1,*y2;
	void (*pFunc)();
	int type;
	
};
class CKeyBoolIn{
public:
	int keyCode;
	bool *pBool;
};
class CMouseBoolIn{
public:
	int x1,x2,y1,y2;
	bool *pBool;
	int type;
	

};
class CpMouseBoolIn{
public:
	int *x1,*x2,*y1,*y2;
	bool *pBool;
	int type;
	
};
class CFrame{
public:
	void (*pFunc)();
};
class CBoolean{
public:
	void (*pFunc)();
	bool* pBool;
};


class CKey{
public:
	CKey(){

      

	}

	  static const int BACK = KEY_INPUT_BACK	;
      static const int TAB = KEY_INPUT_TAB	;
      static const int RETURN = KEY_INPUT_RETURN	;

      static const int LSHIFT = KEY_INPUT_LSHIFT	;
      static const int RSHIFT = KEY_INPUT_RSHIFT	; 
      static const int LCONTROL = KEY_INPUT_LCONTROL	;
      static const int RCONTROL = KEY_INPUT_RCONTROL	; 
      static const int ESCAPE = KEY_INPUT_ESCAPE	; 
      static const int SPACE = KEY_INPUT_SPACE	; 
      static const int PGUP = KEY_INPUT_PGUP	; 
      static const int PGDN = KEY_INPUT_PGDN	;
      static const int END = KEY_INPUT_END	; 
      static const int HOME = KEY_INPUT_HOME	;
      static const int LEFT = KEY_INPUT_LEFT	; 
      static const int UP = KEY_INPUT_UP	; 
      static const int RIGHT = KEY_INPUT_RIGHT	; 
      static const int DOWN = KEY_INPUT_DOWN	; 
      static const int INSERT = KEY_INPUT_INSERT	; 
      static const int _DELETE = KEY_INPUT_DELETE	;

      static const int MINUS = KEY_INPUT_MINUS	; 
      static const int YEN = KEY_INPUT_YEN	; 
      static const int PREVTRACK = KEY_INPUT_PREVTRACK	; 
      static const int PERIOD = KEY_INPUT_PERIOD	;
      static const int SLASH = KEY_INPUT_SLASH	;
      static const int LALT = KEY_INPUT_LALT	;
      static const int RALT = KEY_INPUT_RALT	; 
      static const int SCROLL = KEY_INPUT_SCROLL	; 
      static const int SEMICOLON = KEY_INPUT_SEMICOLON	;
      static const int COLON = KEY_INPUT_COLON	; 
      static const int LBRACKET = KEY_INPUT_LBRACKET	;
      static const int RBRACKET = KEY_INPUT_RBRACKET	; 
      static const int AT = KEY_INPUT_AT	; 
      static const int BACKSLASH = KEY_INPUT_BACKSLASH	; 
      static const int COMMA = KEY_INPUT_COMMA	; 
      static const int CAPSLOCK = KEY_INPUT_CAPSLOCK	;
      static const int PAUSE = KEY_INPUT_PAUSE	; 

      static const int NUMPAD0 = KEY_INPUT_NUMPAD0	;
      static const int NUMPAD1 = KEY_INPUT_NUMPAD1	; 
      static const int NUMPAD2 = KEY_INPUT_NUMPAD2	; 
      static const int NUMPAD3 = KEY_INPUT_NUMPAD3	; 
      static const int NUMPAD4 = KEY_INPUT_NUMPAD4	; 
      static const int NUMPAD5 = KEY_INPUT_NUMPAD5	; 
      static const int NUMPAD6 = KEY_INPUT_NUMPAD6	; 
      static const int NUMPAD7 = KEY_INPUT_NUMPAD7	; 
      static const int NUMPAD8 = KEY_INPUT_NUMPAD8	; 
      static const int NUMPAD9 = KEY_INPUT_NUMPAD9	; 
      static const int MULTIPLY = KEY_INPUT_MULTIPLY	; 
      static const int ADD = KEY_INPUT_ADD	; 
      static const int SUBTRACT = KEY_INPUT_SUBTRACT	;
      static const int DECIMAL = KEY_INPUT_DECIMAL	; 
      static const int DIVIDE = KEY_INPUT_DIVIDE	; 
      static const int NUMPADENTER = KEY_INPUT_NUMPADENTER	; 

      static const int F1 = KEY_INPUT_F1	; 
      static const int F2 = KEY_INPUT_F2	;
      static const int F3 = KEY_INPUT_F3	; 
      static const int F4 = KEY_INPUT_F4	; 
      static const int F5 = KEY_INPUT_F5	; 
      static const int F6 = KEY_INPUT_F6	; 
      static const int F7 = KEY_INPUT_F7	;
      static const int F8 = KEY_INPUT_F8	; 
      static const int F9 = KEY_INPUT_F9	; 
      static const int F10 = KEY_INPUT_F10	; 
      static const int F11 = KEY_INPUT_F11	; 
      static const int F12 = KEY_INPUT_F12	; 

      static const int A = KEY_INPUT_A	;  
      static const int B = KEY_INPUT_B	;  
      static const int C = KEY_INPUT_C	;  
      static const int D = KEY_INPUT_D	;  
      static const int E = KEY_INPUT_E	;  
      static const int F = KEY_INPUT_F	;  
      static const int G = KEY_INPUT_G	;  
      static const int H = KEY_INPUT_H	;  
      static const int I = KEY_INPUT_I	;  
      static const int J = KEY_INPUT_J	;  
      static const int K = KEY_INPUT_K	;  
      static const int L = KEY_INPUT_L	;  
      static const int M = KEY_INPUT_M	; 
      static const int N = KEY_INPUT_N	;  
      static const int O = KEY_INPUT_O	;  
      static const int P = KEY_INPUT_P	; 
      static const int Q = KEY_INPUT_Q	;  
      static const int R = KEY_INPUT_R	;  
      static const int S = KEY_INPUT_S	;  
      static const int T = KEY_INPUT_T	;  
      static const int U = KEY_INPUT_U	;  
      static const int V = KEY_INPUT_V	;  
      static const int W = KEY_INPUT_W	;  
      static const int X = KEY_INPUT_X	;  
      static const int Y = KEY_INPUT_Y	;  
      static const int Z = KEY_INPUT_Z	;  
      static const int NUM0 = KEY_INPUT_0	;  
      static const int NUM1 = KEY_INPUT_1	;  
      static const int NUM2 = KEY_INPUT_2	;  
      static const int NUM3 = KEY_INPUT_3	;  
      static const int NUM4 = KEY_INPUT_4	;  
      static const int NUM5 = KEY_INPUT_5	;  
      static const int NUM6 = KEY_INPUT_6	;  
      static const int NUM7 = KEY_INPUT_7	;  
      static const int NUM8 = KEY_INPUT_8	;  
      static const int NUM9 = KEY_INPUT_9	; 


	  void Loop(){
			 //�S�ẴL�[�̉�����Ԃ��擾
			char buf[256];
			GetHitKeyStateAll( buf ) ;
			for(int i=0;i<256;i++){
				if( buf[i] == 0 ){
					count[i] += 1.0f;
				}else if( buf[i] == 1 ){
					if(count[i] < 1.0f){
						count[i] = 0.5f;
					}else{
						count[i] = 0.0f;
					}
				}
			}
	  }
	  bool GetPush(int keyCode){
			 //�L�[�R�[�h�`�F�b�N
			 if( keyCode < 256 && keyCode >= 0 ){
				if( count[keyCode] < 1.0f ){
					return true;
				}else{
					return false;
				}
			 }else{
				WarningSK("CKey::GetPush�̈����ɕs���ȃL�[�R�[�h�����͂���܂���\n�L�[�R�[�h�@�F�@%d",keyCode);
				return false;
			 }
		 }
		 bool GetDown(int keyCode){
			 //�L�[�R�[�h�`�F�b�N
			 if( keyCode < 256 && keyCode >= 0 ){
				if( count[keyCode] == 0.0f ){
					return true;
				}else{
					return false;
				}
			 }else{
				WarningSK("CKey::GetDown�̈����ɕs���ȃL�[�R�[�h�����͂���܂���\n�L�[�R�[�h�@�F�@%d",keyCode);
				return false;
			 }
		 }
		 bool GetUp(int keyCode){
			 //�L�[�R�[�h�`�F�b�N
			 if( keyCode < 256 && keyCode >= 0 ){
				if( count[keyCode] == 1.5f ){
					return true;
				}else{
					return false;
				}
			 }else{
				WarningSK("CKey::GetUp�̈����ɕs���ȃL�[�R�[�h�����͂���܂���\n�L�[�R�[�h�@�F�@%d",keyCode);
				return false;
			 }
		 }
		 int GetCount(int keyCode){
			//�L�[�R�[�h�`�F�b�N
			 if( keyCode < 256 && keyCode >= 0 ){
				return (int)(count[keyCode]);
			 }else{
				WarningSK("CKey::GetCount�̈����ɕs���ȃL�[�R�[�h�����͂���܂���\n�L�[�R�[�h�@�F�@%d",keyCode);
				return -1;
			 }
		 }
	private:
		 float count[256];
};
//�}�E�X��`�N���X
class CMouse{
public:
	CMouseIn Off( int _x1 , int _y1 , int _x2 , int _y2 ){

		CMouseIn temp;

		temp.x1 = _x1;
		temp.x2 = _x2;
		temp.y1 = _y1;
		temp.y2 = _y2;

		temp.type = MOUSE_OFF;

		return temp;
	}
	bool GetOff( int _x1 , int _y1 , int _x2 , int _y2 ){
		if(_x1>mouseX && _x2<mouseX ){
			if(_y1>mouseY && _y2<mouseY){
				return true;
			}
		}
		return false;
	}
	CpMouseIn Off( int *_x1 , int *_y1 , int *_x2 , int *_y2 ){

		CpMouseIn temp;

		temp.x1 = _x1;
		temp.x2 = _x2;
		temp.y1 = _y1;
		temp.y2 = _y2;

		temp.type = MOUSE_OFF;

		return temp;
	}
	bool GetOff( int *_x1 , int *_y1 , int *_x2 , int *_y2 ){
		if(*_x1>mouseX && *_x2<mouseX ){
			if(*_y1>mouseY && *_y2<mouseY){
				return true;
			}
		}
		return false;
	}
	CMouseIn On( int _x1 , int _y1 , int _x2 , int _y2 ){
	
		CMouseIn temp;

		temp.x1 = _x1;
		temp.x2 = _x2;
		temp.y1 = _y1;
		temp.y2 = _y2;

		temp.type = MOUSE_ON;

		return temp;

	}
	bool GetOn( int _x1 , int _y1 , int _x2 , int _y2 ){
		if(_x1<mouseX && _x2>mouseX ){
			if(_y1<mouseY && _y2>mouseY){
				return true;
			}
		}
		return false;
	}
	CpMouseIn On( int *_x1 , int *_y1 , int *_x2 , int *_y2 ){
	
		CpMouseIn temp;

		temp.x1 = _x1;
		temp.x2 = _x2;
		temp.y1 = _y1;
		temp.y2 = _y2;

		temp.type = MOUSE_ON;

		return temp;

	}
	bool GetOn( int *_x1 , int *_y1 , int *_x2 , int *_y2 ){
		if(*_x1<mouseX && *_x2>mouseX ){
			if(*_y1<mouseY && *_y2>mouseY){
				return true;
			}
		}
		return false;
	}
	CMouseIn Click( int _x1 , int _y1 , int _x2 , int _y2 ){
		
		CMouseIn temp;

		temp.x1 = _x1;
		temp.x2 = _x2;
		temp.y1 = _y1;
		temp.y2 = _y2;

		temp.type = MOUSE_CLICK;

		return temp;

	}
	bool GetClick( int _x1 , int _y1 , int _x2 , int _y2 ){
		if(_x1<mouseX && _x2>mouseX ){
			if(_y1<mouseY && _y2>mouseY){
				if(mouseInput && !preMouseInput ){
					return true;			
				} 
			}
		}
		return false;
	}

	CpMouseIn Click( int *_x1 , int *_y1 , int *_x2 , int *_y2 ){
		
		CpMouseIn temp;

		temp.x1 = _x1;
		temp.x2 = _x2;
		temp.y1 = _y1;
		temp.y2 = _y2;

		temp.type = MOUSE_CLICK;

		return temp;

	}
	bool GetClick( int *_x1 , int *_y1 , int *_x2 , int *_y2 ){
		if(*_x1<mouseX && *_x2>mouseX ){
			if(*_y1<mouseY && *_y2>mouseY){
				if(mouseInput && !preMouseInput ){
					return true;			
				} 
			}
		}
		return false;
	}
	CMouseIn Release( int _x1 , int _y1 , int _x2 , int _y2 ){
		
		CMouseIn temp;

		temp.x1 = _x1;
		temp.x2 = _x2;
		temp.y1 = _y1;
		temp.y2 = _y2;

		temp.type = MOUSE_RELEASE;

		return temp;
	}
	bool GetRelease( int _x1 , int _y1 , int _x2 , int _y2 ){
		if(_x1<mouseX && _x2>mouseX ){
			if(_y1<mouseY && _y2>mouseY){
				if( !mouseInput && preMouseInput ){
					return true;
				} 
			}	
		}
		return false;
	}
	CpMouseIn Release( int *_x1 , int *_y1 , int *_x2 , int *_y2 ){
		
		CpMouseIn temp;

		temp.x1 = _x1;
		temp.x2 = _x2;
		temp.y1 = _y1;
		temp.y2 = _y2;

		temp.type = MOUSE_RELEASE;

		return temp;
	}
	bool GetRelease( int *_x1 , int *_y1 , int *_x2 , int *_y2 ){
		if(*_x1<mouseX && *_x2>mouseX ){
			if(*_y1<mouseY && *_y2>mouseY){
				if( !mouseInput && preMouseInput ){
					return true;
				} 
			}	
		}
		return false;
	}
	void Loop(){
		GetMousePoint( &mouseX, &mouseY );
			preMouseInput = mouseInput;
			if(IsLeft){
				mouseInput = (bool)( GetMouseInput() & MOUSE_INPUT_LEFT );
			}else{
				mouseInput = (bool)( GetMouseInput() & MOUSE_INPUT_RIGHT );
			}
	}

	int mouseX,mouseY;
	bool mouseInput,preMouseInput;
	void SetLeft(){
		IsLeft = true;
	}
	void SetRight(){
		IsLeft = false;
	}
	private:
		bool IsLeft;
		/*bool CheckScene(){
		
		}*/
};
//���̓C�x���g��`�N���X
class CEvent{
public:
	CEvent(){
		EVERY_FRAME=FRAME_EVENT;
		LMouse.SetLeft();
		RMouse.SetRight();
	}
	void Loop(){
		key.Loop();
		LMouse.Loop();
		RMouse.Loop();
	}
	char EVERY_FRAME;
	CKey key;
	CMouse LMouse;
	CMouse RMouse;
private:
};
extern CEvent Event;
//���̓C�x���g�Ǘ��N���X
class CInput{
public:
	CInput(){
		useMouse = true;
		useKey = true;
	}
	
	void AddEventListener( int inputCode , void func() ){
				
				keyTemp.keyCode=inputCode;
				keyTemp.pFunc=func;
				keyTask.push_back(keyTemp);

	}
	void RemoveEventListener( int inputCode , void func()  ){

		vector< CKeyIn >::iterator it = keyTask.begin();

		while( ( it != keyTask.end() ) ){

			if( it->keyCode == inputCode && it->pFunc == func  ){

				keyTask.erase( it );
				break;
			}
			it++;
		}
		
	}
	void AddEventListener( CMouseIn input , void func()  ){

				mouseTemp=input;
				mouseTemp.pFunc=func;
				mouseTask.push_back(mouseTemp);
				
	}
	bool RemoveEventListener( CMouseIn input , void func()  ){

		vector< CMouseIn >::iterator it = mouseTask.begin();

		while( ( it != mouseTask.end() ) ){

			if( it->pFunc == func && it->type == input.type && it->x1 == input.x1 && it->x2 == input.x2 && it->y1 == input.y1 && it->y2 == input.y2  ){

				mouseTask.erase( it );
				break;
			}
			it++;
		}
		
	}
	void AddEventListener( CpMouseIn input , void func()  ){

				pMouseTemp=input;
				pMouseTemp.pFunc=func;
				pMouseTask.push_back(pMouseTemp);
				
	}
	void RemoveEventListener( CpMouseIn input , void func()  ){

		vector< CpMouseIn >::iterator it = pMouseTask.begin();

		while( ( it != pMouseTask.end() ) ){

			if( it->pFunc == func && it->type == input.type && it->x1 == input.x1 && it->x2 == input.x2 && it->y1 == input.y1 && it->y2 == input.y2  ){

				pMouseTask.erase( it );
				break;
			}
			it++;
		}
	}
	void AddEventListener( char input , void func()  ){
			frameTemp.pFunc=func;
			frameTask.push_back(frameTemp);
			
	}
	void RemoveEventListener( char input , void func()  ){

		vector< CFrame >::iterator it = frameTask.begin();

		while( ( it != frameTask.end() ) ){

			if( it->pFunc ==  func  ){

				frameTask.erase( it );
				break;
			}
			it++;
		}
		
	}
	void AddEventListener( bool* input , void func()  ){
			boolTemp.pFunc=func;
			boolTemp.pBool=input;
			boolTask.push_back(boolTemp);
			
	}
	void RemoveEventListener( bool* input , void func()  ){

		vector< CBoolean >::iterator it = boolTask.begin();

		while( ( it != boolTask.end() ) ){

			if( it->pBool == input && it->pFunc == func  ){

				boolTask.erase( it );
				break;
			}
			it++;
		}
	
	}	

	void Loop(){

		
		//KEY
		if(useKey){


			vector<CKeyIn>::iterator it=keyTask.begin();

			while( it != keyTask.end() ) {
				if(CheckHitKey(it->keyCode)){

					CKeyIn temp=*it;
					temp.pFunc();

				}
				it++;
			}

			

			
		}
		
		//MOUSE
		if(useMouse){

			GetMousePoint( &mouseX, &mouseY );
			preMouseInput = mouseInput;
			mouseInput = (bool)( GetMouseInput() & MOUSE_INPUT_LEFT );

			vector<CMouseIn>::iterator it1=mouseTask.begin();

			while( it1 != mouseTask.end() ) {

				CMouseIn temp = *it1;
			
				switch(temp.type){
				
				case MOUSE_OFF :
					if(temp.x1>mouseX && temp.x2<mouseX ){
						if(temp.y1>mouseY && temp.y2<mouseY){
							
								temp.pFunc();
							
						}
					}
					break;
				case MOUSE_ON :
					if(temp.x1<mouseX && temp.x2>mouseX ){
						if(temp.y1<mouseY && temp.y2>mouseY){
							
								temp.pFunc();
							
						}
					}
					break;

				case MOUSE_PUSH :
					if(temp.x1<mouseX && temp.x2>mouseX ){
						if(temp.y1<mouseY && temp.y2>mouseY){
							if(mouseInput){
								
									temp.pFunc();
								
							}
						}
					} 
					break;
				case MOUSE_CLICK :
					if(temp.x1<mouseX && temp.x2>mouseX ){
						if(temp.y1<mouseY && temp.y2>mouseY){
							if(mouseInput && !preMouseInput ){
								
									temp.pFunc();
								
							} 
						}
					}
					break;
				case MOUSE_RELEASE :
					if(temp.x1<mouseX && temp.x2>mouseX ){
						if(temp.y1<mouseY && temp.y2>mouseY){
							if( !mouseInput && preMouseInput ){
								
									temp.pFunc();
								
							} 
						}	
					}
					break;
				default :
					break;
				}
				it1++;
			}


			vector<CpMouseIn>::iterator it11 =pMouseTask.begin();

				while( it11 != pMouseTask.end() ) {

					CpMouseIn temp = *it11;
					
					
					switch(temp.type){
				
					case MOUSE_OFF :
						if( *(temp.x1) > mouseX && *(temp.x2) < mouseX ){
							if( *(temp.y1) > mouseY && *(temp.y2) < mouseY ){
								
									temp.pFunc();
								
							}
						}
						break;
					case MOUSE_ON :
						if( *(temp.x1) < mouseX && *(temp.x2) > mouseX ){
							if( *(temp.y1) < mouseY && *(temp.y2) > mouseY){
								
									temp.pFunc();
								
							} 
						} 
						break;

					case MOUSE_PUSH :
						if( *(temp.x1) < mouseX && *(temp.x2) > mouseX ){
							if( *(temp.y1) < mouseY && *(temp.y2) > mouseY ){
								if( mouseInput ){
									
										temp.pFunc();
									
								} 
							}
						} 
						break;
					case MOUSE_CLICK :
						if( *(temp.x1) < mouseX && *(temp.x2) > mouseX ){
							if( *(temp.y1) < mouseY && *(temp.y2) > mouseY ){
								if( mouseInput && !preMouseInput ){
									
										temp.pFunc();
									
								} 
							} 
						} 
						break;
					case MOUSE_RELEASE :
						if( *(temp.x1) < mouseX && *(temp.x2) > mouseX ){
							if( *(temp.y1) < mouseY && *(temp.y2) > mouseY ){
								if( !mouseInput && preMouseInput ){
									
										temp.pFunc();
									
								}	
							} 
						} 
						break;
					default :
						break;
					}
					it11++;
				}
			}


		vector<CFrame>::iterator it2 = frameTask.begin();

		while( it2 != frameTask.end() ) {
			CFrame temp=*it2;
			temp.pFunc();
			it2++;
		}

		vector<CBoolean>::iterator it3=boolTask.begin();

		while( it3 != boolTask.end() ) {
			
			CBoolean temp=*it3;

			if(*(temp.pBool)){
			
				temp.pFunc();

			}

			it3++;
		}

	}//end of void Loop()
	void DrawLoop(){
		//KEY
		if(useKey){


			vector<CKeyIn>::iterator it=keyTask_Draw.begin();

			while( it != keyTask_Draw.end() ) {
				if(CheckHitKey(it->keyCode)){

					CKeyIn temp=*it;
					temp.pFunc();

				}
				it++;
			}

			
		}
		
		//MOUSE
		if(useMouse){

			vector<CMouseIn>::iterator it1=mouseTask_Draw.begin();

			while( it1 != mouseTask_Draw.end() ) {

				CMouseIn temp = *it1;
			
				switch(temp.type){
				
				case MOUSE_OFF :
					if(temp.x1>mouseX && temp.x2<mouseX ){
						if(temp.y1>mouseY && temp.y2<mouseY){
							
								temp.pFunc();
							
						}
					}
					break;
				case MOUSE_ON :
					if(temp.x1<mouseX && temp.x2>mouseX ){
						if(temp.y1<mouseY && temp.y2>mouseY){
							
								temp.pFunc();
							
						}
					}
					break;

				case MOUSE_PUSH :
					if(temp.x1<mouseX && temp.x2>mouseX ){
						if(temp.y1<mouseY && temp.y2>mouseY){
							if(mouseInput){
								
									temp.pFunc();
								
							}
						}
					} 
					break;
				case MOUSE_CLICK :
					if(temp.x1<mouseX && temp.x2>mouseX ){
						if(temp.y1<mouseY && temp.y2>mouseY){
							if(mouseInput && !preMouseInput ){
								
									temp.pFunc();
								
							} 
						}
					}
					break;
				case MOUSE_RELEASE :
					if(temp.x1<mouseX && temp.x2>mouseX ){
						if(temp.y1<mouseY && temp.y2>mouseY){
							if( !mouseInput && preMouseInput ){
								
									temp.pFunc();
								
							} 
						}	
					}
					break;
				default :
					break;
				}
				it1++;
			}

			vector<CpMouseIn>::iterator it11 =pMouseTask_Draw.begin();

				while( it11 != pMouseTask_Draw.end() ) {

					CpMouseIn temp = *it11;
					
					
					switch(temp.type){
				
					case MOUSE_OFF :
						if( *(temp.x1) > mouseX && *(temp.x2) < mouseX ){
							if( *(temp.y1) > mouseY && *(temp.y2) < mouseY ){
								
									temp.pFunc();
								
							}
						}
						break;
					case MOUSE_ON :
						if( *(temp.x1) < mouseX && *(temp.x2) > mouseX ){
							if( *(temp.y1) < mouseY && *(temp.y2) > mouseY){
								
									temp.pFunc();
								
							} 
						} 
						break;

					case MOUSE_PUSH :
						if( *(temp.x1) < mouseX && *(temp.x2) > mouseX ){
							if( *(temp.y1) < mouseY && *(temp.y2) > mouseY ){
								if( mouseInput ){
									
										temp.pFunc();
									
								} 
							}
						} 
						break;
					case MOUSE_CLICK :
						if( *(temp.x1) < mouseX && *(temp.x2) > mouseX ){
							if( *(temp.y1) < mouseY && *(temp.y2) > mouseY ){
								if( mouseInput && !preMouseInput ){
									
										temp.pFunc();
									
								} 
							} 
						} 
						break;
					case MOUSE_RELEASE :
						if( *(temp.x1) < mouseX && *(temp.x2) > mouseX ){
							if( *(temp.y1) < mouseY && *(temp.y2) > mouseY ){
								if( !mouseInput && preMouseInput ){
									
										temp.pFunc();
									
								}	
							} 
						} 
						break;
					default :
						break;
					}
					it11++;
				}
			}

			
		//���[�v
		vector<CFrame>::iterator it2=frameTask_Draw.begin();

		while( it2 != frameTask_Draw.end() ) {
			CFrame temp=*it2;
			temp.pFunc();
			it2++;
		}
		

		//bool
		vector<CBoolean>::iterator it3=boolTask_Draw.begin();

		while( it3 != boolTask_Draw.end() ) {
			
			CBoolean temp=*it3;

			if(*(temp.pBool)){
			
				temp.pFunc();

			}

			it3++;
		}
	}//end of DrawLoop()

	bool useKey,useMouse;
	int mouseX,mouseY;
private:
	CKeyIn keyTemp;
	vector<CKeyIn> keyTask;

	CMouseIn mouseTemp;
	vector<CMouseIn> mouseTask;

	CpMouseIn pMouseTemp;
	vector<CpMouseIn> pMouseTask;

	CFrame frameTemp;
	vector<CFrame> frameTask;

	CBoolean boolTemp;
	vector<CBoolean> boolTask;

	vector<CKeyIn> keyTask_Draw;
	vector<CMouseIn> mouseTask_Draw;
	vector<CpMouseIn> pMouseTask_Draw;
	vector<CFrame> frameTask_Draw;
	vector<CBoolean> boolTask_Draw;

	bool mouseInput,preMouseInput;
};

class CButton{
public:
	CButton(){
		IsUseGraph = false;
		IsReact = false;
	}
	char *title;
	int x1,x2,y1,y2;
	int backColor,stringColor;
	int graphHandle;
	bool IsUseGraph;
	int graphHandle_on;
	int graphHandle_off;
	bool IsReact;			//�}�E�X�ɔ������邩�ۂ�
};
class CpButton{
public:
	CpButton(){
		IsUseGraph = false;
		IsReact =false;
	}
	char *title;
	int *x1,*x2,*y1,*y2;
	int backColor,stringColor;
	int graphHandle;
	bool IsUseGraph;
	int graphHandle_on;
	int graphHandle_off;
	bool IsReact;			//�}�E�X�ɔ������邩�ۂ�
};

//�V�[���N���X
class CScene{
public:
	CScene(){
		serialNum = sceneNum;
		sceneNum++;
		focus = false;
		sceneChild = NULL;
	}
	void Loop(){
		if(!focus){
			input.useKey = false;
			input.useMouse = false;
		}
		input.Loop();
		input.DrawLoop();

		collision.Loop();
		collision.DrawLoop();

		ButtonLoop();

		if( sceneChild != NULL ){
			sceneChild->Loop();
		}
		if(focus){
			input.useKey = true;
			input.useMouse = true;
		}
	}
	void ButtonLoop(){
		

		vector<CButton>::iterator it = buttonChild.begin();
		if( buttonChild.size() != 0 ){
			while( it != buttonChild.end() ) {
				if(it->IsUseGraph){
					if(it->IsReact){
						if(Event.LMouse.GetOn((it->x1) , (it->y1) , (it->x2) , (it->y2))){
							DrawExtendGraph( (it->x1) , (it->y1) , (it->x2) , (it->y2) , (it->graphHandle_on) , true );
						}else{
							DrawExtendGraph( (it->x1) , (it->y1) , (it->x2) , (it->y2) , (it->graphHandle_off) , true );
						}
					}else{
						DrawExtendGraph( (it->x1) , (it->y1) , (it->x2) , (it->y2) , (it->graphHandle) , true );
					}
				}else{
					
					DrawBox(it->x1,it->y1,it->x2,it->y2,it->backColor,TRUE);
					DrawCenterString((it->x1+it->x2)/2,(it->y1+it->y2)/2-10,it->stringColor,it->title);
				}
				it++;
			}
		}
		vector<CpButton>::iterator it1 = pButtonChild.begin();
		if( pButtonChild.size() != 0 ){
			while( it1 != pButtonChild.end() ) {
				if(it1->IsUseGraph){
					if(it1->IsReact){
						if(Event.LMouse.GetOn(*(it1->x1) , *(it1->y1) , *(it1->x2) , *(it1->y2))){
							DrawExtendGraph( *(it1->x1) , *(it1->y1) , *(it1->x2) , *(it1->y2) , (it1->graphHandle_on) , true );
						}else{
							DrawExtendGraph( *(it1->x1) , *(it1->y1) , *(it1->x2) , *(it1->y2) , (it1->graphHandle_off) , true );
						}
					}else{
						DrawExtendGraph( *(it1->x1) , *(it1->y1) , *(it1->x2) , *(it1->y2) , (it1->graphHandle) , true );
					}
				}else{
					DrawBox( *(it1->x1) , *(it1->y1) , *(it1->x2) , *(it1->y2) , it1->backColor , TRUE );
					DrawCenterString( (*(it1->x1) + *(it1->x2) ) / 2 , ( *(it1->y1) + *(it1->y2) ) / 2 - 10 , it1->stringColor , it1->title );
				}
				it1++;
			}
		}
		
	}
	CCollisionManager collision;
	CInput input;
	vector<CButton> buttonChild;
	vector<CpButton> pButtonChild;
	CScene *sceneChild;
	
	void SetFocus(bool _focus){
		focus = _focus;
	}
	bool GetFocus(){
		return focus;
	}
	void AddChild(CScene *_scene){
		if(focus){
			if( sceneChild != NULL ){
				RemoveChild();
			}
			//�t�H�[�J�X�̈ڍs
			this->SetFocus(false);
			_scene->SetFocus(true);
			//�ǉ�
			sceneChild = _scene;
		}else{
			WarningSK("���ݗL���ł͂Ȃ��V�[���ɓ���q�̃V�[����ǉ����邱�Ƃ͂ł��܂���(CScene::AddChild)");
		}

	}
	void RemoveChild(){
		if( sceneChild != NULL ){
			//�t�H�[�J�X�̈ڍs
			sceneChild->SetFocus(false);
			this->SetFocus(true);
			//�폜
			sceneChild = NULL;
		}else{
			WarningSK("CScene::RemoveChild���Ăяo����܂�����CScene::sceneChild�ɃV�[��������܂���");
		}
	}
	void SetButton( int x1 , int y1 , int x2 , int y2 , int backColor , char *title , int stringColor , void (*pFunc)() ){
		CButton temp;
		temp.IsUseGraph = false;
		temp.title = title;
		temp.x1 = x1;
		temp.x2 = x2;
		temp.y1 = y1;
		temp.y2 = y2;
		temp.backColor = backColor;
		temp.stringColor = stringColor;

		buttonChild.push_back( temp );
		
		this->input.AddEventListener( Event.LMouse.Click( x1 , y1 , x2 , y2 ) , pFunc );
	}
	void SetButton( int x1 , int y1 , int x2 , int y2 , int graph, void (*pFunc)() ){
		CButton temp;
		
		temp.IsUseGraph = true;
		temp.x1 = x1;
		temp.x2 = x2;
		temp.y1 = y1;
		temp.y2 = y2;
		temp.graphHandle = graph;

		buttonChild.push_back( temp );
		
		this->input.AddEventListener( Event.LMouse.Click( x1 , y1 , x2 , y2 ) , pFunc );
	}
	void SetButton( int x1 , int y1 , int x2 , int y2 , char* graphPath, void (*pFunc)() ){
		CButton temp;
		
		temp.IsUseGraph = true;
		temp.x1 = x1;
		temp.x2 = x2;
		temp.y1 = y1;
		temp.y2 = y2;
		temp.graphHandle = LoadGraph(graphPath);
		if( temp.graphHandle == -1 ){
			MessageBox(NULL,"error : SetButton���\�b�h��char *graphPath�̃O���t�B�b�N�̃p�X�ɖ����Ȓl�����͂���܂���","�������C�u����",MB_OK);
		}

		buttonChild.push_back( temp );
		
		this->input.AddEventListener( Event.LMouse.Click( x1 , y1 , x2 , y2 ) , pFunc );
	}
	void SetButton( int x1 , int y1 , int x2 , int y2 , char* Off_graphPath , char* On_graphPath , void (*pFunc)() ){
		CButton temp;
		
		temp.IsUseGraph = true;
		temp.IsReact = true;
		temp.x1 = x1;
		temp.x2 = x2;
		temp.y1 = y1;
		temp.y2 = y2;
		temp.graphHandle_off = LoadGraph(Off_graphPath);
		temp.graphHandle_on = LoadGraph(On_graphPath);
		if( temp.graphHandle_off == -1 ){
			MessageBox(NULL,"error : SetButton���\�b�h��char *Off_graphPath�̃O���t�B�b�N�̃p�X�ɖ����Ȓl�����͂���܂���","�������C�u����",MB_OK);
		}
		if( temp.graphHandle_on == -1 ){
			MessageBox(NULL,"error : SetButton���\�b�h��char *On_graphPath�̃O���t�B�b�N�̃p�X�ɖ����Ȓl�����͂���܂���","�������C�u����",MB_OK);
		}

		this->input.AddEventListener( Event.LMouse.Click( x1 , y1 , x2 , y2 ) , pFunc );

		buttonChild.push_back( temp );
	}
	void SetButton( int *x1 , int *y1 , int *x2 , int *y2 , int backColor , char *title , int stringColor , void (*pFunc)() ){
		CpButton temp;
		temp.IsUseGraph = false;
		temp.title = title;
		temp.x1 = x1;
		temp.x2 = x2;
		temp.y1 = y1;
		temp.y2 = y2;
		temp.backColor = backColor;
		temp.stringColor = stringColor;

		pButtonChild.push_back( temp );

		this->input.AddEventListener( Event.LMouse.Click( x1 , y1 , x2 , y2 ) , pFunc );
	}
	void SetButton( int *x1 , int *y1 , int *x2 , int *y2 , int graph , void (*pFunc)() ){
		CpButton temp;
		temp.IsUseGraph = true;
		
		temp.x1 = x1;
		temp.x2 = x2;
		temp.y1 = y1;
		temp.y2 = y2;
		
		temp.graphHandle = graph;

		pButtonChild.push_back( temp );

		this->input.AddEventListener( Event.LMouse.Click( x1 , y1 , x2 , y2 ) , pFunc );
	}
	void SetButton( int *x1 , int *y1 , int *x2 , int *y2 , char* graphPath , void (*pFunc)() ){
		CpButton temp;
		
		temp.IsUseGraph = true;
		temp.x1 = x1;
		temp.x2 = x2;
		temp.y1 = y1;
		temp.y2 = y2;
		temp.graphHandle = LoadGraph(graphPath);
		if( temp.graphHandle == -1 ){
			MessageBox(NULL,"error : SetButton���\�b�h��char graphPath�̃O���t�B�b�N�̃p�X�ɖ����Ȓl�����͂���܂���","�������C�u����",MB_OK);
		}

		pButtonChild.push_back( temp );
		
		this->input.AddEventListener( Event.LMouse.Click( x1 , y1 , x2 , y2 ) , pFunc );
	}
	void SetButton( int *x1 , int *y1 , int *x2 , int *y2 , char* Off_graphPath , char* On_graphPath , void (*pFunc)() ){
		CpButton temp;
		
		temp.IsUseGraph = true;
		temp.IsReact = true;
		temp.x1 = x1;
		temp.x2 = x2;
		temp.y1 = y1;
		temp.y2 = y2;
		temp.graphHandle_off = LoadGraph(Off_graphPath);
		temp.graphHandle_on = LoadGraph(On_graphPath);
		if( temp.graphHandle_off == -1 ){
			MessageBox(NULL,"error : SetButton���\�b�h��char *Off_graphPath�̃O���t�B�b�N�̃p�X�ɖ����Ȓl�����͂���܂���","�������C�u����",MB_OK);
		}
		if( temp.graphHandle_on == -1 ){
			MessageBox(NULL,"error : SetButton���\�b�h��char *On_graphPath�̃O���t�B�b�N�̃p�X�ɖ����Ȓl�����͂���܂���","�������C�u����",MB_OK);
		}

		this->input.AddEventListener( Event.LMouse.Click( x1 , y1 , x2 , y2 ) , pFunc );

		pButtonChild.push_back( temp );
	}
	//�������C�u���������֐��i�g�p�֎~�j
	void ResetSceneNum(){
		sceneNum = 1;
	}
	unsigned int GetSerialNum(){
		return serialNum;
	}
private:
	bool focus;
	static unsigned int sceneNum;
	unsigned int serialNum;
};
//�Q�[���V�X�e�������N���X
class CGame{
public:
	CGame(){
		useDrawLoopFlag =true;
		rootScene.ResetSceneNum();
	}
	~CGame(){
/*
		if(memoryLeakChecker!=0){
			char info[256];
			sprintf(info,"error : %d���̃��������[�N���������Ă��܂�",memoryLeakChecker);
			MessageBox(NULL,info,"MemoryLeakChecher",MB_OK);
		}
		*/
		rootScene.SetFocus(true);
	}
	void awake(){

	}
	void AddChild(CScene* _scene){
		
		rootScene.SetFocus(false);

		_scene->SetFocus(true);
		sceneChild.push_back(_scene);

	}
	void RemoveChild(CScene* _scene){
		_scene->SetFocus(false);
		vector<CScene*>::iterator it=sceneChild.begin();

		while( it != sceneChild.end() ) {
			if(*it==_scene){
				
				sceneChild.erase(it);
				break;
			}
			it++;
		}

		if(sceneChild.empty()){
			rootScene.SetFocus(true);
		}
		

	}
	void removeChild(){
		sceneChild.front()->SetFocus(false);
		sceneChild.pop_back();
		
		if(sceneChild.empty()){
			rootScene.SetFocus(true);
		}
	}
	void Loop(){
	
			Event.Loop();
		

		if( !sceneChild.size() == 0 ){

			sceneChild.back()->Loop();

		}else{
			
			rootScene.Loop();

		}
	}

	
	void SetUseDrawLoop(bool flag){
		useDrawLoopFlag = flag;
	}
	bool GetUseDrawLoop(){
		return useDrawLoopFlag;
	}
	vector<CScene*> sceneChild;
	CScene rootScene;
private:
	bool useDrawLoopFlag;
	
	
};

//�Q�[���N���X


