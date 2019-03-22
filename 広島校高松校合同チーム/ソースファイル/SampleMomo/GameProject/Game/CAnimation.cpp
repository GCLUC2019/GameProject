#include "CAnimation.h"
#include "CFPS.h"
#include "../Global.h"

void CAnimation::SetAnim(int _anim_id)
{
	if (m_play_anim_id == _anim_id) return;
	m_play_anim_id = _anim_id;
	m_play_anim_image = m_anim_info[_anim_id].image_id;
	m_play_anim_count = m_anim_info[_anim_id].delay[0];
}

//引数無しの場合、再生予定のアニメーションを再生します。

void CAnimation::CheckWillPlayAnim()
{
	if (m_play_anim_id == m_will_play_anim_id) return;
	m_play_anim_id = m_will_play_anim_id;
	m_play_anim_image = m_anim_info[m_will_play_anim_id].image_id;
	m_play_anim_count = m_anim_info[m_will_play_anim_id].delay[0];
}

void CAnimation::PlayAnim()
{
	//printf("play\n");
	if (m_play_anim_count <= 0.0) {
		//printf("次！\n");
		m_play_anim_image++;
		if (m_play_anim_image >= m_anim_info[m_play_anim_id].image_id + m_anim_info[m_play_anim_id].image_num) {
			m_play_anim_image = m_anim_info[m_play_anim_id].image_id;
		}

		m_play_anim_count = m_anim_info[m_play_anim_id].delay[m_play_anim_image - m_anim_info[m_play_anim_id].image_id];
	}
	else {
		m_play_anim_count -= CFPS::GetDeltaTime() * GAME_BASE_FPS;
	}
}

void CAnimation::ReadAnimDataFile(char * _file_path)
{
	FILE* fp;
	int ret = fopen_s(&fp,_file_path, "r");
	if (ret != 0) return;
	//printf("読み込んだ\n");
	char file_data[20240] = "";
	char file_read[1024];
	while (fgets(file_read, 1024, fp) != NULL) {
		strcat_s(file_data, sizeof(file_data), file_read);
	};
	fclose(fp);


	//printf("%s", file_data);




	char* str_ad = file_data;

	//IDに画像を割り当て
	while (true) {
		if (str_ad = strstr(str_ad, "SET_ANIM_IMAGE:")) {
			//printf("str_ad %s\n", str_ad);
			int image_id;
			char image_name[1024];
			
			char* name_ad = strstr(str_ad, "IMAGE_NAME: ");
			char* last_ad = strstr(str_ad, "\n");
			int name_len = last_ad - name_ad;

			strncpy_s(image_name, name_ad + strlen("IMAGE_NAME: "), name_len - strlen("IMAGE_NAME: "));
			sscanf_s(str_ad, "SET_ANIM_IMAGE: IMAGE_ID: %d", &image_id);
			//printf("image_name %s\n", image_name);
			SetAnimImage(image_id, GET_RESOURCE(image_name, CImage*));
			str_ad += strlen("SET_ANIM_IMAGE:");
			
		}
		else {
			break;
		}
	}

	//アニメーション設定
	str_ad = file_data;
	while (true) {
		if (str_ad = strstr(str_ad, "SET_ANIM_INFO:")) {
			int anim_id;
			int anim_begin_image_id;
			int anim_image_num;
			int anim_deley[ANIMATION_DELAY_MAX];
			sscanf_s(str_ad, "SET_ANIM_INFO: ANIM_ID: %d ANIM_BEGIN_IMAGE_ID: %d ANIM_IMAGE_NUM: %d", &anim_id, &anim_begin_image_id,&anim_image_num);
			
			printf("AnimId %d\n", anim_id);
			//ディレイの取得
			for (int i = 0; i < anim_image_num; i++) {
				str_ad = strstr(str_ad, "ANIM_DELAY:");
				sscanf_s(str_ad, "ANIM_DELAY: %d", &anim_deley[i]);
				str_ad += strlen("ANIM_DELAY");
			}

			SetAnimInfo(anim_id, anim_begin_image_id, anim_image_num, anim_deley);
		}
		else {
			break;
		}
	}
}
