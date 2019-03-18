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

	/*
	ADD_RESOURCE("Stage_Background_0", CImage::LoadImage("stage_background_0.png"));

	ADD_RESOURCE("Shadow", CImage::LoadImage("shadow.png"));

	ADD_RESOURCE("HP_Bar", CImage::LoadImage("hp_bar.png"));
	ADD_RESOURCE("HP_Bar_Frame", CImage::LoadImage("hp_bar_frame.png"));
	*/

	ReadResorceFile("General/GENERAL_IMAGE.resorce");
	ReadResorceFile("PlayerAnim/PLAYER_ANIM_IMAGE.resorce");
	ReadResorceFile("EnemyAnim/ENEMY_ANIM_IMAGE.resorce");
	ReadResorceFile("Story/STORY_IMAGE.resorce");
	/*
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

	ADD_RESOURCE("Player_Down_Anim_0", CImage::LoadImage("momotaro_down_anim_0.png"));
	ADD_RESOURCE("Player_Down_Anim_1", CImage::LoadImage("momotaro_down_anim_1.png"));
	*/

	/*
	ADD_RESOURCE("Enemy_Idle_0", CImage::LoadImage("Enemy_idle1.png"));
	ADD_RESOURCE("Enemy_Move_0", CImage::LoadImage("Enemy_move1.png"));
	ADD_RESOURCE("Enemy_Attack_0", CImage::LoadImage("Enemy_attack1.png"));
	ADD_RESOURCE("Enemy_Damage_0", CImage::LoadImage("Enemy_damage1.png"));
	*/
	
	/*
	ADD_RESOURCE("SpearEnemy_Idle_1", CImage::LoadImage("Enemy_Spear_idle1.png"));
	ADD_RESOURCE("SpearEnemy_Idle_2", CImage::LoadImage("Enemy_Spear_idle2.png"));
	ADD_RESOURCE("SpearEnemy_Idle_3", CImage::LoadImage("Enemy_Spear_idle3.png"));
	ADD_RESOURCE("SpearEnemy_Idle_4", CImage::LoadImage("Enemy_Spear_idle4.png"));
	*/

	/*
	ADD_RESOURCE("AxeEnemy_Idle_1", CImage::LoadImage("Enemy_Axe_idle1.png"));
	ADD_RESOURCE("AxeEnemy_Idle_2", CImage::LoadImage("Enemy_Axe_idle2.png"));
	ADD_RESOURCE("AxeEnemy_Idle_3", CImage::LoadImage("Enemy_Axe_idle3.png"));
	ADD_RESOURCE("AxeEnemy_Idle_4", CImage::LoadImage("Enemy_Axe_idle4.png"));
	*/

	/*
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
	*/

	/*
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
	*/
	

	//ADD_RESOURCE("IconSpear", CImage::LoadImage("IconSpear.png"));
}

void CLoadResorce::ReadResorceFile(char * _file_path)
{
	FILE* fp;
	int ret = fopen_s(&fp, _file_path, "r");
	if (ret != 0) return;
	//printf("ì«Ç›çûÇÒÇæ\n");
	char file_data[10240] = "";
	char file_read[1024];
	while (fgets(file_read, 1024, fp) != NULL) {
		strcat_s(file_data, sizeof(file_data), file_read);
	};
	fclose(fp);


	printf("%s", file_data);

	char* str_ad = file_data;

	bool is_read_file_base_path = false;
	char file_base_path[1024];

	char* file_base_path_ad;
	if (file_base_path_ad = strstr(str_ad, "BASE_FILE_PATH: ")) {
		char* base_pass_last_ad = strstr(str_ad, "\n");
		int base_pass_len = base_pass_last_ad - file_base_path_ad;
		strncpy_s(file_base_path, file_base_path_ad + strlen("BASE_FILE_PATH: "), base_pass_len - strlen("BASE_FILE_PATH: "));
		is_read_file_base_path = true;
		printf("%s\n", file_base_path);
	}


	//IDÇ…âÊëúÇäÑÇËìñÇƒ
	while (true) {
		if (str_ad = strstr(str_ad, "LOAD_RESORCE_IMAGE:")) {
			//printf("str_ad %s\n", str_ad);
			int image_id;
			char image_name[1024];
			char image_file_path[1024];

			char* name_ad = strstr(str_ad, "IMAGE_NAME: ");
			char* name_end_ad = strstr(name_ad, "LOAD_IMAGE_FILE_PATH");
			int name_len = name_end_ad - name_ad;
			strncpy_s(image_name, name_ad + strlen("IMAGE_NAME: "), name_len - strlen("IMAGE_NAME: ") - 1);

			char* path_ad = strstr(str_ad, "LOAD_IMAGE_FILE_PATH: ");
			char* path_end_ad = strstr(str_ad, "\n");
			//printf("path_end_ad %s \n",path_end_ad);
			int path_len = path_end_ad - path_ad;
			strncpy_s(image_file_path, path_ad + strlen("LOAD_IMAGE_FILE_PATH: "), path_len - strlen("LOAD_IMAGE_FILE_PATH: "));
			
			
			
			if (is_read_file_base_path == true) {
				char load_image_file_path[1024];
				memset(load_image_file_path, 0, sizeof(load_image_file_path));
				strcat_s(load_image_file_path,file_base_path);
				strcat_s(load_image_file_path,image_file_path);
				printf("image_name Åy%sÅzimage_path Åy%sÅz\n", image_name, load_image_file_path);
				ADD_RESOURCE(image_name, CImage::LoadImage((char*)load_image_file_path));

			}
			else {
				printf("image_name Åy%sÅzimage_path Åy%sÅz\n", image_name, image_file_path);
				ADD_RESOURCE(image_name, CImage::LoadImage((char*)image_file_path));
			}
			str_ad += strlen("LOAD_RESORCE_IMAGE:");

		}
		else {
			break;
		}
	}
}
