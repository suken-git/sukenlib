#include"Key.h"
#include "Event.h"
#include <Utility\Debug.h>


void suken::CKey::Loop(){
	 //全てのキーの押下状態を取得
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
bool suken::CKey::GetPush(int keyCode){
	 //キーコードチェック
	if( keyCode < 256 && keyCode >= 0 ){
		if( count[keyCode] < 1.0f ){
			return Event.GetValid(); 
		}else{
			return false;
		}
	 }else{
		WarningSK("CKey::GetPushの引数に不正なキーコードが入力されました\nキーコード　：　%d",keyCode);
		return false;
	 }
 }
 bool suken::CKey::GetDown(int keyCode){
	 //キーコードチェック
	 if( keyCode < 256 && keyCode >= 0 ){
		if( count[keyCode] == 0.0f ){
			return Event.GetValid(); 
		}else{
			return false;
		}
	 }else{
		WarningSK("CKey::GetDownの引数に不正なキーコードが入力されました\nキーコード　：　%d",keyCode);
		return false;
	 }
}
 bool suken::CKey::GetUp(int keyCode){
	//キーコードチェック
	if( keyCode < 256 && keyCode >= 0 ){
		if( count[keyCode] == 1.5f ){
			return Event.GetValid(); 
		}else{
			return false;			
		}
	}else{
		WarningSK("CKey::GetUpの引数に不正なキーコードが入力されました\nキーコード　：　%d",keyCode);
		return false;
	}
}
int suken::CKey::GetCount(int keyCode){
	//キーコードチェック
		if( keyCode < 256 && keyCode >= 0 ){
		return (int)(count[keyCode]);
	}else{
		WarningSK("CKey::GetCountの引数に不正なキーコードが入力されました\nキーコード　：　%d",keyCode);
		return -1;
	}
}
