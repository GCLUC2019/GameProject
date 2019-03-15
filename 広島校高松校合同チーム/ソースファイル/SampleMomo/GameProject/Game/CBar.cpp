#include "CBar.h"
#include "CCharacterPlayer.h"
CBar::CBar(CImage* _img, float* _hp, float _max_hp, CVector2D _pos, CVector2D _size) :CObject(0, 0)
{
	//ADD_RESOURCE("HPbar", CImage::LoadImage("HPbar.png"));

	m_HPbar_img = _img;
	m_size = _size;
	m_bar_pos = _pos;
	hp = _max_hp;
	now_hp = _hp;
	m_bar_value_now = *now_hp;
}

CBar::~CBar()
{
}

void CBar::Update()
{
	const float value_change_speed = 0.01f;
	float value_change = (*now_hp - m_bar_value_now) * value_change_speed;
	const float change_limit = 1.0 * value_change_speed;
	if(abs(value_change) > change_limit) m_bar_value_now += value_change;
	if (m_bar_value_now <= 0.0f) m_bar_value_now = 0.0f;

	m_mult_hp = m_bar_value_now / hp;
	//now_bar_size = max_bar_size * m_mult_hp;
	/*m_mult_hp = (*now_hp / hp) * max_bar_size;
	if (now_bar_size != m_mult_hp) {
		--now_bar_size;
		if (now_bar_size <= 0) {
			now_bar_size = 0;
			m_mult_hp = 0;
		}
	}*/
}

void CBar::Draw()
{
	float now_bar_size = m_size.x*m_mult_hp;
	m_HPbar_img->SetSize(CVector2D(now_bar_size,m_size.y));
	
	m_HPbar_img->SetRect(0, now_bar_size, now_bar_size, now_bar_size);
	m_HPbar_img->SetPos(m_bar_pos);
	m_HPbar_img->Draw();
}
//�X�V����2019/03/13
//HP�o�[�̌���������ǉ�
//2019/03/14 �R���X�g���N�^�ň����₷������