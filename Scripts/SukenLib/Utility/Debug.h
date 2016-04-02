#pragma once
#include "DxLib.h"
#include "Utility.h"

namespace suken{

/**
*	@brief 数研ライブラリ独自デバッグ用関数
*	exeの動作を一時的に止め、エラーメッセージを表示する。
*	何かしらの操作をすることで復旧可能。
*	@param format 出力する警告文の書式付き文字列のアドレス
*/
inline void WarningSK(const char* format, ...){
#ifdef DEBUG
	 char tmpchar[256];
    sprintf_s(tmpchar, "警告 : \n\n%s\n\n", format);
	printfDx(tmpchar);
	printfDx("PRESS ANY KEY TO CONTINUE...");
    ScreenFlip();
    WaitKey();
    clsDx();
    ClearDrawScreen();
#endif
}

///エラー&デバッグ出力用関数///////////////////////////////////////////////////////
/**
*	@brief 説明
*/
#define ERRORDX(...)     ErrorDx(__LINE__, __FUNCTION__, __FILE__,  __VA_ARGS__)
/**
*	@brief 説明
*/
#define WARNINGDX(...) WarningDx(__LINE__, __FUNCTION__, __FILE__,  __VA_ARGS__)
/**
*	@brief 説明
*/
#define DEBUGDX(...)     DebugDx(__LINE__, __FUNCTION__, __FILE__,  __VA_ARGS__)
 
/**
*	@brief 説明
*/
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

/**
*	@brief 説明
*	@param value 引数
*/
inline void myLog(const char* format, ...){
    va_list args;
    va_start(args, format);
    myprintLog("MyLog", format, args);
    va_end(args);
}

/**
*	@brief 説明
*	@param value 引数
*/
inline void myLogf(const char* filename, const char* format, ...){
    va_list args;
    va_start(args, format);
    myprintLog(filename, format, args);
    va_end(args);
}

/**
*	@brief 説明
*	@param value 引数
*/
inline void myprintfDx(const char*format, va_list args, const char* filename=nullptr, int line=0){
    char string[1024];
    vsprintf_s(string, format, args);   //va_startとva_endは呼び出し元でする
    if (filename!=nullptr) sprintf_s(string, "%s\n->%s(%d)\n", string, filename, line);
 
    myLogf("MyLog_Printed", "PRINT: %s", string);
    printfDx(string);
    ScreenFlip();
    WaitKey();
    clsDx();
    ClearDrawScreen();
}

/**
*	@brief 説明
*	@param value 引数
*/
inline void ErrorDx(int line, const char* func, const char* filename, const char* format, ...){
    char tmpchar[256];
    va_list args;   va_start(args, format);
    sprintf_s(tmpchar, "Error->%s\n->%s", format, func);
    myprintfDx(tmpchar, args, filename, line);
    va_end(args);
}

/**
*	@brief 説明
*	@param value 引数
*/
inline void ErrorDx(const char* format, char* filename, int line, ...){
    va_list args;
    va_start(args, line);
    myprintfDx(format, args, filename, line);
    va_end(args);
}

/**
*	@brief 説明
*	@param value 引数
*/
inline void ErrorDx(const char* format, ...){
    va_list args;
    va_start(args, format);
    myprintfDx(format, args);
    va_end(args);
}

/**
*	@brief 説明
*	@param value 引数
*/
inline void WarningDx(int line, const char* func, const char* filename, const std::string format, ...){
    #ifndef WARNINGDX_DISABLE 
        char tmpchar[256];
        va_list args;   va_start(args, format);
        sprintf_s(tmpchar, "Warning->%s\n->%s", format, func);
        myprintfDx(tmpchar, args, filename, line);
        va_end(args);
    #endif
}

/**
*	@brief 説明
*	@param value 引数
*/
inline void WarningDx(const char* format, char* filename, int line, ...){
    #ifndef WARNINGDX_DISABLE 
        va_list args;
        va_start(args, line);
        myprintfDx(format, args, filename, line);
        va_end(args);
    #endif
}

/**
*	@brief 説明
*	@param value 引数
*/
inline void WarningDx(const char* format, ...){
    #ifndef WARNINGDX_DISABLE 
        va_list args;
        va_start(args, format);
        myprintfDx(format, args);
        va_end(args);
    #endif
}

/**
*	@brief 説明
*	@param value 引数
*/
inline void DebugDx(int line, const char* func, const char* filename, const char* format, ...){
    #ifndef DEBUGDX_DISABLE 
        char tmpchar[256];
        va_list args;   va_start(args, format);
        sprintf_s(tmpchar, "Debug->%s\n->%s", format, func);
        myprintfDx(tmpchar, args, filename, line);
        va_end(args);
    #endif
}

/**
*	@brief 説明
*	@param value 引数
*/
inline void DebugDx(const char* format, const char* filename, int line, ...){
    #ifndef DEBUGDX_DISABLE 
        va_list args;
        va_start(args, line);
        myprintfDx(format, args, filename, line);
        va_end(args);
    #endif
}

/**
*	@brief 説明
*	@param value 引数
*/
inline void DebugDx(const char* format, ...){
    #ifndef DEBUGDX_DISABLE 
        va_list args;
        va_start(args, format);
        myprintfDx(format, args);
        va_end(args);
    #endif
}


}