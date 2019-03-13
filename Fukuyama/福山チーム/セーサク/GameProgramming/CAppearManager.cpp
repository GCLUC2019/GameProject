//小川


#include "CAppearManager.h"
#include "CAppear.h"
#include "CGlobal.h"
CAppearManager::CAppearManager() :Task(eId_Ball, eUp_Ball, eRd_Ball)
{

}

CAppearManager::~CAppearManager()
{
}

void CAppearManager::Update(float delta_time)
{
	/*
	//マウス左ボタンを押しっぱなしなら
	if (CInput::GetState(0, CInput::eHold, CInput::eMouseL)) {
		// 1/60秒加算
		m_time += SPF;
		// 0.1秒で一つ発生
		if (m_time > 0.1f) {
			m_time -= 0.1f;
			//マウスの位置を取得
			CVector2D pos = CInput::GetMousePoint();
			//マウスの位置に玉を生成
			Ball *b = new Ball();
			b->SetVecter(CVector2D(Utility::Rand(-200, 200), -120));
		}
	}
	*/
}

void CAppearManager::Render()
{
}
