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

	ADD_RESOURCE("HPbar", CImage::LoadImage("HPbar.png"));

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

	ADD_RESOURCE("Player_Evasion_Anim_0", CImage::LoadImage("momotaro_evasion_anim_0.png"));
	ADD_RESOURCE("Player_Evasion_Anim_1", CImage::LoadImage("momotaro_evasion_anim_1.png"));
	ADD_RESOURCE("Player_Evasion_Anim_2", CImage::LoadImage("momotaro_evasion_anim_2.png"));
	ADD_RESOURCE("Player_Evasion_Anim_3", CImage::LoadImage("momotaro_evasion_anim_3.png"));
	ADD_RESOURCE("Player_Evasion_Anim_4", CImage::LoadImage("momotaro_evasion_anim_4.png"));
	ADD_RESOURCE("Player_Evasion_Anim_5", CImage::LoadImage("momotaro_evasion_anim_5.png"));


	ADD_RESOURCE("Player_Attack_Anim_0", CImage::LoadImage("momotaro_attack_anim_0.png"));
	ADD_RESOURCE("Player_Attack_Anim_1", CImage::LoadImage("momotaro_attack_anim_1.png"));
	ADD_RESOURCE("Player_Attack_Anim_2", CImage::LoadImage("momotaro_attack_anim_2.png"));

	ADD_RESOURCE("Enemy_Idle_0", CImage::LoadImage("Enemy_idle1.png"));
	ADD_RESOURCE("Enemy_Move_0", CImage::LoadImage("Enemy_move1.png"));
	ADD_RESOURCE("Enemy_Attack_0", CImage::LoadImage("Enemy_attack1.png"));
	ADD_RESOURCE("Enemy_Damage_0", CImage::LoadImage("Enemy_damage1.png"));


	ADD_RESOURCE("SpearEnemy_Idle_1", CImage::LoadImage("Enemy_Spear_idle1.png"));
	ADD_RESOURCE("SpearEnemy_Idle_2", CImage::LoadImage("Enemy_Spear_idle2.png"));
	ADD_RESOURCE("SpearEnemy_Idle_3", CImage::LoadImage("Enemy_Spear_idle3.png"));
	ADD_RESOURCE("SpearEnemy_Idle_4", CImage::LoadImage("Enemy_Spear_idle4.png"));
	ADD_RESOURCE("AxeEnemy_Idle_1", CImage::LoadImage("Enemy_Axe_idle1.png"));
	ADD_RESOURCE("AxeEnemy_Idle_2", CImage::LoadImage("Enemy_Axe_idle2.png"));
	ADD_RESOURCE("AxeEnemy_Idle_3", CImage::LoadImage("Enemy_Axe_idle3.png"));
	ADD_RESOURCE("AxeEnemy_Idle_4", CImage::LoadImage("Enemy_Axe_idle4.png"));
	ADD_RESOURCE("GunEnemy_Idle_1", CImage::LoadImage("Enemy_Gun_idle1.png"));
	ADD_RESOURCE("GunEnemy_Idle_2", CImage::LoadImage("Enemy_Gun_idle2.png"));
	ADD_RESOURCE("GunEnemy_Idle_3", CImage::LoadImage("Enemy_Gun_idle3.png"));
	ADD_RESOURCE("GunEnemy_Idle_4", CImage::LoadImage("Enemy_Gun_idle4.png"));
	ADD_RESOURCE("SpearEnemy_Move_1", CImage::LoadImage("Enemy_Spear_move1.png"));
	ADD_RESOURCE("SpearEnemy_Move_2", CImage::LoadImage("Enemy_Spear_move2.png"));
	ADD_RESOURCE("SpearEnemy_Move_3", CImage::LoadImage("Enemy_Spear_move3.png"));
	ADD_RESOURCE("SpearEnemy_Move_4", CImage::LoadImage("Enemy_Spear_move4.png"));
	ADD_RESOURCE("SpearEnemy_Move_5", CImage::LoadImage("Enemy_Spear_move5.png"));
	ADD_RESOURCE("SpearEnemy_Move_6", CImage::LoadImage("Enemy_Spear_move6.png"));
	ADD_RESOURCE("SpearEnemy_Move_7", CImage::LoadImage("Enemy_Spear_move7.png"));
	ADD_RESOURCE("SpearEnemy_Move_8", CImage::LoadImage("Enemy_Spear_move8.png"));
	ADD_RESOURCE("AxeEnemy_Move_1", CImage::LoadImage("Enemy_Axe_move1.png"));
	ADD_RESOURCE("AxeEnemy_Move_2", CImage::LoadImage("Enemy_Axe_move2.png"));
	ADD_RESOURCE("AxeEnemy_Move_3", CImage::LoadImage("Enemy_Axe_move3.png"));
	ADD_RESOURCE("AxeEnemy_Move_4", CImage::LoadImage("Enemy_Axe_move4.png"));
	ADD_RESOURCE("AxeEnemy_Move_5", CImage::LoadImage("Enemy_Axe_move5.png"));
	ADD_RESOURCE("AxeEnemy_Move_6", CImage::LoadImage("Enemy_Axe_move6.png"));
	ADD_RESOURCE("AxeEnemy_Move_7", CImage::LoadImage("Enemy_Axe_move7.png"));
	ADD_RESOURCE("AxeEnemy_Move_8", CImage::LoadImage("Enemy_Axe_move8.png"));
	ADD_RESOURCE("GunEnemy_Move_1", CImage::LoadImage("Enemy_Gun_move1.png"));
	ADD_RESOURCE("GunEnemy_Move_2", CImage::LoadImage("Enemy_Gun_move2.png"));
	ADD_RESOURCE("GunEnemy_Move_3", CImage::LoadImage("Enemy_Gun_move3.png"));
	ADD_RESOURCE("GunEnemy_Move_4", CImage::LoadImage("Enemy_Gun_move4.png"));
	ADD_RESOURCE("GunEnemy_Move_5", CImage::LoadImage("Enemy_Gun_move5.png"));
	ADD_RESOURCE("GunEnemy_Move_6", CImage::LoadImage("Enemy_Gun_move6.png"));
	ADD_RESOURCE("GunEnemy_Move_7", CImage::LoadImage("Enemy_Gun_move7.png"));
	ADD_RESOURCE("GunEnemy_Move_8", CImage::LoadImage("Enemy_Gun_move8.png"));
	ADD_RESOURCE("Enemy_Move_2", CImage::LoadImage("Enemy_move2.png"));
	ADD_RESOURCE("Enemy_Move_3", CImage::LoadImage("Enemy_move3.png"));
	ADD_RESOURCE("Enemy_Move_4", CImage::LoadImage("Enemy_move4.png"));
	ADD_RESOURCE("Enemy_Move_5", CImage::LoadImage("Enemy_move5.png"));
	ADD_RESOURCE("Enemy_Move_6", CImage::LoadImage("Enemy_move6.png"));
	ADD_RESOURCE("Enemy_Move_7", CImage::LoadImage("Enemy_move7.png"));
	ADD_RESOURCE("Enemy_Move_8", CImage::LoadImage("Enemy_move8.png"));
	ADD_RESOURCE("Enemy_Attack_2", CImage::LoadImage("Enemy_attack2.png"));

	ADD_RESOURCE("Player_Down_Anim_0", CImage::LoadImage("momotaro_down_anim_0.png"));
	ADD_RESOURCE("Player_Down_Anim_1", CImage::LoadImage("momotaro_down_anim_1.png"));

	ADD_RESOURCE("IconSpear", CImage::LoadImage("IconSpear.png"));
}
