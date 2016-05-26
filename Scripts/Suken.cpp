#include "../Suken.h"
#define _CRT_SECURE_NO_WARNINGS


CSystem System;
CGame game;
CEvent Event;


bool SelectOpenFile(  char *filename , char *filetype)
{
    OPENFILENAME ofn;

    ZeroMemory(&ofn, sizeof(OPENFILENAME));
    ofn.lStructSize = sizeof(OPENFILENAME);
    //ofn.hwndOwner = hWnd;
    ofn.lpstrFilter = filetype;
    ofn.lpstrFile = filename;
    ofn.nMaxFile = MAX_PATH;
    ofn.nMaxFileTitle = 100;
    ofn.Flags = OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
    ofn.lpstrTitle = "�t�@�C�����J��";
    if (!GetOpenFileName(&ofn)) return FALSE; // �L�����Z��

    return TRUE;
}
bool SaveFile(char *filename ,char *filetype){
	static OPENFILENAME     ofn;
    static TCHAR            szPath[ MAX_PATH ];
    static TCHAR            szFile[ MAX_PATH ];
    
    if ( szPath[0] == TEXT('\0') ){
        GetCurrentDirectory( MAX_PATH, szPath );
    }
    if ( ofn.lStructSize == 0 ){
        ofn.lStructSize         = sizeof(OPENFILENAME);
		ofn.hwndOwner           = DxLib::GetMainWindowHandle();
        ofn.lpstrInitialDir     = szPath;       // �����t�H���_�ʒu
        ofn.lpstrFile           = filename;       // �I���t�@�C���i�[
        ofn.nMaxFile            = MAX_PATH;
        ofn.lpstrDefExt         = TEXT(".*");
        ofn.lpstrFilter         = filetype;
        ofn.lpstrTitle          = TEXT("�t�@�C����ۑ����܂��B");
        ofn.Flags               = OFN_FILEMUSTEXIST | OFN_OVERWRITEPROMPT;
    }
    if ( GetSaveFileName(&ofn) ){
        MessageBox( GetMainWindowHandle(), filename, TEXT("�t�@�C������t���ĕۑ�"), MB_OK );
    }

	return true;
}

CSystem::CSystem(){
	startTime = 0;
	count = 0;
	fps = 60.0;		//0���Z��h������
	frame = 0;
	escapeFlag = false;
	targetFps = 0.0f;
	screenShotGrHandleAdress = NULL;
	loadingImgPath[0] = NULL;
}
CSystem::~CSystem(){
	
}
void CSystem::Awake(){
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
int  CSystem::GetLocalStandardTime(){
	return localStandardTime;
}
void CSystem::SetUseThread_Awake(bool flag){
	useThread_AwakeFlag = flag;
}
bool CSystem::GetUseThread_Awake(){
	return useThread_AwakeFlag;
}
void CSystem::SetLoadingGraph(const char *path){
	strcpy(loadingImgPath,path);
}
void CSystem::SetLoadingMinimalTime(int time){
	loadingMinimalTime = time;
}
void CSystem::Wait_Loading(){
	int restTime = loadingMinimalTime - (GetNowCount()-localStandardTime);
	if(restTime > 0){
		WaitTimer(restTime);
	}
}
void CSystem::Update(){
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
void CSystem::Wait(){
		
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
void CSystem::End(){
	DxLib_End();	
	ShellExecute(GetMainWindowHandle() , "open" , "Launcher.exe" , NULL , NULL , SW_SHOW);
}
void CSystem::TakeScreenShot(){
	if(screenShotFlag){
		screenShotFlag = false;
		if(screenShotGrHandleAdress != NULL){
			*screenShotGrHandleAdress = GetDrawScreen();
		}
		screenShotGrHandleAdress = NULL;
	}
}
void CSystem::GetScreenShot(int *GrHandleAdress){
	screenShotFlag = true;
	screenShotGrHandleAdress = GrHandleAdress;
}
void CSystem::Escape(){
	escapeFlag = true;
}
bool CSystem::GetEscapeFlag(){	
	return escapeFlag;
}
int CSystem::GetFrame(){
	return frame;
}
int CSystem::GetNow(){
	return now;
}
float CSystem::GetFps(){
	return fps;
}
int CSystem::GetRefreshRate(){
	return refreshRate;
}
void CSystem::SetTargetFps(float _fps){
	targetFps = _fps;
}
float CSystem::GetTargetFps(){
	return targetFps;
}
//�V�����X���b�h�����B
void CSystem::CreateNewThread( void(*pFunc)() ){
	if(handleChild.empty()){				
		DxLib::SetMultiThreadFlag( true );			//���̂܂܂ł�DxLib��DirectX�̊֌W�Ń}���`�X���b�h�ɂł��Ȃ��̂Őݒ肵�Ă��K�v������
	}
	//�V�����X���b�h���쐬�i�^�uHANDLE�v�̓|�C���^�Ȃ̂�System::CreateNewThread���\�b�h���I�����Ă������I�ɔj������Ȃ��j
	HANDLE handle = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)pFunc, NULL, 0, LPDWORD());

	handleChild.push_back(handle);
}
HDC CSystem::GetDisplayDC(){
	return display;
}
#ifdef USE_LUA
lua_State* CSystem::GetLua(){
	return Lua;
}
#endif

void SukenExecute(char *URL){
		OSVERSIONINFO OSver;
		OSver.dwOSVersionInfoSize =sizeof(OSVERSIONINFO);
		GetVersionEx(&OSver);
		if(OSver.dwMajorVersion < 6 ){//XP�ȉ�
			ShellExecute( NULL, "open", "IExplore",URL, NULL,SW_SHOWNORMAL );
		}else{//Vista�ȏ�
			ShellExecute( NULL, "open",URL, NULL, NULL,SW_SHOWNORMAL );
		}
}

double Scos(int Angle){
	return  cos( (double)Angle * M_PI / 180.0   ) ;
}
double Ssin(int Angle){
	return  sin( (double)Angle * M_PI / 180.0   ) ;
}
double Stan(int Angle){
	return  tan( (double)Angle * M_PI  / 180.0 ) ;
}
int AngleFromRad(double Angle){
	return (int)( Angle * 180 / M_PI) ;
}
int Power2(int x, int y){
    int i,result;
    for( i=1, result = 1; i <= y; i++) {result *= x;}
    return result;
}
int Clng ( char *Str ,int n ){
	char s[10];int ns = 0; int ret = 0;
	while(!(Str[n] == '\0' )  && ns < 10){
		switch (Str[n]){
		case '0': s[ns] = 0 ;ns++;break;case '1': s[ns] = 1 ;ns++;break;  
		case '2': s[ns] = 2 ;ns++;break;case '3': s[ns] = 3 ;ns++;break;  
		case '4': s[ns] = 4 ;ns++;break;case '5': s[ns] = 5 ;ns++;break;  
		case '6': s[ns] = 6 ;ns++;break;case '7': s[ns] = 7 ;ns++;break;  
		case '8': s[ns] = 8 ;ns++;break;case '9': s[ns] = 9 ;ns++;break;   
		}
		n++;
	}
	int ss = 0;ns--;
	while(ns >= 0){
		ret += s[ns] * Power2(10,ss);
		ns--; ss++;
	}
	return ret ;
}
int ClngFrom ( char *Str ,char Word ){
	char s[10];int ns = 0; int ret = 0;
	int n = 0;
	while(!(Str[n] == '\0' || Str[n] == Word )  && ns < 10){n++;}
	while(!(Str[n] == '\0' )  && ns < 10){
		switch (Str[n]){
		case '0': s[ns] = 0 ;ns++;break;case '1': s[ns] = 1 ;ns++;break;  
		case '2': s[ns] = 2 ;ns++;break;case '3': s[ns] = 3 ;ns++;break;  
		case '4': s[ns] = 4 ;ns++;break;case '5': s[ns] = 5 ;ns++;break;  
		case '6': s[ns] = 6 ;ns++;break;case '7': s[ns] = 7 ;ns++;break;  
		case '8': s[ns] = 8 ;ns++;break;case '9': s[ns] = 9 ;ns++;break;   
		}
		n++;
	}
	int ss = 0;ns--;
	while(ns >= 0){
		ret += s[ns] * Power2(10,ss);
		ns--; ss++;
	}
	return ret ;
}
int ClngTo ( char *Str ,char Word ){
	char s[10];int ns = 0; int ret = 0;
	int n = 0;
	while(!(Str[n] == '\0' || Str[n] == Word)  && ns < 10){
		switch (Str[n]){
		case '0': s[ns] = 0 ;ns++;break;case '1': s[ns] = 1 ;ns++;break;  
		case '2': s[ns] = 2 ;ns++;break;case '3': s[ns] = 3 ;ns++;break;  
		case '4': s[ns] = 4 ;ns++;break;case '5': s[ns] = 5 ;ns++;break;  
		case '6': s[ns] = 6 ;ns++;break;case '7': s[ns] = 7 ;ns++;break;  
		case '8': s[ns] = 8 ;ns++;break;case '9': s[ns] = 9 ;ns++;break;   
		}
		n++;
	}
	int ss = 0;ns--;
	while(ns >= 0){
		ret += s[ns] * Power2(10,ss);
		ns--; ss++;
	}
	return ret ;
}
bool CheckWord(char *Str ,char Word ){
	int n = 0 ;
	while(!(Str[n] == '\0' )){
		if(Str[n] == Word )return 1 ;
		n++;
	}
	return 0 ;
}
unsigned long FileGetSize(char *FileName){ 
	int filesize;
	FILE* fp = fopen( FileName, "rb" );
	if (fp ==NULL)return 0;
	fseek( fp, 0L, SEEK_END );
	filesize = ftell( fp );
	fclose( fp );
	return filesize;
}

CCaesar::CCaesar (char finame[],char imname[],int key){
	FileName = finame;Key = key;ImaginaryName = imname; 
}
bool CCaesar::CaesarToBMP(){

	FILE *fi,*fo;int value;
	unsigned long FileSize =FileGetSize(FileName);
	switch(FileSize){case 0:case 4294967295:return 0;}
	fi = fopen(FileName,"rb");if (fi == NULL) return 0;
	fo = fopen(ImaginaryName,"wb");if (fo == NULL) return 0;

	putc(0x42,fo);putc(0x4d,fo);
	putc(0x00,fo);putc(0x00,fo);putc(0x00,fo);putc(0x00,fo);
	putc(0x00,fo);putc(0x00,fo);putc(0x00,fo);putc(0x00,fo);
	putc(0x36,fo);putc(0x00,fo);putc(0x00,fo);putc(0x00,fo);
	putc(0x28,fo);putc(0x00,fo);putc(0x00,fo);putc(0x00,fo);

	putc(0x04,fo);putc(0x00,fo);putc(0x00,fo);putc(0x00,fo);//Width
	//////////////////////////////////////////////////////////Height
	int File4 = (int)(FileSize / 12);
	int FileMod12 = FileSize % 12;
	if(FileMod12 != 0)File4++;
	int F0,F1,F2,F3;
	F3 = (int)(File4 / (Power2(2,24)));
	F2 = (int)((File4 -(F3 * Power2(2,24))) / (Power2(2,16)));
	F1 = (int)((File4 -(F3 * Power2(2,24)) -(F2 * Power2(2,16))) / (Power2(2,8)));
	F0 = File4 - F3 * Power2(2,24) - F2 * Power2(2,16) - F1 * Power2(2,8);

	putc(F0,fo);putc(F1,fo);putc(F2,fo);putc(F3,fo);

	putc(0x01,fo);putc(0x00,fo);putc(0x18,fo);putc(0x00,fo);
	putc(0x00,fo);putc(0x00,fo);putc(0x00,fo);putc(0x00,fo);

	putc(0x00,fo);putc(0x00,fo);putc(0x00,fo);putc(0x00,fo);
	putc(0x00,fo);putc(0x00,fo);putc(0x00,fo);putc(0x00,fo);
	putc(0x00,fo);putc(0x00,fo);putc(0x00,fo);putc(0x00,fo);
	putc(0x00,fo);putc(0x00,fo);putc(0x00,fo);putc(0x00,fo);
	putc(0x00,fo);putc(0x00,fo);putc(0x00,fo);putc(0x00,fo);
	if(FileMod12 != 0){for (int i = 0; i < 12 - FileMod12  ;i++){putc(0x72,fo);}}

	while ((value = getc(fi)) != EOF){putc(value + Key,fo);}
	fclose(fo);fclose(fi);
	remove(FileName);
	return 1;
}
bool CCaesar::CaesarFromBMP(){

	FILE *fi,*fo;int value;
	fo = fopen(ImaginaryName,"rb");if (fo == NULL) return 0;
	fi = fopen(FileName,"wb");if (fi == NULL) return 0;
	for(int i = 0;i<54;i++){value = getc(fo);}
	value = getc(fo);
		while (value == 0x72){value = getc(fo);}
	putc(value- Key,fi);
	while ((value = getc(fo)) != EOF){putc(value- Key,fi);}
	fclose(fo);fclose(fi);
	remove(ImaginaryName);
	return 1;
}
bool CCaesar::CaesarCode(){

	FILE *fi,*fo;int value;
	fi = fopen(FileName,"rb");if (fi == NULL) return 0;
	fo = fopen(ImaginaryName,"wb");if (fo == NULL) return 0;
	
	while ((value = getc(fi)) != EOF){putc(value + Key,fo);}
	fclose(fo);fclose(fi);
	remove(FileName);
	return 1;
}
bool CCaesar::CaesarDecode(){

	FILE *fi,*fo;int value;
	fo = fopen(ImaginaryName,"rb");if (fo == NULL) return 0;
	fi = fopen(FileName,"wb");if (fi == NULL) return 0;

	while ((value = getc(fo)) != EOF){putc(value- Key,fi);}
	fclose(fo);fclose(fi);
	remove(ImaginaryName);
	return 1;
}

CIntData::CIntData(char *_DataName){
	int Len;
	Len = std::strlen (_DataName);
	DataName = new char [Len + 1];
	strcpy(DataName , _DataName);
	DataName[Len] = '\0';
}
void CIntData::NewMake(){
	FILE *fp;
	fp = fopen( DataName , "w+");/////////////��������
	if (fp == NULL){
		DataName = "iMaGiNaRy.imr";
		fp = fopen( DataName , "w+");
	}
	for(int i = 0; i <2000 ;i++){
	fputs("0:0\r\n" , fp);//��������
	}
	fclose(fp);
}
void CIntData::ReadData(){
	FILE *fp;	
	char s[64];
	fp = fopen( DataName , "a"); //�t�@�C���������ɍ쐬or�m��
	if (fp == NULL){
		DataName = "iMaGiNaRy.imr";
		fp = fopen( DataName , "a");
	}	
	fclose(fp);
	fp = fopen( DataName , "r+");/////////////�ǂݍ���
	int n = 0;
	while (fgets(s, 64, fp) != NULL && n < 2000) {
		LeftData[n] = ClngTo(s,':');
		RightData[n] = ClngFrom(s,':');
		n++;
	}
	fclose(fp);
	if(n == 0){NewMake ();ReadData() ;}
}
void CIntData::WriteData(){
	FILE *fp;	
	fp = fopen( DataName , "a"); //�t�@�C���������ɍ쐬or�m��
	if (fp == NULL){
		DataName = "iMaGiNaRy.imr";
		fp = fopen( DataName , "a");
	}	
	fclose(fp);
	fp = fopen( DataName , "r+");/////////////�ǂݍ���
 
	for(int i=0;i<2000;i++){/////////////��������	
	fprintf( fp, "%d:%d\r\n",LeftData[i],RightData[i] );
	}
	fclose(fp);

}

CStrData::CStrData(char *_DataName){
	int Len;
	Len = std::strlen (_DataName);
	DataName = new char [Len];
	std::strcpy(DataName , _DataName);
}
void CStrData::NewMake (){
	FILE *fp;
	fp = fopen( DataName , "w+");/////////////��������
	if (fp == NULL){
		DataName = "ImAgInArY.imr";
		fp = fopen( DataName , "w+");
	}
	for(int i = 0; i <1000 ;i++){
	fputs("NoName\r\n" , fp);//��������
	}
	fclose(fp);
}
void CStrData::ReadData(){
	FILE *fp;	
	fp = fopen( DataName , "a"); 
	if (fp == NULL){
		DataName = "ImAgInArY.imr";
		fp = fopen( DataName , "a");
	}
	fclose(fp);//�t�@�C���������ɍ쐬or�m��
	fp = fopen( DataName , "r+");/////////////�ǂݍ���
	int n = 0;
	while (fgets(Data[n], 128, fp) != NULL && n < 1000 ) {n++;}
	fclose(fp);
	if(n == 0){NewMake ();ReadData(); }
}
void CStrData::WriteData(){
	FILE *fp;	
	fp = fopen( DataName , "a");
	if (fp == NULL){
		DataName = "ImAgInArY.imr";
		fp = fopen( DataName , "a");
	}
	fclose(fp);//�t�@�C���������ɍ쐬or�m��
	fp = fopen( DataName , "r+");/////////////�ǂݍ���
	char s[128];
	for(int i=0;i<1000;i++){/////////////��������
		std::strcpy (s,Data[i]);
		std::strcat (s,"");
		fputs( s ,fp);
		
	}
	fclose(fp);
}

void KEYCHECK(char &CC ,int INPUT  ){
	switch(CC){
		case 0:
		CC =INPUT;
		break;
		case 1:
		CC++ ;
		break;
		default:
		if(!INPUT)CC =0;
		else if(CC<125)CC++;
		break;
	}
	return;
}
void CKeyPush::ALLKEYCHECK (){
	KEYCHECK(A, CheckHitKey(KEY_INPUT_A));
	KEYCHECK(B, CheckHitKey(KEY_INPUT_B));
	KEYCHECK(C, CheckHitKey(KEY_INPUT_C));
	KEYCHECK(D, CheckHitKey(KEY_INPUT_D));
	KEYCHECK(E, CheckHitKey(KEY_INPUT_E));
	KEYCHECK(F, CheckHitKey(KEY_INPUT_F));
	KEYCHECK(G, CheckHitKey(KEY_INPUT_G));
	KEYCHECK(H, CheckHitKey(KEY_INPUT_H));
	KEYCHECK(I, CheckHitKey(KEY_INPUT_I));
	KEYCHECK(J, CheckHitKey(KEY_INPUT_J));
	KEYCHECK(K, CheckHitKey(KEY_INPUT_K));
	KEYCHECK(L, CheckHitKey(KEY_INPUT_L));
	KEYCHECK(M, CheckHitKey(KEY_INPUT_M));
	KEYCHECK(N, CheckHitKey(KEY_INPUT_N));
	KEYCHECK(O, CheckHitKey(KEY_INPUT_O));
	KEYCHECK(P, CheckHitKey(KEY_INPUT_P));
	KEYCHECK(Q, CheckHitKey(KEY_INPUT_Q));
	KEYCHECK(R, CheckHitKey(KEY_INPUT_R));
	KEYCHECK(S, CheckHitKey(KEY_INPUT_S));
	KEYCHECK(T, CheckHitKey(KEY_INPUT_T));
	KEYCHECK(U, CheckHitKey(KEY_INPUT_U));
	KEYCHECK(V, CheckHitKey(KEY_INPUT_V));
	KEYCHECK(W, CheckHitKey(KEY_INPUT_W));
	KEYCHECK(X, CheckHitKey(KEY_INPUT_X));
	KEYCHECK(Y, CheckHitKey(KEY_INPUT_Y));
	KEYCHECK(Z, CheckHitKey(KEY_INPUT_Z));
	KEYCHECK(Key0, CheckHitKey(KEY_INPUT_0));
	KEYCHECK(Key1, CheckHitKey(KEY_INPUT_1));
	KEYCHECK(Key2, CheckHitKey(KEY_INPUT_2));
	KEYCHECK(Key3, CheckHitKey(KEY_INPUT_3));
	KEYCHECK(Key4, CheckHitKey(KEY_INPUT_4));
	KEYCHECK(Key5, CheckHitKey(KEY_INPUT_5));
	KEYCHECK(Key6, CheckHitKey(KEY_INPUT_6));
	KEYCHECK(Key7, CheckHitKey(KEY_INPUT_7));
	KEYCHECK(Key8, CheckHitKey(KEY_INPUT_8));
	KEYCHECK(Key9, CheckHitKey(KEY_INPUT_9));
	KEYCHECK(F1, CheckHitKey(KEY_INPUT_F1));
	KEYCHECK(F2, CheckHitKey(KEY_INPUT_F2));
	KEYCHECK(F3, CheckHitKey(KEY_INPUT_F3));
	KEYCHECK(F4, CheckHitKey(KEY_INPUT_F4));
	KEYCHECK(F5, CheckHitKey(KEY_INPUT_F5));
	KEYCHECK(F6, CheckHitKey(KEY_INPUT_F6));
	KEYCHECK(F7, CheckHitKey(KEY_INPUT_F7));
	KEYCHECK(F8, CheckHitKey(KEY_INPUT_F8));
	KEYCHECK(F9, CheckHitKey(KEY_INPUT_F9));
	KEYCHECK(F10, CheckHitKey(KEY_INPUT_F10));
	KEYCHECK(F11, CheckHitKey(KEY_INPUT_F11));
	KEYCHECK(F12, CheckHitKey(KEY_INPUT_F12));
	KEYCHECK( BACK, CheckHitKey(KEY_INPUT_BACK));//KEY_INPUT_BACK  // �o�b�N�X�y�[�X�L�[ 
	KEYCHECK( TAB, CheckHitKey(KEY_INPUT_TAB));//KEY_INPUT_TAB  // �^�u�L�[ 
	KEYCHECK( RETURN, CheckHitKey(KEY_INPUT_RETURN));//KEY_INPUT_RETURN  // �G���^�[�L�[
	KEYCHECK( LSHIFT, CheckHitKey(KEY_INPUT_LSHIFT));//KEY_INPUT_LSHIFT  // ���V�t�g�L�[ 
	KEYCHECK( RSHIFT, CheckHitKey(KEY_INPUT_RSHIFT));//KEY_INPUT_RSHIFT  // �E�V�t�g�L�[ 
	KEYCHECK( LCONTROL, CheckHitKey(KEY_INPUT_LCONTROL));//KEY_INPUT_LCONTROL  // ���R���g���[���L�[ 
	KEYCHECK( RCONTROL, CheckHitKey(KEY_INPUT_RCONTROL));//KEY_INPUT_RCONTROL  // �E�R���g���[���L�[ 
	KEYCHECK( ESCAPE, CheckHitKey(KEY_INPUT_ESCAPE));//KEY_INPUT_ESCAPE  // �G�X�P�[�v�L�[ 
	KEYCHECK( SPACE, CheckHitKey(KEY_INPUT_SPACE));//KEY_INPUT_SPACE  // �X�y�[�X�L�[ 
	KEYCHECK( LEFT, CheckHitKey(KEY_INPUT_LEFT));//KEY_INPUT_LEFT  // ���L�[ 
	KEYCHECK( UP, CheckHitKey(KEY_INPUT_UP));//KEY_INPUT_UP  // ��L�[ 
	KEYCHECK( RIGHT, CheckHitKey(KEY_INPUT_RIGHT));//KEY_INPUT_RIGHT  // �E�L�[ 
	KEYCHECK( DOWN, CheckHitKey(KEY_INPUT_DOWN));//KEY_INPUT_DOWN  // ���L�[ 
	KEYCHECK( INSERT, CheckHitKey(KEY_INPUT_INSERT));//KEY_INPUT_INSERT  // �C���T�[�g�L�[ 
	KEYCHECK( Delete, CheckHitKey(KEY_INPUT_DELETE));//KEY_INPUT_DELETE  // �f���[�g�L�[
	KEYCHECK( LALT, CheckHitKey(KEY_INPUT_LALT));//KEY_INPUT_LALT  // ���`�k�s�L�[ 
	KEYCHECK( RALT, CheckHitKey(KEY_INPUT_RALT));//KEY_INPUT_RALT  // �E�`�k�s�L�[ 
	KEYCHECK( SCROLL, CheckHitKey(KEY_INPUT_SCROLL));//KEY_INPUT_SCROLL  // ScrollLock�L�[
	KEYCHECK( CAPSLOCK, CheckHitKey(KEY_INPUT_CAPSLOCK));//KEY_INPUT_CAPSLOCK  // CaspLock�L�[ 
	KEYCHECK( PAUSE, CheckHitKey(KEY_INPUT_PAUSE));//KEY_INPUT_PAUSE  // PauseBreak�L�[
	KEYCHECK( MINUS , CheckHitKey(KEY_INPUT_MINUS)); // �|�L�[ 
	KEYCHECK( YEN , CheckHitKey(KEY_INPUT_YEN));  // ���L�[ 
	KEYCHECK( PREVTRACK , CheckHitKey(KEY_INPUT_PREVTRACK)); // �O�L�[ 
	KEYCHECK( PERIOD , CheckHitKey(KEY_INPUT_PERIOD)); // �D�L�[ 
	KEYCHECK( SLASH , CheckHitKey(KEY_INPUT_SLASH)); // �^�L�[ 
	KEYCHECK( SEMICOLON , CheckHitKey(KEY_INPUT_SEMICOLON)); // �G�L�[ 
	KEYCHECK( COLON , CheckHitKey(KEY_INPUT_COLON)); // �F�L�[ 
	KEYCHECK( LBRACKET , CheckHitKey(KEY_INPUT_LBRACKET)); // �m�L�[ 
	KEYCHECK( RBRACKET , CheckHitKey(KEY_INPUT_RBRACKET)); // �n�L�[ 
	KEYCHECK( AT , CheckHitKey(KEY_INPUT_AT)); // ���L�[ 
	KEYCHECK( BACKSLASH , CheckHitKey(KEY_INPUT_BACKSLASH)); // �_�L�[ 
	KEYCHECK( COMMA , CheckHitKey(KEY_INPUT_COMMA)); // �C�L�[ 
}

void GetHttpFile(char *&Buf, char *Http,DWORD ReadSize){
	HINTERNET hInternet;HINTERNET hFile;
	BOOL bResult;
	DWORD RealRead = ReadSize;
	// WININET������ 
	hInternet = InternetOpen("WININET Sample Program",INTERNET_OPEN_TYPE_PRECONFIG,	NULL,NULL,0);
	if(!hInternet)return;
	// URL�̃I�[�v�� 
	hFile = InternetOpenUrl(hInternet,Http,	NULL,0,	INTERNET_FLAG_RELOAD,0);
	if(!hFile){if(hInternet)InternetCloseHandle(hInternet);return;}
	bResult = InternetReadFile(hFile,Buf,RealRead,&ReadSize);
	if(!bResult) {return;if(hFile)InternetCloseHandle(hFile);if(hInternet)InternetCloseHandle(hInternet);}
	Buf[ReadSize] = '\0';
	if(hFile)InternetCloseHandle(hFile);
	if(hInternet)InternetCloseHandle(hInternet);
}

CBox::CBox(){
	Color = GetColor( 128 , 128 , 128 );
}
void CBox::Draw(){
	DrawBox( Left , Top , Left + Width , Top + Height , Color , TRUE );
}

CommandButton::CommandButton(){
	Left = 32;
	Top = 32;
	Width = 32;
	Height = 32;
	FontSize = 24;
	ForeColor = GetColor( 0 , 0 , 0 );
	BGColor = GetColor( 128 , 128 , 128 );
}
CommandButton::CommandButton( int _left , int _right , int _width , int _height ){
	Left = _left;
	Top = _right;
	Width = _width;
	Height = _height;
	FontSize = 24;
	ForeColor = GetColor( 0 , 0 , 0 );
	BGColor = GetColor( 128 , 128 , 128 );
}
void CommandButton::Draw(){
	int StringWidth;

	SetFontSize( FontSize );
	StringWidth = GetDrawFormatStringWidth( "%s" , Caption );
	DrawBox( Left , Top , Left + Width , Top + Height , BGColor , TRUE );
	DrawFormatString( Left + ((Width - StringWidth)/2) , Top + ((Height - FontSize)/2) , ForeColor , "%s" , Caption );
}
void CommandButton::Judge(){
if( !(GetMouseInput() & MOUSE_INPUT_LEFT) ){
	return;
}

	int x;
	int y;
	
	GetMousePoint( &x , &y );

	if ( x > Left && y > Top && x < Left+Width && y < Top + Height ){
		if( Func != NULL ){
			Func();
		} else {
			Click();
		}
	}
}
void CommandButton::Update(){
	Draw();
	Judge();
}
void CommandButton::Click(){}

CVector GetIntersection( int a1 , int b1 , int a2 , int b2 ){
	CVector Point;

	if( a1 != a2 ){
		Point.x = (float)( ( b2 - b1 ) / ( a1 - a2 ) );
	} else {
		Point.x = NULL;
		Point.y = NULL;
		return Point;
	}

	Point.y = (a1 * Point.x) + b1;

	return Point;
}


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


/// FROM NUNULIB
//���ݎ����擾�֐�///////////////////////////////////////////
SYSTEMTIME GetNowSystemTime(){
    SYSTEMTIME st;
    GetSystemTime(&st);
     
    FILETIME ft1;
    FILETIME ft2;
    SystemTimeToFileTime(&st, &ft1);
     
    //a ������ł�OK�B����͊m�F�ς݁B
    //long long int t = (long long int)(ft1.dwHighDateTime)<<32 | ft1.dwLowDateTime;
    //t += (long long int)9*60*60*1000*1000*10; //1���E�E�E24*60*60*1000*1000*10 
    //ft2.dwHighDateTime = t>>32; // & 0xFFFFFFFF;
    //ft2.dwLowDateTime = (int)t;   
     
    //b
    FileTimeToLocalFileTime(&ft1, &ft2);
 
    FileTimeToSystemTime(&ft2, &st);
    return st;
}
std::string GetNowSystemTimeString(){
    char currentTime[25] = { 0 };
    SYSTEMTIME st = GetNowSystemTime();
    wsprintf(currentTime, "%04d/%02d/%02d %02d:%02d:%02d %03d",
        st.wYear, st.wMonth, st.wDay,
        st.wHour, st.wMinute, st.wSecond, st.wMilliseconds); 
    std::string tmp = currentTime;
    return tmp;
}
//DrawCenterString Not�t�H�[�}�b�g��
int DrawCenterString(int cx, int y, int color, const TCHAR* format, ...){
    va_list args;
    char string[1024];
    int for_return;
 
    va_start( args, format );
    vsprintf_s( string, format, args );
    va_end( args );
 
    if(strlen(string)<1024){
        for_return = DrawCenterString((int)cx,(int)y,string,color); 
    }else{
        for_return=-1;
    }
 
    return for_return;  
}
int DrawCenterString(int cx, int y, int color, bool centerY, const TCHAR* format, ...){ //�t�H�[�}�b�g��
    va_list args;
    char string[1024];
    int for_return;
 
    va_start( args, format );
    vsprintf_s( string, format, args );
    va_end( args );
 
    if(strlen(string)<1024){
        for_return = DrawCenterString((int)cx,(int)y,string,color,centerY); 
    }else{
        for_return=-1;
    }
 
    return for_return;  
}

//�t�H���g�ǉ��i�p�X���͕K�{�j
void AddFontFromPath(char *path){

	LPCSTR font_path = path; // �ǂݍ��ރt�H���g�t�@�C���̃p�X
		if (AddFontResourceEx(font_path, FR_PRIVATE, NULL) > 0) {
		
		} else {
			// �t�H���g�Ǎ��G���[����
			MessageBox(NULL,"�t�H���g�Ǎ����s","",MB_OK);
		}
}

CVector::CVector( float _x , float _y ){
	x = _x;
	y = _y;
    }
CVector::CVector(){
	x = 0.0f;
	y = 0.0f;
}
void CVector::Set( float _x , float _y){
	x = _x;
	y = _y;
    }
void CVector::Set(CVector _vec){
	x = _vec.x;
	y = _vec.y;
}     
CVector CVector::Add( float _x , float _y){
	x += _x;
	y += _y;
	return *this;
}
CVector CVector::Add(CVector _vec){
	x += _vec.x;
	y += _vec.y;
        
	return *this;
}
// +���Z�q�I�[�o�[���[�h
CVector CVector::operator+(const CVector &obj){
	CVector tmp;
	tmp.x = x + obj.x;
	tmp.y = y + obj.y;
	return tmp;
}
// +=���Z�q�I�[�o�[���[�h
CVector& CVector::operator+=(const CVector &obj){
	x += obj.x;
	y += obj.y;
	return *this;
}    
// -���Z�q�I�[�o�[���[�h
CVector CVector::operator-(const CVector &obj){
	CVector tmp;
	tmp.x = x - obj.x;
	tmp.y = y - obj.y;
	return tmp;
}
// -=���Z�q�I�[�o�[���[�h
CVector& CVector::operator-=(const CVector &obj){
	x -= obj.x;
	y -= obj.y;
	return *this;
}
//*���Z�q�I�[�o�[���[�h
CVector CVector::operator*(const float _num){
	CVector tmp;
	tmp.x = x * _num;
	tmp.y = y * _num;
	return tmp;
}
//*=���Z�q�I�[�o�[���[�h
CVector& CVector::operator*=(const float _num){
	x*=_num;
	y*=_num;
	return *this;
}
//  /���Z�q�I�[�o�[���[�h
CVector CVector::operator/(const float _num){
	CVector tmp;
	tmp.x = x / _num;
	tmp.y = y / _num;
	return tmp;
}
///=���Z�q�I�[�o�[���[�h
CVector& CVector::operator/=(const float _num){
	x/=_num;
	y/=_num;
	return *this;
}
///==���Z�q�I�[�o�[���[�h
bool CVector::operator==(const CVector &obj){
	if(x==obj.x&&y==obj.y){
		return true;
	}
	return false;
}
///=���Z�q�I�[�o�[���[�h
CVector& CVector::operator =(const CVector &obj) {
	this->x = obj.x;
	this->y = obj.y;

	//*this��Ԃ����ƂŁuA=B�v�̂悤�ȋL�q�����łȂ��uA=B=C�v�̂悤�ȋL�q�ɂ��Ή��ł���
	return *this;
}
//operator*�̃I�[�o�[���[�h�ɂ����͂�s�v�Ȋ֐�
void CVector::Multiple(float _num){
	x = x*_num;
	y = y*_num;
}
float CVector::GetLength(){
	return sqrt((x*x)+(y*y));
}


CTransform::CTransform(){
	//prePosition = position = velocity = acceralate = VGet(0,0);
	rotation = 0.0f;
	gravity = GRAVITY;
	airResistance = 0 ;
}
void CTransform::TransLate(CVector _v){
	position += _v;
}
void CTransform::Loop(){
		
	//prePosition = position;
		
	///��C��R
	acceralate *= ( 1 - ( airResistance / System.GetFps() ));
		
	///���x
	velocity += (acceralate + gravity ) / System.GetFps();
	velocity *= ( 1 - ( airResistance / System.GetFps() ));
	///�ʒu
	prePosition = position;
	position += velocity / System.GetFps();
	if( velocity.y > 0.0f ){
		rotation = acos(VNorm(velocity).x);
	}else{
		rotation = -acos(VNorm(velocity).x);
	}
}

CRect::CRect(){
	direction=0.0f;
	Set(1,1);
}
void CRect::Set(int sizeX,int sizeY){
	size = VGet((float)sizeX,(float)sizeY);
	rad = atan2(size.y,size.x);
	radius = ( size.GetLength() / 2.0f );
}
CVector CRect::GetCenterPos(){
	return center.position;						
}
CVector CRect::GetSize(){			
	return size;								
}
float CRect::GetArea(){			
	return ( size.x * size.y );					
}
CVector CRect::GetRightTop(){				
	return ( center.position + VScale(VGet((float)cos(direction+rad),(float)sin(direction+rad)),radius) );	
}
CVector CRect::GetLeftTop(){				
	return ( center.position + VScale(VGet((float)cos(direction-rad),(float)sin(direction-rad)),radius) );	
}
CVector CRect::GetLeftBottom(){		
	return ( center.position + VScale(VGet((float)cos(direction-M_PI+rad),(float)sin(direction-M_PI+rad)),radius) );	
}
CVector CRect::GetRightBottom(){			
	return ( center.position + VScale(VGet((float)cos(direction+M_PI-rad),(float)sin(direction+M_PI-rad)),radius) );	
}
void CRect::Draw(int color){
	DrawLine(GetLeftTop(),GetRightTop(),RED);
	DrawLine(GetRightTop(),GetRightBottom(),BLUE);
	DrawLine(GetRightBottom(),GetLeftBottom(),GREEN);
	DrawLine(GetLeftBottom(),GetLeftTop(),WHITE);
}
void CRect::Loop(){

	center.Loop();
#ifdef DEBUG_DRAW
	Draw(WHITE);
		
#endif
}
float CRect::GetRadius(){
	return radius;
}
void CRect::AddEventLisnerOnCollision(void (*pFunc)()){
	onCollisionTaskVoid.push_back(pFunc);
}
void CRect::RemoveEventLisnerOnCollision(void (*pFunc)()){

	if(!onCollisionTaskVoid.empty()){
		vector<void(*)()>::iterator it = onCollisionTaskVoid.begin();
		while( ( it != onCollisionTaskVoid.end() ) ){

			if( *it ==  pFunc  ){

				onCollisionTaskVoid.erase( it );
				break;
			}
			it++;
		}
	}	
}
void CRect::OnCollision(){
	if(!onCollisionTaskVoid.empty()){
		vector<void(*)()>::iterator it=onCollisionTaskVoid.begin();

		while( it != onCollisionTaskVoid.end() ) {

			(*it)();					
				it++;
		}

	}
}



CCircle::CCircle(){
	mass = 1.0f;
	radius = 1.0f;
	bound = 1.0f;
	IsKinematic = false;
}
CVector CCircle::GetCenterPos(){		
	return center.position;					
}
float CCircle::GetArea(){			
	return (float)( M_PI * radius * radius );		
}
void CCircle::Loop(){
	center.Loop();
#ifdef DEBUG_DRAW
	DxLib::DrawCircle((int)(center.position.x +0.5), (int)(center.position.y+0.5) , (int)(radius+0.5) ,WHITE ,false );
#endif
}
void CCircle::AddEventLisnerOnCollision(void (*pFunc)()){
	onCollisionTaskVoid.push_back(pFunc);
}
void CCircle::RemoveEventLisnerOnCollision(void (*pFunc)()){

	if(!onCollisionTaskVoid.empty()){
		vector<void(*)()>::iterator it = onCollisionTaskVoid.begin();
		while( ( it != onCollisionTaskVoid.end() ) ){

			if( *it ==  pFunc  ){
				onCollisionTaskVoid.erase( it );
				break;
			}
			it++;
		}
	}	
}
void CCircle::OnCollisionFunc(){
	if(!onCollisionTaskVoid.empty()){
		vector<void(*)()>::iterator it=onCollisionTaskVoid.begin();

		while( it != onCollisionTaskVoid.end() ) {

			(*it)();					
			it++;
		}

	}
}
void CCircle::AddCollisionFalse(CCircle *c){
	noCollision.push_back(c);
}
void CCircle::RemoveCollisionFalse(CCircle *c){
	if(!noCollision.empty()){
		vector<CCircle*>::iterator it = noCollision.begin();
		while( ( it != noCollision.end() ) ){

			if( *it ==  c  ){

				noCollision.erase( it );
				break;
			}
			it++;
		}
	}
}
bool CCircle::GetIsNoCollision(CCircle *c){
	if(!noCollision.empty()){
		vector<CCircle*>::iterator it = noCollision.begin();
		while( ( it != noCollision.end() ) ){

			if( *it ==  c  ){

				return true;
			}
			it++;
		}
	}
	return false;
}



CCollisionManager::CCollisionManager(){
	
}
CCollisionManager::~CCollisionManager(){
	
}

void CCollisionManager::Awake(){
	
}

void CCollisionManager::Loop(){
		
	for(unsigned int i=0;i<physicsCircle.size();i++){
		physicsCircle[i]->onCollision = false;
		physicsCircle[i]->Loop();
	}
	for(unsigned int i=0;i<fixedCircle.size();i++){
		fixedCircle[i]->onCollision = false;
		fixedCircle[i]->Loop();
	}
	for(unsigned int i=0;i<physicsCircle.size();i++){
		for(unsigned int j=i+1;j<physicsCircle.size();j++){
			if( !physicsCircle[i]->GetIsNoCollision(physicsCircle[j]) && !physicsCircle[j]->GetIsNoCollision(physicsCircle[i])){
				CollisionCircle(*physicsCircle[i],*physicsCircle[j]);
			}
		}
		for(unsigned int j=0;j<fixedCircle.size();j++){
			if( !physicsCircle[i]->GetIsNoCollision(fixedCircle[j]) && !fixedCircle[j]->GetIsNoCollision(physicsCircle[i])){
				CollisionCircle(*physicsCircle[i],*fixedCircle[j]);
			}
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
void CCollisionManager::DrawLoop(){
	
}

void CCollisionManager::CollisionCircleCalc(CCircle &A , CCircle &B ,float time){
		
	float totalWeight = A.mass + B.mass;				//���ʘa
	float reflectionRate = (1 + A.bound * B.bound );	// ������
	CVector C = VNorm( B.center.position - A.center.position ); // �Փˎ��x�N�g��
	float dot = VDot( ( A.center.velocity - B.center.velocity ), C ); // ���ώZ�o
	CVector constVec = C * ( reflectionRate * dot / totalWeight ); // �萔�x�N�g��

	//���x��������
	// �Փˌ�ʒu�̎Z�o
	if(!A.IsKinematic){
		A.center.velocity += constVec * (-B.mass);
		A.center.position += (A.center.velocity) * 0.05f;
	}
	if(!B.IsKinematic){
		B.center.velocity += constVec  * A.mass ;
		B.center.position += (B.center.velocity) * 0.05f;
	}

}
bool CCollisionManager::CollisionCircle(CCircle &A , CCircle &B){
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
   CollisionCircleCalc(A ,B ,( 1.0f - abs(pOut_t0) ) / 60.0f );
   return true; // �Փ˕�

}
bool CCollisionManager::CollisionRect(CRect &A , CRect &B){
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
void CCollisionManager::AddChild(CCircle *_circle , bool moveFlag){
	if(moveFlag){
		physicsCircle.push_back(_circle);
	}else{
		fixedCircle.push_back(_circle);
		_circle->mass = INF ;
	}
}
bool CCollisionManager::RemoveChild(CCircle *_circle){

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
void CCollisionManager::AddChild(CRect *_rect , bool moveFlag){
	if(moveFlag){
		physicsRect.push_back(_rect);
	}else{
		fixedRect.push_back(_rect);
	}
}
bool CCollisionManager::RemoveChild(CRect *_rect){

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

//�K��
unsigned int fanctorial(unsigned int num){
	if(num <= 1){
		return 1;
	}else{
		return ( num * fanctorial( num - 1 ) );
	}
}
//�g�ݍ��킹�in��r�͂��ꂼ��unCr�v��n��r�j
unsigned int combination(unsigned int n , unsigned int r){
	return ( fanctorial( n ) / ( fanctorial( n-r ) * fanctorial( r ) ) );
}

//�x�W�F�Ȑ�

//�x�W�F�Ȑ����_�f�[�^�̍쐬
////�x�W�F�Ȑ��̌v�Z���}�C�t���[������͖̂��ʂȂ̂Ōv�Z�ς݂̃f�[�^���쐬����
//����
// In�@�@�@�@: ����_�iCVector�^�j���w�肷��i2�ȏ�j
// vertexNum : �쐬����f�[�^�ׂ̍������w��i�x�W�F�Ȑ��̍\�����_�̐��j
BEZIER GetBezier(vector<CVector> &In , unsigned int vertexNum ){
	
	const int N = In.size();
	BEZIER vertexes;
	vertexes.push_back(In[0]);
	float t = 0.0f;

	for(unsigned int j = 0; j < vertexNum; j++){

		 t += ( 1.0f / (float)vertexNum ) ;

		CVector vertex ;
		
		for( int i = 0; i < N; i++ ){
			
			float temp = (float)( combination( N-1 , i ) * pow( 1-t , N-i-1  ) * pow( t , i ) );

			vertex += In[i] * temp;

		}

		vertexes.push_back(vertex);
	}
	
	return vertexes;
}
//�x�W�F�Ȑ��̕`��i GetBezier�֐��ō쐬�����f�[�^���K�v�@�j
////GetBezier�֐��ō쐬�����f�[�^��p���ăx�W�F�Ȑ���`�悷��
//����
// data  : GetBezier�֐��ō쐬�����x�W�F�Ȑ��f�[�^
// color : �`��F���w��
void DrawBezier( BEZIER &data ,  int color ){
	for(unsigned int i = 0; i < data.size() - 1; i++){
		DrawLine( (int)data[ i ].x ,(int)data[ i ].y , (int)data[ i+1 ].x , (int)data[ i+1 ].y , color );
	}
}
//�ÓI�����o�ϐ�
unsigned int CScene::sceneNum;


void CKey::Loop(){
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
bool CKey::GetPush(int keyCode){
	 //�L�[�R�[�h�`�F�b�N
		if( keyCode < 256 && keyCode >= 0 ){
		if( count[keyCode] < 1.0f ){
			if(Event.GetValid()){
				return true;
			}else{
				return false;
			}
		}else{
			return false;
		}
	 }else{
		WarningSK("CKey::GetPush�̈����ɕs���ȃL�[�R�[�h�����͂���܂���\n�L�[�R�[�h�@�F�@%d",keyCode);
		return false;
	 }
 }
 bool CKey::GetDown(int keyCode){
	 //�L�[�R�[�h�`�F�b�N
	 if( keyCode < 256 && keyCode >= 0 ){
		if( count[keyCode] == 0.0f ){
			if(Event.GetValid()){
				return true;
			}else{
				return false;
			}
		}else{
			return false;
		}
	 }else{
		WarningSK("CKey::GetDown�̈����ɕs���ȃL�[�R�[�h�����͂���܂���\n�L�[�R�[�h�@�F�@%d",keyCode);
		return false;
	 }
}
 bool CKey::GetUp(int keyCode){
	//�L�[�R�[�h�`�F�b�N
	if( keyCode < 256 && keyCode >= 0 ){
		if( count[keyCode] == 1.5f ){
			if(Event.GetValid()){
				return true;
			}else{
				return false;
			}
		}else{
			return false;			
		}
	}else{
		WarningSK("CKey::GetUp�̈����ɕs���ȃL�[�R�[�h�����͂���܂���\n�L�[�R�[�h�@�F�@%d",keyCode);
		return false;
	}
}
int CKey::GetCount(int keyCode){
	//�L�[�R�[�h�`�F�b�N
		if( keyCode < 256 && keyCode >= 0 ){
		return (int)(count[keyCode]);
	}else{
		WarningSK("CKey::GetCount�̈����ɕs���ȃL�[�R�[�h�����͂���܂���\n�L�[�R�[�h�@�F�@%d",keyCode);
		return -1;
	}
}

CMouseIn CMouse::Off( int _x1 , int _y1 , int _x2 , int _y2 ){

	CMouseIn temp;

	temp.x1 = _x1;
	temp.x2 = _x2;
	temp.y1 = _y1;
	temp.y2 = _y2;

	temp.type = MOUSE_OFF;

	return temp;
}
bool CMouse::GetOff( int _x1 , int _y1 , int _x2 , int _y2 ){
	if(_x1>mouseX && _x2<mouseX ){
		if(_y1>mouseY && _y2<mouseY){
			return true;
		}
	}
	return false;
}
CpMouseIn CMouse::Off( int *_x1 , int *_y1 , int *_x2 , int *_y2 ){

	CpMouseIn temp;

	temp.x1 = _x1;
	temp.x2 = _x2;
	temp.y1 = _y1;
	temp.y2 = _y2;

	temp.type = MOUSE_OFF;

	return temp;
}
bool CMouse::GetOff( int *_x1 , int *_y1 , int *_x2 , int *_y2 ){
	if(*_x1>mouseX && *_x2<mouseX ){
		if(*_y1>mouseY && *_y2<mouseY){
			return true;
		}
	}
	return false;
}
CMouseIn CMouse::On( int _x1 , int _y1 , int _x2 , int _y2 ){
	
	CMouseIn temp;

	temp.x1 = _x1;
	temp.x2 = _x2;
	temp.y1 = _y1;
	temp.y2 = _y2;

	temp.type = MOUSE_ON;

	return temp;

}
bool CMouse::GetOn( int _x1 , int _y1 , int _x2 , int _y2 ){
	if(_x1<mouseX && _x2>mouseX ){
		if(_y1<mouseY && _y2>mouseY){
			if(Event.GetValid()){
				return true;
			}
		}
	}
	return false;
}
CpMouseIn CMouse::On( int *_x1 , int *_y1 , int *_x2 , int *_y2 ){
	
	CpMouseIn temp;

	temp.x1 = _x1;
	temp.x2 = _x2;
	temp.y1 = _y1;
	temp.y2 = _y2;

	temp.type = MOUSE_ON;

	return temp;

}
bool CMouse::GetOn( int *_x1 , int *_y1 , int *_x2 , int *_y2 ){
	if(*_x1<mouseX && *_x2>mouseX ){
		if(*_y1<mouseY && *_y2>mouseY){
			if(Event.GetValid()){
				return true;
			}
		}
	}
	return false;
}
CMouseIn CMouse::Click( int _x1 , int _y1 , int _x2 , int _y2 ){
		
	CMouseIn temp;

	temp.x1 = _x1;
	temp.x2 = _x2;
	temp.y1 = _y1;
	temp.y2 = _y2;

	temp.type = MOUSE_CLICK;

	return temp;

}
bool CMouse::GetClick( int _x1 , int _y1 , int _x2 , int _y2 ){
	if(_x1<mouseX && _x2>mouseX ){
		if(_y1<mouseY && _y2>mouseY){
			if(mouseInput && !preMouseInput ){
				if(Event.GetValid()){
					return true;		
				}
			} 
		}
	}
	return false;
}
CpMouseIn CMouse::Click( int *_x1 , int *_y1 , int *_x2 , int *_y2 ){
		
	CpMouseIn temp;

	temp.x1 = _x1;
	temp.x2 = _x2;
	temp.y1 = _y1;
	temp.y2 = _y2;

	temp.type = MOUSE_CLICK;

	return temp;

}
bool CMouse::GetClick( int *_x1 , int *_y1 , int *_x2 , int *_y2 ){
	if(*_x1<mouseX && *_x2>mouseX ){
		if(*_y1<mouseY && *_y2>mouseY){
			if(mouseInput && !preMouseInput ){
				if(Event.GetValid()){
					return true;	
				}
			} 
		}
	}
	return false;
}
CMouseIn CMouse::Release( int _x1 , int _y1 , int _x2 , int _y2 ){
		
	CMouseIn temp;

	temp.x1 = _x1;
	temp.x2 = _x2;
	temp.y1 = _y1;
	temp.y2 = _y2;

	temp.type = MOUSE_RELEASE;

	return temp;
}
bool CMouse::GetRelease( int _x1 , int _y1 , int _x2 , int _y2 ){
	if(_x1<mouseX && _x2>mouseX ){
		if(_y1<mouseY && _y2>mouseY){
			if( !mouseInput && preMouseInput ){
				if(Event.GetValid()){
					return true;
				}
			} 
		}	
	}
	return false;
}
CpMouseIn CMouse::Release( int *_x1 , int *_y1 , int *_x2 , int *_y2 ){
		
	CpMouseIn temp;

	temp.x1 = _x1;
	temp.x2 = _x2;
	temp.y1 = _y1;
	temp.y2 = _y2;

	temp.type = MOUSE_RELEASE;

	return temp;
}
bool CMouse::GetRelease( int *_x1 , int *_y1 , int *_x2 , int *_y2 ){
	if(*_x1<mouseX && *_x2>mouseX ){
		if(*_y1<mouseY && *_y2>mouseY){
			if( !mouseInput && preMouseInput ){
				if(Event.GetValid()){
					return true;
				}
			} 
		}	
	}
	return false;
}
void CMouse::Loop(){
	GetMousePoint( &mouseX, &mouseY );
	preMouseInput = mouseInput;
	if(IsLeft){
		mouseInput = (bool)( GetMouseInput() & MOUSE_INPUT_LEFT );
	}else{
		mouseInput = (bool)( GetMouseInput() & MOUSE_INPUT_RIGHT );
	}
}
void CMouse::SetLeft(){
	IsLeft = true;
}
void CMouse::SetRight(){
	IsLeft = false;
}

CEvent::CEvent(){
	EVERY_FRAME=FRAME_EVENT;
	LMouse.SetLeft();
	RMouse.SetRight();
	IsActivated = true;
}
void CEvent::Loop(){
	key.Loop();
	LMouse.Loop();
	RMouse.Loop();
}
void CEvent::Activate(){
	IsActivated = true;
}
void CEvent::Deactivate(){
	IsActivated = false;
}
bool CEvent::GetValid(){
	return IsActivated;
}


CInput::CInput(){
	useMouse = true;
	useKey = true;
}	
void CInput::AddEventListener( int inputCode , void func() ){
				
	keyTemp.keyCode=inputCode;
	keyTemp.pFuncVoid=func;
	keyTask.push_back(keyTemp);

}
void CInput::AddEventListener( int inputCode , void func(int) , int *pArgument ){
				
	keyTemp.keyCode=inputCode;
	keyTemp.pFuncInt=func;
	keyTemp.pInt = pArgument;
	keyTask.push_back(keyTemp);

}
void CInput::AddEventListener( int inputCode , void func(int) , int Argument ){
				
	keyTemp.keyCode=inputCode;
	keyTemp.pFuncInt=func;
	keyTemp.Int = Argument;
	keyTask.push_back(keyTemp);

}
void CInput::RemoveEventListener( int inputCode , void func()  ){

	vector< CKeyIn >::iterator it = keyTask.begin();

	while( ( it != keyTask.end() ) ){

		if( it->keyCode == inputCode && it->pFuncVoid == func  ){

			keyTask.erase( it );
			break;
		}
		it++;
	}
		
}
void CInput::RemoveEventListener( int inputCode , void func(int) , int *pArgument  ){

	vector< CKeyIn >::iterator it = keyTask.begin();

	while( ( it != keyTask.end() ) ){

		if( it->keyCode == inputCode && it->pFuncInt == func && it->pInt == pArgument ){

			keyTask.erase( it );
			break;
		}
		it++;
	}
		
}
void CInput::RemoveEventListener( int inputCode , void func(int) , int Argument  ){

	vector< CKeyIn >::iterator it = keyTask.begin();

	while( ( it != keyTask.end() ) ){

		if( it->keyCode == inputCode && it->pFuncInt == func  && it->Int == Argument ){

			keyTask.erase( it );
			break;
		}
		it++;
	}
		
}
void CInput::AddEventListener( CMouseIn input , void func()  ){

	mouseTemp=input;
	mouseTemp.pFuncVoid=func;
	mouseTask.push_back(mouseTemp);
				
}
void CInput::AddEventListener( CMouseIn input , void func(int) , int *pArgument  ){

	mouseTemp=input;
	mouseTemp.pFuncInt=func;
	mouseTemp.pInt = pArgument;
	mouseTask.push_back(mouseTemp);
				
}
void CInput::AddEventListener( CMouseIn input , void func(int) , int Argument  ){

	mouseTemp=input;
	mouseTemp.pFuncInt=func;
	mouseTemp.Int = Argument;
	mouseTask.push_back(mouseTemp);
				
}
void CInput::RemoveEventListener( CMouseIn input , void func()  ){

	vector< CMouseIn >::iterator it = mouseTask.begin();

	while( ( it != mouseTask.end() ) ){

		if( it->pFuncVoid == func && it->type == input.type && it->x1 == input.x1 && it->x2 == input.x2 && it->y1 == input.y1 && it->y2 == input.y2  ){

			mouseTask.erase( it );
			break;
		}
		it++;
	}
		
}
void CInput::RemoveEventListener( CMouseIn input , void func(int) , int *pArgument  ){

	vector< CMouseIn >::iterator it = mouseTask.begin();

	while( ( it != mouseTask.end() ) ){

		if( it->pFuncInt == func && it->type == input.type && it->x1 == input.x1 && it->x2 == input.x2 && it->y1 == input.y1 && it->y2 == input.y2 && it->pInt == pArgument ){

			mouseTask.erase( it );
			break;
		}
		it++;
	}
		
}
void CInput::RemoveEventListener( CMouseIn input , void func(int) , int Argument  ){

	vector< CMouseIn >::iterator it = mouseTask.begin();

	while( ( it != mouseTask.end() ) ){

		if( it->pFuncInt == func && it->type == input.type && it->x1 == input.x1 && it->x2 == input.x2 && it->y1 == input.y1 && it->y2 == input.y2  && it->Int == Argument ){

			mouseTask.erase( it );
			break;
		}
		it++;
	}
		
}
void CInput::AddEventListener( CpMouseIn input , void func()  ){

	pMouseTemp=input;
	pMouseTemp.pFuncVoid=func;
	pMouseTask.push_back(pMouseTemp);
				
}
void CInput::AddEventListener( CpMouseIn input , void func(int) , int *pArgument  ){

	pMouseTemp=input;
	pMouseTemp.pFuncInt=func;
	pMouseTemp.pInt = pArgument;
	pMouseTask.push_back(pMouseTemp);
				
}
void CInput::AddEventListener( CpMouseIn input , void func(int) , int Argument  ){

	pMouseTemp=input;
	pMouseTemp.pFuncInt=func;
	pMouseTemp.Int = Argument;
	pMouseTask.push_back(pMouseTemp);
				
}
void CInput::RemoveEventListener( CpMouseIn input , void func()  ){

	vector< CpMouseIn >::iterator it = pMouseTask.begin();

	while( ( it != pMouseTask.end() ) ){

		if( it->pFuncVoid == func && it->type == input.type && it->x1 == input.x1 && it->x2 == input.x2 && it->y1 == input.y1 && it->y2 == input.y2  ){

			pMouseTask.erase( it );
			break;
		}
		it++;
	}
}
void CInput::RemoveEventListener( CpMouseIn input , void func(int) , int *pArgument  ){

	vector< CpMouseIn >::iterator it = pMouseTask.begin();

	while( ( it != pMouseTask.end() ) ){

		if( it->pFuncInt == func && it->type == input.type && it->x1 == input.x1 && it->x2 == input.x2 && it->y1 == input.y1 && it->y2 == input.y2  && it->pInt == pArgument ){

			pMouseTask.erase( it );
			break;
		}
		it++;
	}
}
void CInput::RemoveEventListener( CpMouseIn input , void func(int) , int Argument  ){

	vector< CpMouseIn >::iterator it = pMouseTask.begin();

	while( ( it != pMouseTask.end() ) ){

		if( it->pFuncInt == func && it->type == input.type && it->x1 == input.x1 && it->x2 == input.x2 && it->y1 == input.y1 && it->y2 == input.y2  && it->Int == Argument ){

			pMouseTask.erase( it );
			break;
		}
		it++;
	}
}
void CInput::AddEventListener( char input , void func()  ){
	frameTemp.pFuncVoid=func;
	frameTask.push_back(frameTemp);
			
}
void CInput::AddEventListener( char input , void func(int) , int *pArgument  ){
	frameTemp.pFuncInt=func;
	frameTemp.pInt = pArgument;
	frameTask.push_back(frameTemp);
			
}
void CInput::AddEventListener( char input , void func(int) , int Argument  ){
	frameTemp.pFuncInt=func;
	frameTemp.Int = Argument;
	frameTask.push_back(frameTemp);
			
}
void CInput::RemoveEventListener( char input , void func()  ){

	vector< CFrame >::iterator it = frameTask.begin();

	while( ( it != frameTask.end() ) ){

		if( it->pFuncVoid ==  func  ){

			frameTask.erase( it );
			break;
		}
		it++;
	}
		
}
void CInput::RemoveEventListener( char input , void func(int) , int *pArgument  ){

	vector< CFrame >::iterator it = frameTask.begin();

	while( ( it != frameTask.end() ) ){

		if( it->pFuncInt ==  func  && it->pInt == pArgument ){

			frameTask.erase( it );
			break;
		}
		it++;
	}
		
}
void CInput::RemoveEventListener( char input , void func(int) , int Argument  ){

	vector< CFrame >::iterator it = frameTask.begin();

	while( ( it != frameTask.end() ) ){

		if( it->pFuncInt ==  func  && it->Int == Argument ){

			frameTask.erase( it );
			break;
		}
		it++;
	}
		
}
void CInput::AddEventListener( bool* input , void func()  ){
	boolTemp.pFuncVoid=func;
	boolTemp.pBool=input;
	boolTask.push_back(boolTemp);
			
}
void CInput::AddEventListener( bool* input , void func(int) , int *pArgument  ){
	boolTemp.pFuncInt=func;
	boolTemp.pInt = pArgument;
	boolTemp.pBool=input;
	boolTask.push_back(boolTemp);
			
}
void CInput::AddEventListener( bool* input , void func(int) , int Argument  ){
	boolTemp.pFuncInt=func;
	boolTemp.Int = Argument;
	boolTemp.pBool=input;
	boolTask.push_back(boolTemp);
			
}
void CInput::RemoveEventListener( bool* input , void func()  ){

	vector< CBoolean >::iterator it = boolTask.begin();

	while( ( it != boolTask.end() ) ){

		if( it->pBool == input && it->pFuncVoid == func  ){

			boolTask.erase( it );
			break;
		}
		it++;
	}
	
}	
void CInput::RemoveEventListener( bool* input , void func(int) , int *pArgument  ){

	vector< CBoolean >::iterator it = boolTask.begin();

	while( ( it != boolTask.end() ) ){

		if( it->pBool == input && it->pFuncInt == func  && it->pInt == pArgument ){

			boolTask.erase( it );
			break;
		}
		it++;
	}
	
}
void CInput::RemoveEventListener( bool* input , void func(int) , int Argument  ){

	vector< CBoolean >::iterator it = boolTask.begin();

	while( ( it != boolTask.end() ) ){

		if( it->pBool == input && it->pFuncInt == func  && it->Int == Argument ){

			boolTask.erase( it );
			break;
		}
		it++;
	}
	
}
void CInput::Loop(){

		
	//KEY
	if(useKey){


		vector<CKeyIn>::iterator it=keyTask.begin();

		while( it != keyTask.end() ) {
			if(Event.key.GetPush(it->keyCode)){
					
				CKeyIn temp=*it;
				if(temp.pFuncVoid != NULL){
					temp.pFuncVoid();
				}else{
					if(temp.pInt == NULL){
						temp.pFuncInt(temp.Int);
					}else{
						temp.pFuncInt(*temp.pInt);
					}
				}
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
						
						if(temp.pFuncVoid != NULL){
							temp.pFuncVoid();
						}else{
							if(temp.pInt == NULL){
								temp.pFuncInt(temp.Int);
							}else{
								temp.pFuncInt(*temp.pInt);
							}
						}
						
					}
				}
				break;
			case MOUSE_ON :
				if(temp.x1<mouseX && temp.x2>mouseX ){
					if(temp.y1<mouseY && temp.y2>mouseY){
						
						if(temp.pFuncVoid != NULL){
							temp.pFuncVoid();
						}else{
							if(temp.pInt == NULL){
								temp.pFuncInt(temp.Int);
							}else{
								temp.pFuncInt(*temp.pInt);
							}
						}
						
					}
				}
				break;

			case MOUSE_PUSH :
				if(temp.x1<mouseX && temp.x2>mouseX ){
					if(temp.y1<mouseY && temp.y2>mouseY){
						if(mouseInput){
							
							if(temp.pFuncVoid != NULL){
								temp.pFuncVoid();
							}else{
								if(temp.pInt == NULL){
									temp.pFuncInt(temp.Int);
								}else{
									temp.pFuncInt(*temp.pInt);
								}
							}							
						}
					}
				} 
				break;
			case MOUSE_CLICK :
				if(temp.x1<mouseX && temp.x2>mouseX ){
					if(temp.y1<mouseY && temp.y2>mouseY){
						if(mouseInput && !preMouseInput ){
							
							if(temp.pFuncVoid != NULL){
								temp.pFuncVoid();
							}else{
								if(temp.pInt == NULL){
									temp.pFuncInt(temp.Int);
								}else{
									temp.pFuncInt(*temp.pInt);
								}
							}			
						} 
					}
				}
				break;
			case MOUSE_RELEASE :
				if(temp.x1<mouseX && temp.x2>mouseX ){
					if(temp.y1<mouseY && temp.y2>mouseY){
						if( !mouseInput && preMouseInput ){
								
							if(temp.pFuncVoid != NULL){
								temp.pFuncVoid();
							}else{
								if(temp.pInt == NULL){
									temp.pFuncInt(temp.Int);
								}else{
									temp.pFuncInt(*temp.pInt);
								}
							}	
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
								
							if(temp.pFuncVoid != NULL){
								temp.pFuncVoid();
							}else{
								if(temp.pInt == NULL){
									temp.pFuncInt(temp.Int);
								}else{
									temp.pFuncInt(*temp.pInt);
								}
							}				
						}
					}
					break;
				case MOUSE_ON :
					if( *(temp.x1) < mouseX && *(temp.x2) > mouseX ){
						if( *(temp.y1) < mouseY && *(temp.y2) > mouseY){
								
							if(temp.pFuncVoid != NULL){
								temp.pFuncVoid();
							}else{
								if(temp.pInt == NULL){
									temp.pFuncInt(temp.Int);
								}else{
									temp.pFuncInt(*temp.pInt);
								}
							}			
						} 
					} 
					break;
				case MOUSE_PUSH :
					if( *(temp.x1) < mouseX && *(temp.x2) > mouseX ){
						if( *(temp.y1) < mouseY && *(temp.y2) > mouseY ){
							if( mouseInput ){
									
								if(temp.pFuncVoid != NULL){
									temp.pFuncVoid();
								}else{
									if(temp.pInt == NULL){
										temp.pFuncInt(temp.Int);
									}else{
										temp.pFuncInt(*temp.pInt);
									}
								}	
							} 
						}
					} 
					break;
				case MOUSE_CLICK :
					if( *(temp.x1) < mouseX && *(temp.x2) > mouseX ){
						if( *(temp.y1) < mouseY && *(temp.y2) > mouseY ){
							if( mouseInput && !preMouseInput ){
									
								if(temp.pFuncVoid != NULL){
									temp.pFuncVoid();
								}else{
									if(temp.pInt == NULL){
										temp.pFuncInt(temp.Int);
									}else{
										temp.pFuncInt(*temp.pInt);
									}
								}	
							} 
						} 
					} 
					break;
				case MOUSE_RELEASE :
					if( *(temp.x1) < mouseX && *(temp.x2) > mouseX ){
						if( *(temp.y1) < mouseY && *(temp.y2) > mouseY ){
							if( !mouseInput && preMouseInput ){
									
								if(temp.pFuncVoid != NULL){
									temp.pFuncVoid();
								}else{
									if(temp.pInt == NULL){
										temp.pFuncInt(temp.Int);
									}else{
										temp.pFuncInt(*temp.pInt);
									}
								}									
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

		if(temp.pFuncVoid != NULL){
			temp.pFuncVoid();
		}else{
			if(temp.pInt == NULL){
				temp.pFuncInt(temp.Int);
			}else{
				temp.pFuncInt(*temp.pInt);
			}
		}
		it2++;
	}

	vector<CBoolean>::iterator it3=boolTask.begin();

	while( it3 != boolTask.end() ) {
			
		CBoolean temp=*it3;

		if(*(temp.pBool)){
			
			if(temp.pFuncVoid != NULL){
				temp.pFuncVoid();
			}else{
				if(temp.pInt == NULL){
					temp.pFuncInt(temp.Int);
				}else{
					temp.pFuncInt(*temp.pInt);
				}
			}

		}

		it3++;
	}

}//end of void Loop()
void CInput::DrawLoop(){
	//KEY
	if(useKey){

		vector<CKeyIn>::iterator it=keyTask_Draw.begin();

		while( it != keyTask_Draw.end() ) {
			if(CheckHitKey(it->keyCode)){

				CKeyIn temp=*it;
				if(temp.pFuncVoid != NULL){
					temp.pFuncVoid();
				}else{
					temp.pFuncInt(*temp.pInt);
				}
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
							
						if(temp.pFuncVoid != NULL){
							temp.pFuncVoid();
						}else{
							temp.pFuncInt(*temp.pInt);
						}	
					}
				}
				break;
			case MOUSE_ON :
				if(temp.x1<mouseX && temp.x2>mouseX ){
					if(temp.y1<mouseY && temp.y2>mouseY){
							
						if(temp.pFuncVoid != NULL){
							temp.pFuncVoid();
						}else{
							temp.pFuncInt(*temp.pInt);
						}						
					}
				}
					break;
			case MOUSE_PUSH :
				if(temp.x1<mouseX && temp.x2>mouseX ){
					if(temp.y1<mouseY && temp.y2>mouseY){
						if(mouseInput){
								
							if(temp.pFuncVoid != NULL){
								temp.pFuncVoid();
							}else{
								temp.pFuncInt(*temp.pInt);
							}							
						}
					}
				} 
				break;
			case MOUSE_CLICK :
					if(temp.x1<mouseX && temp.x2>mouseX ){
					if(temp.y1<mouseY && temp.y2>mouseY){
						if(mouseInput && !preMouseInput ){
								
							if(temp.pFuncVoid != NULL){
								temp.pFuncVoid();
							}else{
								temp.pFuncInt(*temp.pInt);
							}						
						} 
					}
				}
				break;
			case MOUSE_RELEASE :
				if(temp.x1<mouseX && temp.x2>mouseX ){
					if(temp.y1<mouseY && temp.y2>mouseY){
						if( !mouseInput && preMouseInput ){
								
							if(temp.pFuncVoid != NULL){
								temp.pFuncVoid();
							}else{
								temp.pFuncInt(*temp.pInt);
							}							
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
								
						if(temp.pFuncVoid != NULL){
							temp.pFuncVoid();
						}else{
							temp.pFuncInt(*temp.pInt);
						}					
					}
				}
				break;
			case MOUSE_ON :
				if( *(temp.x1) < mouseX && *(temp.x2) > mouseX ){
					if( *(temp.y1) < mouseY && *(temp.y2) > mouseY){
								
						if(temp.pFuncVoid != NULL){
							temp.pFuncVoid();
						}else{
							temp.pFuncInt(*temp.pInt);
						}							
					} 
				} 
				break;
			case MOUSE_PUSH :
				if( *(temp.x1) < mouseX && *(temp.x2) > mouseX ){
					if( *(temp.y1) < mouseY && *(temp.y2) > mouseY ){
						if( mouseInput ){									
							if(temp.pFuncVoid != NULL){
								temp.pFuncVoid();
							}else{
								temp.pFuncInt(*temp.pInt);
							}						
						} 
					}
				} 
				break;
			case MOUSE_CLICK :
				if( *(temp.x1) < mouseX && *(temp.x2) > mouseX ){
					if( *(temp.y1) < mouseY && *(temp.y2) > mouseY ){
						if( mouseInput && !preMouseInput ){
								
							if(temp.pFuncVoid != NULL){
								temp.pFuncVoid();
							}else{
								temp.pFuncInt(*temp.pInt);
							}		
						} 
					} 
				} 
				break;
			case MOUSE_RELEASE :
				if( *(temp.x1) < mouseX && *(temp.x2) > mouseX ){
					if( *(temp.y1) < mouseY && *(temp.y2) > mouseY ){
						if( !mouseInput && preMouseInput ){
								
							if(temp.pFuncVoid != NULL){
								temp.pFuncVoid();
							}else{
								temp.pFuncInt(*temp.pInt);
							}					
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
		if(temp.pFuncVoid != NULL){
			temp.pFuncVoid();
		}else{
			temp.pFuncInt(*temp.pInt);
		}
		it2++;
	}
		
	//bool
	vector<CBoolean>::iterator it3=boolTask_Draw.begin();

	while( it3 != boolTask_Draw.end() ) {
		CBoolean temp=*it3;

		if(*(temp.pBool)){
			
			if(temp.pFuncVoid != NULL){
				temp.pFuncVoid();
			}else{
				temp.pFuncInt(*temp.pInt);
			}
		}

		it3++;
	}
}//end of DrawLoop()

CScene::CScene(){
	serialNum = sceneNum;
	sceneNum++;
	focus = false;
	sceneChild = NULL;
}
void CScene::Loop(){
	if(!focus){
		input.useKey = false;
		input.useMouse = false;
		Event.Deactivate();
	}
		
	input.Loop();
	ButtonLoop();
	input.DrawLoop();

	collision.Loop();
	collision.DrawLoop();

	if( sceneChild != NULL ){
		sceneChild->Loop();
	}

	if(focus){
		input.useKey = true;
		input.useMouse = true;
	}
	Event.Activate();
}
void CScene::ButtonLoop(){
		

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
void CScene::SetFocus(bool _focus){
	focus = _focus;
}
bool CScene::GetFocus(){
	return focus;
}
void CScene::AddChild(CScene *_scene){
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
void CScene::RemoveChild(){
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
void CScene::SetButton( int x1 , int y1 , int x2 , int y2 , int backColor , char *title , int stringColor , void (*pFunc)() ){
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
void CScene::SetButton( int x1 , int y1 , int x2 , int y2 , int backColor , char *title , int stringColor , void (*pFunc)(int) , int *pInt ){
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
		
	this->input.AddEventListener( Event.LMouse.Click( x1 , y1 , x2 , y2 ) , pFunc , pInt );
}
void CScene::SetButton( int x1 , int y1 , int x2 , int y2 , int backColor , char *title , int stringColor , void (*pFunc)(int) , int Int ){
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
		
	this->input.AddEventListener( Event.LMouse.Click( x1 , y1 , x2 , y2 ) , pFunc , Int );
}
void CScene::SetButton( int x1 , int y1 , int x2 , int y2 , int graph, void (*pFunc)() ){
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
void CScene::SetButton( int x1 , int y1 , int x2 , int y2 , int graph, void (*pFunc)(int) , int *pInt ){
	CButton temp;
		
	temp.IsUseGraph = true;
	temp.x1 = x1;
	temp.x2 = x2;
	temp.y1 = y1;
	temp.y2 = y2;
	temp.graphHandle = graph;

	buttonChild.push_back( temp );
		
	this->input.AddEventListener( Event.LMouse.Click( x1 , y1 , x2 , y2 ) , pFunc , pInt );
}
void CScene::SetButton( int x1 , int y1 , int x2 , int y2 , int graph, void (*pFunc)(int) , int Int ){
	CButton temp;
		
	temp.IsUseGraph = true;
	temp.x1 = x1;
	temp.x2 = x2;
	temp.y1 = y1;
	temp.y2 = y2;
	temp.graphHandle = graph;

	buttonChild.push_back( temp );
		
	this->input.AddEventListener( Event.LMouse.Click( x1 , y1 , x2 , y2 ) , pFunc , Int );
}
void CScene::SetButton( int x1 , int y1 , int x2 , int y2 , char* graphPath, void (*pFunc)() ){
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
void CScene::SetButton( int x1 , int y1 , int x2 , int y2 , char* graphPath, void (*pFunc)(int) , int *pInt ){
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
		
	this->input.AddEventListener( Event.LMouse.Click( x1 , y1 , x2 , y2 ) , pFunc , pInt );
}
void CScene::SetButton( int x1 , int y1 , int x2 , int y2 , char* graphPath, void (*pFunc)(int) , int Int ){
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
		
	this->input.AddEventListener( Event.LMouse.Click( x1 , y1 , x2 , y2 ) , pFunc , Int );
}
void CScene::SetButton( int x1 , int y1 , int x2 , int y2 , char* Off_graphPath , char* On_graphPath , void (*pFunc)() ){
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
void CScene::SetButton( int x1 , int y1 , int x2 , int y2 , char* Off_graphPath , char* On_graphPath , void (*pFunc)(int) , int *pInt ){
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

	this->input.AddEventListener( Event.LMouse.Click( x1 , y1 , x2 , y2 ) , pFunc , pInt );

	buttonChild.push_back( temp );
}
void CScene::SetButton( int x1 , int y1 , int x2 , int y2 , char* Off_graphPath , char* On_graphPath , void (*pFunc)(int) , int Int ){
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

	this->input.AddEventListener( Event.LMouse.Click( x1 , y1 , x2 , y2 ) , pFunc , Int );

	buttonChild.push_back( temp );
}
void CScene::SetButton( int *x1 , int *y1 , int *x2 , int *y2 , int backColor , char *title , int stringColor , void (*pFunc)() ){
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
void CScene::SetButton( int *x1 , int *y1 , int *x2 , int *y2 , int backColor , char *title , int stringColor , void (*pFunc)(int) ,int *pInt ){
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

	this->input.AddEventListener( Event.LMouse.Click( x1 , y1 , x2 , y2 ) , pFunc ,pInt );
}
void CScene::SetButton( int *x1 , int *y1 , int *x2 , int *y2 , int backColor , char *title , int stringColor , void (*pFunc)(int) ,int Int ){
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

	this->input.AddEventListener( Event.LMouse.Click( x1 , y1 , x2 , y2 ) , pFunc ,Int );
}
void CScene::SetButton( int *x1 , int *y1 , int *x2 , int *y2 , int graph , void (*pFunc)() ){
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
void CScene::SetButton( int *x1 , int *y1 , int *x2 , int *y2 , int graph , void (*pFunc)(int) ,int *pInt ){
	CpButton temp;
	temp.IsUseGraph = true;
		
	temp.x1 = x1;
	temp.x2 = x2;
	temp.y1 = y1;
	temp.y2 = y2;
		
	temp.graphHandle = graph;

	pButtonChild.push_back( temp );

	this->input.AddEventListener( Event.LMouse.Click( x1 , y1 , x2 , y2 ) , pFunc ,pInt );
}
void CScene::SetButton( int *x1 , int *y1 , int *x2 , int *y2 , int graph , void (*pFunc)(int) ,int Int ){
	CpButton temp;
	temp.IsUseGraph = true;
		
	temp.x1 = x1;
	temp.x2 = x2;
	temp.y1 = y1;
	temp.y2 = y2;
		
	temp.graphHandle = graph;

	pButtonChild.push_back( temp );

	this->input.AddEventListener( Event.LMouse.Click( x1 , y1 , x2 , y2 ) , pFunc , Int );
}
void CScene::SetButton( int *x1 , int *y1 , int *x2 , int *y2 , char* graphPath , void (*pFunc)() ){
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
void CScene::SetButton( int *x1 , int *y1 , int *x2 , int *y2 , char* graphPath , void (*pFunc)(int) , int *pInt ){
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
		
	this->input.AddEventListener( Event.LMouse.Click( x1 , y1 , x2 , y2 ) , pFunc ,pInt );
}
void CScene::SetButton( int *x1 , int *y1 , int *x2 , int *y2 , char* graphPath , void (*pFunc)(int) , int Int ){
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
		
	this->input.AddEventListener( Event.LMouse.Click( x1 , y1 , x2 , y2 ) , pFunc ,Int );
}
void CScene::SetButton( int *x1 , int *y1 , int *x2 , int *y2 , char* Off_graphPath , char* On_graphPath , void (*pFunc)() ){
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
void CScene::SetButton( int *x1 , int *y1 , int *x2 , int *y2 , char* Off_graphPath , char* On_graphPath , void (*pFunc)(int) , int *pInt ){
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

	this->input.AddEventListener( Event.LMouse.Click( x1 , y1 , x2 , y2 ) , pFunc , pInt );

	pButtonChild.push_back( temp );
}
void CScene::SetButton( int *x1 , int *y1 , int *x2 , int *y2 , char* Off_graphPath , char* On_graphPath , void (*pFunc)(int) , int Int ){
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

	this->input.AddEventListener( Event.LMouse.Click( x1 , y1 , x2 , y2 ) , pFunc , Int );

	pButtonChild.push_back( temp );
}
//�������C�u���������֐��i�g�p�֎~�j
void CScene::ResetSceneNum(){
	sceneNum = 1;
}
unsigned int CScene::GetSerialNum(){
	return serialNum;
}


CGame::CGame(){
	useDrawLoopFlag =true;
	rootScene.ResetSceneNum();
}
CGame::~CGame(){
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
void CGame::AddChild(CScene* _scene){
		
	rootScene.SetFocus(false);

	_scene->SetFocus(true);
	sceneChild.push_back(_scene);

}
void CGame::RemoveChild(CScene* _scene){
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
void CGame::RemoveChild(){
	sceneChild.front()->SetFocus(false);
	sceneChild.pop_back();
		
	if(sceneChild.empty()){
		rootScene.SetFocus(true);
	}
}
void CGame::Loop(){
	
		Event.Loop();
	
	if( !sceneChild.size() == 0 ){

		sceneChild.back()->Loop();

	}else{
			
		rootScene.Loop();

	}
}

	
void CGame::SetUseDrawLoop(bool flag){
	useDrawLoopFlag = flag;
}
bool CGame::GetUseDrawLoop(){
	return useDrawLoopFlag;
}