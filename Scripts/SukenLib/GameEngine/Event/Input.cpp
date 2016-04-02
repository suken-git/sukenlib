#include "DxLib.h"
#include"Input.h"
#include"Event.h"

suken::CInput::CInput(){
	useMouse = true;
	useKey = true;
}	
void suken::CInput::AddEventListener( int inputCode , void func() ){
				
	keyTemp.keyCode=inputCode;
	keyTemp.pFuncVoid=func;
	keyTask.push_back(keyTemp);

}
void suken::CInput::AddEventListener( int inputCode , void func(int) , int *pArgument ){
				
	keyTemp.keyCode=inputCode;
	keyTemp.pFuncInt=func;
	keyTemp.pInt = pArgument;
	keyTask.push_back(keyTemp);

}
void suken::CInput::AddEventListener( int inputCode , void func(int) , int Argument ){
				
	keyTemp.keyCode=inputCode;
	keyTemp.pFuncInt=func;
	keyTemp.Int = Argument;
	keyTask.push_back(keyTemp);

}
void suken::CInput::RemoveEventListener( int inputCode , void func()  ){

	for (auto it = keyTask.begin(); it != keyTask.end();it ++ ){
		if( it->keyCode == inputCode && it->pFuncVoid == func  ){
			keyTask.erase( it );
			break;
		}	
	}	
}
void suken::CInput::RemoveEventListener( int inputCode , void func(int) , int *pArgument  ){
	for(auto it = keyTask.begin(); it != keyTask.end(); it++){
		if( it->keyCode == inputCode && it->pFuncInt == func && it->pInt == pArgument ){
			keyTask.erase( it );
			break;
		}
	}
		
}
void suken::CInput::RemoveEventListener( int inputCode , void func(int) , int Argument  ){

	for(auto it = keyTask.begin(); it != keyTask.end(); it++){
		if( it->keyCode == inputCode && it->pFuncInt == func  && it->Int == Argument ){
			keyTask.erase( it );
			break;
		}
	}
		
}
void suken::CInput::AddEventListener( CMouseIn input , void func()  ){

	mouseTemp=input;
	mouseTemp.pFuncVoid=func;
	mouseTask.push_back(mouseTemp);
				
}
void suken::CInput::AddEventListener( CMouseIn input , void func(int) , int *pArgument  ){

	mouseTemp=input;
	mouseTemp.pFuncInt=func;
	mouseTemp.pInt = pArgument;
	mouseTask.push_back(mouseTemp);
				
}
void suken::CInput::AddEventListener( CMouseIn input , void func(int) , int Argument  ){

	mouseTemp=input;
	mouseTemp.pFuncInt=func;
	mouseTemp.Int = Argument;
	mouseTask.push_back(mouseTemp);
				
}
void suken::CInput::RemoveEventListener( CMouseIn input , void func()  ){

	for(auto it = mouseTask.begin(); it != mouseTask.end(); it++){
		if( it->pFuncVoid == func && it->type == input.type && it->x1 == input.x1 && it->x2 == input.x2 && it->y1 == input.y1 && it->y2 == input.y2  ){
			mouseTask.erase( it );
			break;
		}
	}
		
}
void suken::CInput::RemoveEventListener( CMouseIn input , void func(int) , int *pArgument  ){

	for(auto it = mouseTask.begin(); it != mouseTask.end(); it++){
		if( it->pFuncInt == func && it->type == input.type && it->x1 == input.x1 && it->x2 == input.x2 && it->y1 == input.y1 && it->y2 == input.y2 && it->pInt == pArgument ){
			mouseTask.erase( it );
			break;
		}
	}
		
}
void suken::CInput::RemoveEventListener( CMouseIn input , void func(int) , int Argument  ){

	for(auto it = mouseTask.begin(); it != mouseTask.end(); it++){
		if( it->pFuncInt == func && it->type == input.type && it->x1 == input.x1 && it->x2 == input.x2 && it->y1 == input.y1 && it->y2 == input.y2  && it->Int == Argument ){
			mouseTask.erase( it );
			break;
		}
	}
		
}
void suken::CInput::AddEventListener( CpMouseIn input , void func()  ){

	pMouseTemp=input;
	pMouseTemp.pFuncVoid=func;
	pMouseTask.push_back(pMouseTemp);
				
}
void suken::CInput::AddEventListener( CpMouseIn input , void func(int) , int *pArgument  ){

	pMouseTemp=input;
	pMouseTemp.pFuncInt=func;
	pMouseTemp.pInt = pArgument;
	pMouseTask.push_back(pMouseTemp);
				
}
void suken::CInput::AddEventListener( CpMouseIn input , void func(int) , int Argument  ){

	pMouseTemp=input;
	pMouseTemp.pFuncInt=func;
	pMouseTemp.Int = Argument;
	pMouseTask.push_back(pMouseTemp);
				
}
void suken::CInput::RemoveEventListener( CpMouseIn input , void func()  ){

	for(auto it = pMouseTask.begin(); it != pMouseTask.end(); it++){
		if( it->pFuncVoid == func && it->type == input.type && it->x1 == input.x1 && it->x2 == input.x2 && it->y1 == input.y1 && it->y2 == input.y2  ){
			pMouseTask.erase( it );
			break;
		}
	}
}
void suken::CInput::RemoveEventListener( CpMouseIn input , void func(int) , int *pArgument  ){

	for(auto it = pMouseTask.begin(); it != pMouseTask.end(); it++){
		if( it->pFuncInt == func && it->type == input.type && it->x1 == input.x1 && it->x2 == input.x2 && it->y1 == input.y1 && it->y2 == input.y2  && it->pInt == pArgument ){
			pMouseTask.erase( it );
			break;
		}
	}
}
void suken::CInput::RemoveEventListener( CpMouseIn input , void func(int) , int Argument  ){

	for(auto it = pMouseTask.begin(); it != pMouseTask.end(); it++){
		if( it->pFuncInt == func && it->type == input.type && it->x1 == input.x1 && it->x2 == input.x2 && it->y1 == input.y1 && it->y2 == input.y2  && it->Int == Argument ){
			pMouseTask.erase( it );
			break;
		}
	}
}
void suken::CInput::AddEventListener( char input , void func()  ){
	frameTemp.pFuncVoid=func;
	frameTask.push_back(frameTemp);
			
}
void suken::CInput::AddEventListener( char input , void func(int) , int *pArgument  ){
	frameTemp.pFuncInt=func;
	frameTemp.pInt = pArgument;
	frameTask.push_back(frameTemp);
			
}
void suken::CInput::AddEventListener( char input , void func(int) , int Argument  ){
	frameTemp.pFuncInt=func;
	frameTemp.Int = Argument;
	frameTask.push_back(frameTemp);
			
}
void suken::CInput::RemoveEventListener( char input , void func()  ){
	for(auto it = frameTask.begin(); it != frameTask.end(); it++){
		if( it->pFuncVoid ==  func  ){
			frameTask.erase( it );
			break;
		}
	}		
}
void suken::CInput::RemoveEventListener( char input , void func(int) , int *pArgument  ){
	for(auto it = frameTask.begin(); it != frameTask.end(); it++){
		if( it->pFuncInt ==  func  && it->pInt == pArgument ){
			frameTask.erase( it );
			break;
		}
	}
		
}
void suken::CInput::RemoveEventListener( char input , void func(int) , int Argument  ){

	for(auto it = frameTask.begin(); it != frameTask.end(); it++){
		if( it->pFuncInt ==  func  && it->Int == Argument ){
			frameTask.erase( it );
			break;
		}
	}		
}
void suken::CInput::AddEventListener( bool* input , void func()  ){
	boolTemp.pFuncVoid=func;
	boolTemp.pBool=input;
	boolTask.push_back(boolTemp);
			
}
void suken::CInput::AddEventListener( bool* input , void func(int) , int *pArgument  ){
	boolTemp.pFuncInt=func;
	boolTemp.pInt = pArgument;
	boolTemp.pBool=input;
	boolTask.push_back(boolTemp);
			
}
void suken::CInput::AddEventListener( bool* input , void func(int) , int Argument  ){
	boolTemp.pFuncInt=func;
	boolTemp.Int = Argument;
	boolTemp.pBool=input;
	boolTask.push_back(boolTemp);
			
}
void suken::CInput::RemoveEventListener( bool* input , void func()  ){
	for(auto it = boolTask.begin(); it != boolTask.end(); it++){
		if( it->pBool == input && it->pFuncVoid == func  ){
			boolTask.erase( it );
			break;
		}
	}	
}	
void suken::CInput::RemoveEventListener( bool* input , void func(int) , int *pArgument  ){

	for(auto it = boolTask.begin(); it != boolTask.end(); it++){	
		if( it->pBool == input && it->pFuncInt == func  && it->pInt == pArgument ){
			boolTask.erase( it );
			break;
		}
	}	
}
void suken::CInput::RemoveEventListener( bool* input , void func(int) , int Argument  ){

	for(auto it = boolTask.begin(); it != boolTask.end(); it++){
		if( it->pBool == input && it->pFuncInt == func  && it->Int == Argument ){
			boolTask.erase( it );
			break;
		}
	}
	
}
void suken::CInput::Loop(){

		
	//KEY
	if(useKey){


		std::vector<CKeyIn>::iterator it=keyTask.begin();

		while( it != keyTask.end() ) {
			if(Event.key.GetPush(it->keyCode)){
					
				CKeyIn temp=*it;
				if(temp.pFuncVoid != nullptr){
					temp.pFuncVoid();
				}else{
					if(temp.pInt == nullptr){
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

		std::vector<CMouseIn>::iterator it1=mouseTask.begin();

		while( it1 != mouseTask.end() ) {

			CMouseIn temp = *it1;
			
			switch(temp.type){
				
			case MOUSE_OFF :
				if(temp.x1>mouseX && temp.x2<mouseX ){
					if(temp.y1>mouseY && temp.y2<mouseY){
						
						if(temp.pFuncVoid != nullptr){
							temp.pFuncVoid();
						}else{
							if(temp.pInt == nullptr){
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
						
						if(temp.pFuncVoid != nullptr){
							temp.pFuncVoid();
						}else{
							if(temp.pInt == nullptr){
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
							
							if(temp.pFuncVoid != nullptr){
								temp.pFuncVoid();
							}else{
								if(temp.pInt == nullptr){
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
							
							if(temp.pFuncVoid != nullptr){
								temp.pFuncVoid();
							}else{
								if(temp.pInt == nullptr){
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
								
							if(temp.pFuncVoid != nullptr){
								temp.pFuncVoid();
							}else{
								if(temp.pInt == nullptr){
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

		std::vector<CpMouseIn>::iterator it11 =pMouseTask.begin();

			while( it11 != pMouseTask.end() ) {

				CpMouseIn temp = *it11;
					
					
				switch(temp.type){
				
				case MOUSE_OFF :
					if( *(temp.x1) > mouseX && *(temp.x2) < mouseX ){
						if( *(temp.y1) > mouseY && *(temp.y2) < mouseY ){
								
							if(temp.pFuncVoid != nullptr){
								temp.pFuncVoid();
							}else{
								if(temp.pInt == nullptr){
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
								
							if(temp.pFuncVoid != nullptr){
								temp.pFuncVoid();
							}else{
								if(temp.pInt == nullptr){
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
									
								if(temp.pFuncVoid != nullptr){
									temp.pFuncVoid();
								}else{
									if(temp.pInt == nullptr){
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
									
								if(temp.pFuncVoid != nullptr){
									temp.pFuncVoid();
								}else{
									if(temp.pInt == nullptr){
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
									
								if(temp.pFuncVoid != nullptr){
									temp.pFuncVoid();
								}else{
									if(temp.pInt == nullptr){
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


	std::vector<CFrame>::iterator it2 = frameTask.begin();

	while( it2 != frameTask.end() ) {
		CFrame temp=*it2;

		if(temp.pFuncVoid != nullptr){
			temp.pFuncVoid();
		}else{
			if(temp.pInt == nullptr){
				temp.pFuncInt(temp.Int);
			}else{
				temp.pFuncInt(*temp.pInt);
			}
		}
		it2++;
	}

	std::vector<CBoolean>::iterator it3=boolTask.begin();

	while( it3 != boolTask.end() ) {
			
		CBoolean temp=*it3;

		if(*(temp.pBool)){
			
			if(temp.pFuncVoid != nullptr){
				temp.pFuncVoid();
			}else{
				if(temp.pInt == nullptr){
					temp.pFuncInt(temp.Int);
				}else{
					temp.pFuncInt(*temp.pInt);
				}
			}

		}

		it3++;
	}

}//end of void Loop()
void suken::CInput::DrawLoop(){
	//KEY
	if(useKey){

		std::vector<CKeyIn>::iterator it=keyTask_Draw.begin();

		while( it != keyTask_Draw.end() ) {
			if(CheckHitKey(it->keyCode)){

				CKeyIn temp=*it;
				if(temp.pFuncVoid != nullptr){
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

		std::vector<CMouseIn>::iterator it1=mouseTask_Draw.begin();

		while( it1 != mouseTask_Draw.end() ) {

			CMouseIn temp = *it1;
			
			switch(temp.type){
				
			case MOUSE_OFF :
				if(temp.x1>mouseX && temp.x2<mouseX ){
					if(temp.y1>mouseY && temp.y2<mouseY){
							
						if(temp.pFuncVoid != nullptr){
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
							
						if(temp.pFuncVoid != nullptr){
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
								
							if(temp.pFuncVoid != nullptr){
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
								
							if(temp.pFuncVoid != nullptr){
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
								
							if(temp.pFuncVoid != nullptr){
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

		std::vector<CpMouseIn>::iterator it11 =pMouseTask_Draw.begin();

		while( it11 != pMouseTask_Draw.end() ) {

			CpMouseIn temp = *it11;
					
					
			switch(temp.type){
				
			case MOUSE_OFF :
				if( *(temp.x1) > mouseX && *(temp.x2) < mouseX ){
					if( *(temp.y1) > mouseY && *(temp.y2) < mouseY ){
								
						if(temp.pFuncVoid != nullptr){
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
								
						if(temp.pFuncVoid != nullptr){
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
							if(temp.pFuncVoid != nullptr){
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
								
							if(temp.pFuncVoid != nullptr){
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
								
							if(temp.pFuncVoid != nullptr){
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
	//ÉãÅ[Év
	std::vector<CFrame>::iterator it2=frameTask_Draw.begin();

	while( it2 != frameTask_Draw.end() ) {
		CFrame temp=*it2;
		if(temp.pFuncVoid != nullptr){
			temp.pFuncVoid();
		}else{
			temp.pFuncInt(*temp.pInt);
		}
		it2++;
	}
		
	//bool
	std::vector<CBoolean>::iterator it3=boolTask_Draw.begin();

	while( it3 != boolTask_Draw.end() ) {
		CBoolean temp=*it3;

		if(*(temp.pBool)){
			
			if(temp.pFuncVoid != nullptr){
				temp.pFuncVoid();
			}else{
				temp.pFuncInt(*temp.pInt);
			}
		}

		it3++;
	}
}//end of DrawLoop()
