//����


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
			Ball *b = new Ball();
			b->SetVecter(CVector2D(Utility::Rand(-200, 200), -120));
		}
	}
	*/
}

void CAppearManager::Render()
{
}
