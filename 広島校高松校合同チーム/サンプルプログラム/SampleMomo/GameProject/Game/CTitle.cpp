#include "CTitle.h"
#include "CObjectImage.h"
CTitle::CTitle() : CObject(0, 0)
{
	ADD_RESOURCE("Back", CImage::LoadImage("Back.png"));
	m_back = COPY_RESOURCE("Back", CImage*);
	TaskManager::GetInstance()->AddTask(new CObjectImage(GET_RESOURCE("Back", CImage*), CVector3D(0, 0, 0), CVector2D(1280, 720), -1));
	
}

CTitle::~CTitle()
{
}

void CTitle::Update()
{
}

void CTitle::Draw()
{
	m_back.Draw();
}
