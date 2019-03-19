#include "CFade.h"

CFade* s_instance_p = nullptr;

CFade::CFade() :CObject(0, DP_MAX)
{
	m_black_screen_p = new CImage();
}

void CFade::Update()
{
	if (m_fade_out_count > 0.0) {
		m_fade_out_count -= CFPS::GetDeltaTime() * GAME_BASE_FPS;
		m_alpha += m_fade_out_value_per_count * CFPS::GetDeltaTime() * GAME_BASE_FPS;
		if (m_fade_out_count <= 0.0){
			m_fade_out_count = 0.0;
			m_alpha = 2.55;
		}
	}
	else if (m_fade_in_count > 0.0) {
		m_fade_in_count -= CFPS::GetDeltaTime() * GAME_BASE_FPS;
		m_alpha -= m_fade_in_value_per_count * CFPS::GetDeltaTime() * GAME_BASE_FPS;
		if (m_fade_in_count <= 0.0) {
			m_fade_in_count = 0.0;
			m_alpha = 0.0;
		}
	}
}

void CFade::Draw()
{
	//printf("alpha %lf\n", m_alpha);
	m_black_screen_p->SetSize(1280, 720);
	m_black_screen_p->SetColor(0, 0, 0, m_alpha);
	m_black_screen_p->SetPos(0, 0);
	m_black_screen_p->Draw();
}

CFade * CFade::GetInstance()
{
	if (s_instance_p == nullptr) {
		TaskManager::GetInstance()->AddTask(s_instance_p = new CFade());
	}
	return s_instance_p;
}
