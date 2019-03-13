#include "CBar.h"

CBar::CBar():CObject(0, 0)
{
	ADD_RESOURCE("HPbar", CImage::LoadImage("HPbar.png"));
	m_HPbar_img = GET_RESOURCE("HPbar", CImage*);
	m_HPbar_img->SetPos(10, 25);
	max_bar_size = 400;
	now_bar_size = 400;
	m_decrease_hp = 400;
	hp = 100;
	now_hp = 100;
	damage = 20;
}

CBar::~CBar()
{
}

void CBar::Update()
{
	if (CInput::GetState(0, CInput::ePush, CInput::eButton2)) {
		now_hp -= damage;
		m_decrease_hp = (now_hp / hp) * max_bar_size;
	}
	if (now_bar_size != m_decrease_hp) {
		--now_bar_size;
		if (now_bar_size <= 0) {
			now_bar_size = 0;
			m_decrease_hp = 0;
		}
	}
}

void CBar::Draw()
{
	m_HPbar_img->Draw();
	m_HPbar_img->SetSize(now_bar_size, 50);
	m_HPbar_img->SetRect(0, now_bar_size, now_bar_size, now_bar_size);
}
//更新履歴2019/03/13
//HPバーの減少処理を追加