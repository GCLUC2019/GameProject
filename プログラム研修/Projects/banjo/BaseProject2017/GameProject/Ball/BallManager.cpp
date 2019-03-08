#include "BallManager.h"
#include "Ball.h"
#include "Bullet.h"
#include "../Global.h"
BallManager::BallManager():Task(eId_Ball,eUp_Ball,eRd_Ball)
{

}

BallManager::~BallManager()
{
}

void BallManager::Update(float delta_time)
{
	//�}�E�X���{�^�����������ςȂ��Ȃ�
	if (CInput::GetState(0, CInput::eHold, CInput::eMouseL)) {
		// 1/60�b���Z
		m_time += SPF;
		// 0.1�b�ň����
		if (m_time > 0.1f) {
			m_time -= 0.1f;
			//�}�E�X�̈ʒu���擾
			CVector2D pos = CInput::GetMousePoint();
			//�}�E�X�̈ʒu�ɋʂ𐶐�
			new Bullet(pos);
			//b->SetVector(CVector2D(Utility::Rand(-200, 200), -120));
		}
	}
}

void BallManager::Render()
{
}
