#include"Utility.h"




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
    ofn.lpstrTitle = "ファイルを開く";
    if (!GetOpenFileName(&ofn)) return FALSE; // キャンセル

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
        ofn.lpstrInitialDir     = szPath;       // 初期フォルダ位置
        ofn.lpstrFile           = filename;       // 選択ファイル格納
        ofn.nMaxFile            = MAX_PATH;
        ofn.lpstrDefExt         = TEXT(".*");
        ofn.lpstrFilter         = filetype;
        ofn.lpstrTitle          = TEXT("ファイルを保存します。");
        ofn.Flags               = OFN_FILEMUSTEXIST | OFN_OVERWRITEPROMPT;
    }
    if ( GetSaveFileName(&ofn) ){
        MessageBox( GetMainWindowHandle(), filename, TEXT("ファイル名を付けて保存"), MB_OK );
    }

	return true;
}


void SukenExecute(char *URL){
		OSVERSIONINFO OSver;
		OSver.dwOSVersionInfoSize =sizeof(OSVERSIONINFO);
		GetVersionEx(&OSver);
		if(OSver.dwMajorVersion < 6 ){//XP以下
			ShellExecute( NULL, "open", "IExplore",URL, NULL,SW_SHOWNORMAL );
		}else{//Vista以上
			ShellExecute( NULL, "open",URL, NULL, NULL,SW_SHOWNORMAL );
		}
}

/*

void GetHttpFile(char *&Buf, char *Http,DWORD ReadSize){
	HINTERNET hInternet;HINTERNET hFile;
	BOOL bResult;
	DWORD RealRead = ReadSize;
	// WININET初期化 
	hInternet = InternetOpenA("WININET Sample Program",INTERNET_OPEN_TYPE_PRECONFIG,	NULL,NULL,0);
	if(!hInternet)return;
	// URLのオープン 
	hFile = InternetOpenUrlA(hInternet,Http,	NULL,0,	INTERNET_FLAG_RELOAD,0);
	if(!hFile){if(hInternet)InternetCloseHandle(hInternet);return;}
	bResult = InternetReadFile(hFile,Buf,RealRead,&ReadSize);
	if(!bResult) {return;if(hFile)InternetCloseHandle(hFile);if(hInternet)InternetCloseHandle(hInternet);}
	Buf[ReadSize] = '\0';
	if(hFile)InternetCloseHandle(hFile);
	if(hInternet)InternetCloseHandle(hInternet);
}

原因不明エラーのためコメントアウト
1>Utility.obj : error LNK2019: 未解決の外部シンボル __imp__InternetReadFile@16 が関数 "void __cdecl GetHttpFile(char * &,char *,unsigned long)" (?GetHttpFile@@YAXAAPADPADK@Z) で参照されました。
1>Utility.obj : error LNK2019: 未解決の外部シンボル __imp__InternetCloseHandle@4 が関数 "void __cdecl GetHttpFile(char * &,char *,unsigned long)" (?GetHttpFile@@YAXAAPADPADK@Z) で参照されました。
1>Utility.obj : error LNK2019: 未解決の外部シンボル __imp__InternetOpenUrlA@24 が関数 "void __cdecl GetHttpFile(char * &,char *,unsigned long)" (?GetHttpFile@@YAXAAPADPADK@Z) で参照されました。
1>Utility.obj : error LNK2019: 未解決の外部シンボル __imp__InternetOpenA@20 が関数 "void __cdecl GetHttpFile(char * &,char *,unsigned long)" (?GetHttpFile@@YAXAAPADPADK@Z) で参照されました。

*/

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


/// FROM NUNULIB
//現在時刻取得関数///////////////////////////////////////////
SYSTEMTIME GetNowSystemTime(){
    SYSTEMTIME st;
    GetSystemTime(&st);
     
    FILETIME ft1;
    FILETIME ft2;
    SystemTimeToFileTime(&st, &ft1);
     
    //a こちらでもOK。動作は確認済み。
    //long long int t = (long long int)(ft1.dwHighDateTime)<<32 | ft1.dwLowDateTime;
    //t += (long long int)9*60*60*1000*1000*10; //1日・・・24*60*60*1000*1000*10 
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
//DrawCenterString Notフォーマット版
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
int DrawCenterString(int cx, int y, int color, bool centerY, const TCHAR* format, ...){ //フォーマット版
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

//フォント追加（パス入力必須）
void AddFontFromPath(char *path){

	LPCSTR font_path = path; // 読み込むフォントファイルのパス
		if (AddFontResourceEx(font_path, FR_PRIVATE, NULL) > 0) {
		
		} else {
			// フォント読込エラー処理
			MessageBox(NULL,"フォント読込失敗","",MB_OK);
		}
}


//階乗
unsigned int fanctorial(unsigned int num){
	if(num <= 1){
		return 1;
	}else{
		return ( num * fanctorial( num - 1 ) );
	}
}
//組み合わせ（nとrはそれぞれ「nCr」のnとr）
unsigned int combination(unsigned int n , unsigned int r){
	return ( fanctorial( n ) / ( fanctorial( n-r ) * fanctorial( r ) ) );
}

//ベジェ曲線

//ベジェ曲線頂点データの作成
////ベジェ曲線の計算をマイフレームするのは無駄なので計算済みのデータを作成する
//引数
// In　　　　: 制御点（Vector2D型）を指定する（2つ以上）
// vertexNum : 作成するデータの細かさを指定（ベジェ曲線の構成頂点の数）
BEZIER GetBezier(vector<suken::Vector2D> &In , unsigned int vertexNum ){
	
	const int N = In.size();
	BEZIER vertexes;
	vertexes.push_back(In[0]);
	float t = 0.0f;

	for(unsigned int j = 0; j < vertexNum; j++){

		 t += ( 1.0f / (float)vertexNum ) ;

		suken::Vector2D vertex ;
		
		for( int i = 0; i < N; i++ ){
			
			float temp = (float)( combination( N-1 , i ) * pow( 1-t , N-i-1  ) * pow( t , i ) );

			vertex += In[i] * temp;

		}

		vertexes.push_back(vertex);
	}
	
	return vertexes;
}
//ベジェ曲線の描画（ GetBezier関数で作成したデータが必要　）
////GetBezier関数で作成したデータを用いてベジェ曲線を描画する
//引数
// data  : GetBezier関数で作成したベジェ曲線データ
// color : 描画色を指定
void DrawBezier( BEZIER &data ,  int color ){
	for(unsigned int i = 0; i < data.size() - 1; i++){
		DrawLine( (int)data[ i ].x ,(int)data[ i ].y , (int)data[ i+1 ].x , (int)data[ i+1 ].y , color );
	}
}

