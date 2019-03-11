#include "CTitle.h"
#include "CObjectImage.h"
#include "CStoryScene.h"
CTitle::CTitle() : CObject(0, 0)
{
	ADD_RESOURCE("Back", CImage::LoadImage("Back.png"));
	m_background_image_p= GET_RESOURCE("Back", CImage*);
	ADD_RESOURCE("Back_txt", CImage::LoadImage("Back_txt.png"));
	m_backtxt_p = GET_RESOURCE("Back_txt", CImage*);
	m_backtxt_p->SetPos(1050, -50);
}

CTitle::~CTitle()
{
	
}

void CTitle::Update()
{
	//�X�y�[�X�L�[�Ń^�C�g����ʂ�j��
	if (CInput::GetState(0,CInput::ePush, CInput::eButton1)) {
		SetIsDelete();
		//Delete();
		next_scene();
	}
}

void CTitle::Draw()
{
	m_background_image_p->Draw();
	m_backtxt_p->Draw();
	//printf("Draw���܂���");
}

void CTitle::next_scene()
{
	CStoryScene*StoryScene_p = new CStoryScene();
	TaskManager::GetInstance()->AddTask(StoryScene_p);
}

//�X�V����2019/03/11 �^�C�g����ǉ�
//�X�g�[���[�V�[���̂ֈڍs��ǉ�