#include "CBar.h"

CBar::CBar(CImage * _img, float * _value, float _max_value, CVector3D _pos, CVector2D _size, bool _is_scrool)
{
	m_bar_img = _img;
	m_bar_img->SetFilter(GL_NEAREST);
	m_size = _size;
	m_pos = _pos;
	m_max_value = _max_value;
	m_now_value = _value;
	m_bar_value_now = *m_now_value;
	m_is_scroll = _is_scrool;
}

CBar::CBar(CImage * _img, float * _value, float _max_value, CVector2D _pos, CVector2D _size, bool _is_scrool)
	:CBar(_img,_value, _max_value, CVector3D(_pos.x, _pos.y,0.0),_size, _is_scrool)
{
}

CBar::~CBar()
{
}

void CBar::Update()
{
	const float value_change_speed = 0.01f;
	float value_change = (*m_now_value - m_bar_value_now) * value_change_speed;
	const float change_limit = 0.01 * value_change_speed;
	if(abs(value_change) > change_limit) m_bar_value_now += value_change;
	if (m_bar_value_now <= 0.0f) m_bar_value_now = 0.0f;
	m_mult_value = m_bar_value_now / m_max_value;
}

void CBar::Draw()
{
	float now_bar_size = m_size.x * m_mult_value;
	m_bar_img->SetSize(CVector2D(now_bar_size,m_size.y));
	m_bar_img->SetRect(0, now_bar_size, now_bar_size, now_bar_size);

	m_bar_img->SetColor(2.55f,2.55f,2.55f,2.55f);

	if(m_is_scroll == false) m_bar_img->SetPos(CVector2D(m_pos.x,m_pos.y + m_pos.z));
	else if(m_is_scroll == true) m_bar_img->SetPos(CVector2D(m_pos.x, m_pos.y + m_pos.z) - GetScroll());

	m_bar_img->Draw();
}
//更新履歴2019/03/13
//HPバーの減少処理を追加
//2019/03/14 コンストラクタで扱いやすくした 三野
//2019/03/19 