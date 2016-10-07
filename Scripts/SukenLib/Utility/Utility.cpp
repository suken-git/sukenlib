#include"Utility.h"

#include "../System/System.h"
# include <cmath>
# include <algorithm>

namespace megademo  // http://www.demoscene.jp/?p=1460
{
	float Fraction( float v )
	{
		return v - floor(v);
	}

	struct HSV
	{
		HSV(){}

		HSV( float h_, float s_, float v_ ) : h(h_),s(s_),v(v_){}

		float h;	// ... 0°==0.0f, 360°==1.0f ...
		
		float s,v;	// [0.0f, 1.0f]
	};

	RGB HSVtoRGB( const HSV& hsv )
	{
		const float h = Fraction(hsv.h);
		const float s = hsv.s;
		const float v = hsv.v;
		const float hueF = h * 6.0f;
		const int hueI = static_cast<int>(hueF);
		const float fr = hueF - hueI;
		const float m = v * (1.0f-s);
		const float n = v * (1.0f-s*fr);
		const float p = v * (1.0f-s*(1.0f-fr));

		RGB rgb;

		switch(hueI)
		{
			case 0: rgb.r = v; rgb.g = p; rgb.b = m; break;
			case 1: rgb.r = n; rgb.g = v; rgb.b = m; break;
			case 2: rgb.r = m; rgb.g = v; rgb.b = p; break;
			case 3: rgb.r = m; rgb.g = n; rgb.b = v; break;
			case 4: rgb.r = p; rgb.g = m; rgb.b = v; break;
			default: rgb.r = v; rgb.g = m; rgb.b = n; break;
		}

		return rgb;
	}
	
	HSV RGBtoHSV( const RGB& rgb )
	{
		const float min = std::min<float>(std::min<float>(rgb.r,rgb.g),rgb.b);
		const float max = std::max<float>(std::max<float>(rgb.r,rgb.g),rgb.b);

		HSV hsv(0.0f,0.0f,max);	

		const float delta = max - min;

		if(delta!=0.0f)
		{
			hsv.s = delta / max;

			if(rgb.r==max)
			{
				hsv.h = (rgb.g-rgb.b) / delta;
			}
			else if(rgb.g==max)
			{
				hsv.h = 2.0f + (rgb.b-rgb.r) / delta;
			}
			else
			{
				hsv.h = 4.0f + (rgb.r-rgb.g) / delta;
			}
		
			hsv.h /= 6.0f;

			if(hsv.h<0.0f)
			{
				hsv.h += 1.0f;
			}
		}

		return hsv;
	}

}

float rainbow = 0;

int count;

megademo::RGB rgb;

megademo::HSV hsv;

int suken::RainBow(int time){
	hsv.h = rainbow+(float)(time/100);
	hsv.s = 1;
	hsv.v = 1;
	rgb = megademo::HSVtoRGB(hsv);
	if(count != System.GetFrame()){
		rainbow += 0.01f;
		if(rainbow > 1)rainbow = 0;
		count = System.GetFrame();
	}
	return GetColor(rgb.r*255,rgb.g*255,rgb.b*255);
}

int suken::GetColorHSV(int h,int s,int v){
	hsv.h = h / 255;
	hsv.s = s / 255;
	hsv.v = v / 255;
	rgb = megademo::HSVtoRGB(hsv);
	return GetColor(rgb.r*255,rgb.g*255,rgb.b*255);
}

bool suken::SelectOpenFile( char* filename ,  char* filetype)
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
bool suken::SaveFile( char* filename , char* filetype)
{
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


void suken::SukenExecute(std::string URL)
{
		OSVERSIONINFO OSver;
		OSver.dwOSVersionInfoSize =sizeof(OSVERSIONINFO);
		GetVersionEx(&OSver);
		if(OSver.dwMajorVersion < 6 ){//XP以下
			ShellExecute( nullptr, "open", "IExplore",URL.c_str(), nullptr,SW_SHOWNORMAL );
		}else{//Vista以上
			ShellExecute( nullptr, "open",URL.c_str(), nullptr, nullptr,SW_SHOWNORMAL );
		}
}

/// FROM NUNULIB
//現在時刻取得関数///////////////////////////////////////////
SYSTEMTIME suken::GetNowSystemTime()
{
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
std::string suken::GetNowSystemTimeString()
{
    char currentTime[25] = { 0 };
    SYSTEMTIME st = suken::GetNowSystemTime();
    wsprintf(currentTime, "%04d/%02d/%02d %02d:%02d:%02d %03d",
        st.wYear, st.wMonth, st.wDay,
        st.wHour, st.wMinute, st.wSecond, st.wMilliseconds); 
    std::string tmp = currentTime;
    return tmp;
}
//DrawCenterString Notフォーマット版
int suken::DrawCenterString(int cx, int y, int color, const TCHAR* format, ...)
{
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
int suken::DrawCenterString(int cx, int y, int color, bool centerY, const TCHAR* format, ...)
{ //フォーマット版
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
void suken::AddFontFromPath(std::string path)
{

	LPCSTR font_path = path.c_str(); // 読み込むフォントファイルのパス
		if (AddFontResourceEx(font_path, FR_PRIVATE, nullptr) > 0) {
		
		} else {
			// フォント読込エラー処理
			MessageBox(nullptr,"フォント読込失敗","",MB_OK);
		}
}


//階乗
unsigned int suken::fanctorial(unsigned int num)
{
	if(num <= 1){
		return 1;
	}else{
		return ( num * suken::fanctorial( num - 1 ) );
	}
}
//組み合わせ（nとrはそれぞれ「nCr」のnとr）
unsigned int suken::combination(unsigned int n , unsigned int r)
{
	return ( suken::fanctorial( n ) / ( suken::fanctorial( n-r ) * suken::fanctorial( r ) ) );
}

