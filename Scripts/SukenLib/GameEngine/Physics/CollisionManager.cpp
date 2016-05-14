#include"CollosionManager.h"
#include <Utility/Utility.h>
using namespace suken;

suken::CCollisionManager::CCollisionManager()
{
	
}
suken::CCollisionManager::~CCollisionManager()
{
	
}
void suken::CCollisionManager::Awake()
{
	
}
void suken::CCollisionManager::Loop()
{
		
	for(unsigned int i=0;i<physicsCircle.size();i++){
		physicsCircle[i]->SetCollisionState( false );
		physicsCircle[i]->Loop();
	}
	for(unsigned int i=0;i<fixedCircle.size();i++){
		fixedCircle[i]->SetCollisionState( false );
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
		if(physicsCircle[i]->center.position.x > System.GetWindowX() ){
			physicsCircle[i]->center.velocity.x = -(physicsCircle[i]->center.velocity.x);
			physicsCircle[i]->center.position.x = System.GetWindowX() ;
		}
		if(physicsCircle[i]->center.position.y < 0){
			physicsCircle[i]->center.velocity.y = -(physicsCircle[i]->center.velocity.y);
			physicsCircle[i]->center.position.y = 0;
		}
		if(physicsCircle[i]->center.position.y > System.GetWindowY() ){
			physicsCircle[i]->center.velocity.y = -(physicsCircle[i]->center.velocity.y);
			physicsCircle[i]->center.position.y = System.GetWindowY();
		}
	}*/
		
}
void suken::CCollisionManager::DrawLoop()
{
	
}
void suken::CCollisionManager::CollisionCircleCalc(CCircle &A , CCircle &B ,float time)
{
		
	float totalWeight = A.mass + B.mass;				//質量和
	float reflectionRate = (1 + A.bound * B.bound );	// 反発率
	suken::Vector2D C = VNorm( B.center.position - A.center.position ); // 衝突軸ベクトル
	float dot = VDot( ( A.center.velocity - B.center.velocity ), C ); // 内積算出
	suken::Vector2D constVec = C * ( reflectionRate * dot / totalWeight ); // 定数ベクトル

	//速度書き換え
	// 衝突後位置の算出
	if(!A.IsKinematic){
		A.center.velocity += constVec * (-B.mass);
		A.center.position += (A.center.velocity) * 0.05f;
	}
	if(!B.IsKinematic){
		B.center.velocity += constVec  * A.mass ;
		B.center.position += (B.center.velocity) * 0.05f;
	}

}
bool suken::CCollisionManager::CollisionCircle(CCircle &A , CCircle &B)
{
	// 前位置及び到達位置におけるパーティクル間のベクトルを算出
	suken::Vector2D C0 = B.center.prePosition - A.center.prePosition;
	suken::Vector2D C1 = B.center.position - A.center.position;
	suken::Vector2D D = C1 - C0;

	// 衝突判定用の2次関数係数の算出
	float P = VSquareSize( D ); 
	// 同じ方向に移動
	if(P==0){ 
		return false; 
	}
	float Q = VDot( C0, D );
	float R = VSquareSize( C0 );

	// 距離
	float r = A.radius + B.radius;

	 // 衝突判定式
	float Judge = Q*Q - P*(R-r*r);

	if( Judge < 0 ){
	// 衝突していない
		return false;
	}

	// 衝突時間の算出
	float t_plus = (-Q + sqrt( Judge ) ) / P;
	float t_minus = ( -Q - sqrt( Judge ) ) / P;

	// 衝突位置の決定
	suken::Vector2D pOut_colli_A = A.center.prePosition + ( A.center.position - A.center.prePosition) * t_minus;
	suken::Vector2D pOut_colli_B = B.center.prePosition + ( B.center.position - B.center.prePosition) * t_minus;

   // 衝突時間の決定（t_minus側が常に最初の衝突）
   float pOut_t0 = t_minus;
   float pOut_t1 = t_plus;

	// 時間内衝突できるか？
   // t_minusが1より大きいと届かず衝突していない
   // t_plus、t_minusが両方ともマイナスだと反対方向なので衝突しない
   if( (t_minus > 1) || (t_minus < 0 && t_plus < 0) ){
      return false;
   }

   //衝突処理
   A.SetCollisionState(true);
   B.SetCollisionState(true);

   A.OnCollisionFunc();
   B.OnCollisionFunc();
#ifdef DEBUG_DRAW
   DxLib::DrawCircle((int)(A.center.position.x +0.5), (int)(A.center.position.y+0.5) , (int)(A.radius+0.5) ,GREEN ,true );
   DxLib::DrawCircle((int)(B.center.position.x +0.5), (int)(B.center.position.y+0.5) , (int)(B.radius+0.5) ,GREEN ,true );
#endif
   CollisionCircleCalc(A ,B ,( 1.0f - abs(pOut_t0) ) / 60.0f );
   return true; // 衝突報告

}
bool suken::CCollisionManager::CollisionRect(CRect &A , CRect &B)
{
	if(pow((A.GetRadius()+B.GetRadius()),2.0f) > GetSquareDistance(A.center.position,B.center.position)){
	suken::Vector2D v[4]={VSub(A.GetRightTop(),A.GetLeftTop()),VSub(A.GetRightBottom(),A.GetRightTop()),VSub(A.GetLeftBottom(),A.GetRightBottom()),VSub(A.GetLeftTop(),A.GetLeftBottom())};
	suken::Vector2D s[4]={A.GetLeftTop(),A.GetRightTop(),A.GetRightBottom(),A.GetLeftBottom()};
	suken::Vector2D vertex[4]={B.GetLeftTop(),B.GetRightTop(),B.GetRightBottom(),B.GetLeftBottom()};
	bool IsCollision[4]={true,true,true,true};
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if( VCrossLength(v[j],VSub(vertex[i],s[j])) < 0 ){
				IsCollision[i]=false;
			}
		}
		if(IsCollision[i]){
			A.OnCollisionFunc();
			B.OnCollisionFunc();
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
void suken::CCollisionManager::AddChild(CCircle *_circle , bool moveFlag)
{
	if(moveFlag){
		physicsCircle.push_back(_circle);
	}else{
		fixedCircle.push_back(_circle);
		_circle->mass = INF ;
	}
}
bool suken::CCollisionManager::RemoveChild(CCircle *_circle)
{

	std::vector<CCircle*>::iterator it_p = physicsCircle.begin();
	for(unsigned int i=0;i<physicsCircle.size();i++){
		if( physicsCircle[i] == _circle ){
			physicsCircle.erase(it_p);
			return true;
		}
		it_p++;
	}

	std::vector<CCircle*>::iterator it_f = fixedCircle.begin();
	for(unsigned int i=0;i<fixedCircle.size();i++){
		if( fixedCircle[i] == _circle ){
			fixedCircle.erase(it_f);
			return true;
		}
		it_f++;
	}

	return false;
}
void suken::CCollisionManager::AddChild(CRect *_rect , bool moveFlag)
{
	if(moveFlag){
		physicsRect.push_back(_rect);
	}else{
		fixedRect.push_back(_rect);
	}
}
bool suken::CCollisionManager::RemoveChild(CRect *_rect)
{

	std::vector<CRect*>::iterator it_p = physicsRect.begin();
	for(unsigned int i=0;i<physicsRect.size();i++){
		if( physicsRect[i] == _rect ){
			physicsRect.erase(it_p);
			return true;
		}
		it_p++;
	}

	std::vector<CRect*>::iterator it_f = fixedRect.begin();
	for(unsigned int i=0;i<fixedRect.size();i++){
		if( fixedRect[i] == _rect ){
			fixedRect.erase(it_f);
			return true;
		}
		it_f++;
	}

	return false;
}
