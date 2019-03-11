//#include"CBoss.h"
//#include "CEnemyTank.h"
//#include "CPlayerTank.h"
//#include "CBullet.h"
//#include "CExplosion.h"
//#include "CSceneGame.h"
//#include "CMain.h"
//
//#define FIREINTERVER_E 60
//
//extern CPlayerTank*Tank;
//extern CBoss*Boss;
//
//
//void CBoss::Init() {
//	SetVertex(-40.0f, 40.0f, -24.0f, 24.0f);
//}
//
//void CBoss::Update() {
//	Forward();
//	CTank::Update();
//	mHpBar.Update();
//	
//}
//
//void CBoss::OnCollision(CCollider*p) {
//	
//}
//
//void CBoss::OnCollision(CBoxCollider*p) {
//	
//}
//
//void CBoss::Render() {
//	CTank::Render();
//	mHpBar.Render();
//}