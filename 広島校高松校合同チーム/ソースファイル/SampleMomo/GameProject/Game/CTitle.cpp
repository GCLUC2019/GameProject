#include "CTitle.h"
#include "CObjectImage.h"
#include "CStorySceneOpening.h"
#include "CBar.h"
#include "CGameScene.h"
#include "CFade.h"

CTitle::CTitle() : CObject(0, 0)
{

	m_background_image_p= GET_RESOURCE("Back", CImage*);

	m_blind_text_p = GET_RESOURCE("Start_By_Space", CImage*);
	
	m_blind_text_p->SetPos(140, 550);
	m_background_image_p->SetSize(1280, 720);
}

CTitle::~CTitle()
{
	
}

void CTitle::Update()
{
	//�V�t�g&�X�y�[�X�Ń^�C�g���X�L�b�v
	if (CInput::GetState(0, CInput::ePush, CInput::eButton1) && CInput::GetState(0, CInput::eHold, CInput::eButton3)) {
		SetIsDelete();
		CGameScene::GetInstance()->Setup();
	}
	//�X�y�[�X�L�[�Ń^�C�g����ʂ�j��
	else if (CInput::GetState(0,CInput::ePush, CInput::eButton1)) {
		SetIsDelete();
		//Delete();
		NextScene();
	}
	
	//2�b�ԃ^�C�g���̕�����\��������
	if (m_flash_txt == true) {
		if (m_count_txt >= 120) {
			m_count_txt -= 120;
			m_draw_txt = false;
			m_count_txt = 0;
			m_flash_txt = false;
		}
		m_count_txt += CFPS::GetDeltaTime() * GAME_BASE_FPS;
	}
	//1�b�ԃ^�C�g���̕���������
	if (m_flash_txt == false) {
		if (m_count_txt2 >= 60) {
			m_count_txt2 -= 60;
			m_draw_txt = true;
			m_count_txt2 = 0;
			m_flash_txt = true;
		}
		m_count_txt2 += CFPS::GetDeltaTime() * GAME_BASE_FPS;
	}
	
}

void CTitle::Draw()
{
	m_background_image_p->Draw();
	if (m_draw_txt == true) {
		m_blind_text_p->Draw();
	}
}

void CTitle::NextScene()
{
	CFade::GetInstance()->SetFadeOut(0);
	CFade::GetInstance()->SetFadeIn(25);
	TaskManager::GetInstance()->AddTask(new CStorySceneOpening());
}



//�X�V����2019/03/11 �^�C�g����ǉ�
//�X�g�[���[�V�[���̂ֈڍs��ǉ�
//2019/03/12�@�^�C�g���̓_�ŕ\����ǉ�