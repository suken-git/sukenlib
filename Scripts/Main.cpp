#include"Suken.h"
#include"Array.h"
Array<int> A(0,5);
void Awake(){
	
	for(int i=0;i<A.size();i++){
		A[i] = i*i;
	}
	//�킴�Ƒ��݂��Ȃ��v�f�փA�N�Z�X
	A[5] = 9;
}
void GameLoopEnter(){
	
}
void GameLoopExit(){
	for(int i=0;i<A.size();i++){
		DrawFormatString(100,50+30*i,YELLOW,"%d : %d",i,A[i]);
	}
	
	
}