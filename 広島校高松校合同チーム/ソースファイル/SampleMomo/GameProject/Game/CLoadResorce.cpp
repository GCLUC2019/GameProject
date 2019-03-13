#include "CLoadResorce.h"
#include "../Global.h"

CLoadResorce * s_instance_p = nullptr;

CLoadResorce::CLoadResorce()
{
}

CLoadResorce * CLoadResorce::GetInstance()
{
	if (s_instance_p == nullptr) s_instance_p = new CLoadResorce();
	return s_instance_p;
}

void CLoadResorce::LoadResorce()
{
	if (m_is_loaded == true) return;
	m_is_loaded = true;


	ADD_RESOURCE("Stage_Background_0", CImage::LoadImage("stage_background_0.png"));

	ADD_RESOURCE("Shadow", CImage::LoadImage("shadow.png"));

	ADD_RESOURCE("Player_Idle_Anim_0", CImage::LoadImage("momotaro_idle_anim_0.png"));
	ADD_RESOURCE("Player_Idle_Anim_1", CImage::LoadImage("momotaro_idle_anim_1.png"));
	ADD_RESOURCE("Player_Idle_Anim_2", CImage::LoadImage("momotaro_idle_anim_2.png"));
	ADD_RESOURCE("Player_Idle_Anim_3", CImage::LoadImage("momotaro_idle_anim_3.png"));

	ADD_RESOURCE("Player_Move_Anim_0", CImage::LoadImage("momotaro_move_anim_0.png"));
	ADD_RESOURCE("Player_Move_Anim_1", CImage::LoadImage("momotaro_move_anim_1.png"));
	ADD_RESOURCE("Player_Move_Anim_2", CImage::LoadImage("momotaro_move_anim_2.png"));
	ADD_RESOURCE("Player_Move_Anim_3", CImage::LoadImage("momotaro_move_anim_3.png"));
	ADD_RESOURCE("Player_Move_Anim_4", CImage::LoadImage("momotaro_move_anim_4.png"));
	ADD_RESOURCE("Player_Move_Anim_5", CImage::LoadImage("momotaro_move_anim_5.png"));
	ADD_RESOURCE("Player_Move_Anim_6", CImage::LoadImage("momotaro_move_anim_6.png"));
	ADD_RESOURCE("Player_Move_Anim_7", CImage::LoadImage("momotaro_move_anim_7.png"));


	ADD_RESOURCE("Player_Jump_Anim_0", CImage::LoadImage("momotaro_jump_anim_0.png"));
	ADD_RESOURCE("Player_Jump_Anim_1", CImage::LoadImage("momotaro_jump_anim_1.png"));
	ADD_RESOURCE("Player_Jump_Anim_2", CImage::LoadImage("momotaro_jump_anim_2.png"));
	ADD_RESOURCE("Player_Jump_Anim_3", CImage::LoadImage("momotaro_jump_anim_3.png"));
	ADD_RESOURCE("Player_Jump_Anim_4", CImage::LoadImage("momotaro_jump_anim_4.png"));


	ADD_RESOURCE("Player_Run_Anim_0", CImage::LoadImage("momotaro_run_anim_0.png"));
	ADD_RESOURCE("Player_Run_Anim_1", CImage::LoadImage("momotaro_run_anim_1.png"));
	ADD_RESOURCE("Player_Run_Anim_2", CImage::LoadImage("momotaro_run_anim_2.png"));
	ADD_RESOURCE("Player_Run_Anim_3", CImage::LoadImage("momotaro_run_anim_3.png"));
	ADD_RESOURCE("Player_Run_Anim_4", CImage::LoadImage("momotaro_run_anim_4.png"));
	ADD_RESOURCE("Player_Run_Anim_5", CImage::LoadImage("momotaro_run_anim_5.png"));

	ADD_RESOURCE("Player_Damage_Anim_0", CImage::LoadImage("momotaro_damage_anim_0.png"));

	ADD_RESOURCE("Enemy_Idle_0", CImage::LoadImage("Enemy_idle1.png"));
	ADD_RESOURCE("Enemy_Move_0", CImage::LoadImage("Enemy_move1.png"));
	ADD_RESOURCE("Enemy_Attack_0", CImage::LoadImage("Enemy_attack1.png"));
	ADD_RESOURCE("Enemy_Damage_0", CImage::LoadImage("Enemy_damage1.png"));
}
