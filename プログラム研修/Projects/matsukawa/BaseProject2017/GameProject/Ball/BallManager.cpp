#include "BallManager.h"
#include "Ball.h"
#include "../Global.h"
BallManager::BallManager():Task(eId_Ball,eUp_Ball,eRd_Ball)
{

}

BallManager::~BallManager()
{
}

void BallManager::Update(float delta_time)
{
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
			Ball *b=new Ball(pos);
			b->SetVector(CVector2D(Utility::Rand(-10, 10), -20));
		}
	}
}

void BallManager::Render()
{
}
