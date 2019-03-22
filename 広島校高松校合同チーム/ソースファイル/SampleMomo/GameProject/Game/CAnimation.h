#pragma once


class CImage;

#define ANIMATION_INFO_MAX (200)
#define ANIMATION_IMAGE_MAX (500)
#define ANIMATION_DELAY_MAX (200)

struct AnimInfo {
	int image_id;
	int image_num = 0;
	double delay[ANIMATION_DELAY_MAX];
};


class CAnimation {
private:
	//アニメーション関連(アニメーションクラスに分離したほうがよいかも)
	AnimInfo m_anim_info[ANIMATION_INFO_MAX];
	int m_play_anim_id = 0;
	int m_play_anim_image = 0;
	int m_will_play_anim_id = 0;
	double m_play_anim_count = 0;
	CImage* m_anim_image_p[ANIMATION_IMAGE_MAX];
public:

	void SetWillPlayAnim(int _anim_id) { m_will_play_anim_id = _anim_id; }
	int GetWillPlayAnim() { return m_will_play_anim_id; };
	void SetAnim(int _anim_id);
	void CheckWillPlayAnim();
	void PlayAnim();//アニメーションを進める
	CImage* GetPlayAnimImage() { return m_anim_image_p[m_play_anim_image]; };//アニメーションの画像を取得
	void SetAnimImage(int _anim_image_id, CImage* _image_p) { m_anim_image_p[_anim_image_id] = _image_p; };
	void SetAnimInfo(int _anim_id, int _anim_begin_image_id, int _anim_image_num, int* _anim_delays_array) {
		m_anim_info[_anim_id].image_id = _anim_begin_image_id;
		m_anim_info[_anim_id].image_num = _anim_image_num;
		for (int i = 0; i < _anim_image_num; i++) {
			m_anim_info[_anim_id].delay[i] = _anim_delays_array[i];
		}
		
	};
	AnimInfo* GetAnimInfoArray() { return m_anim_info; }

	void ReadAnimDataFile(char * _file_path);
};

/*
2019 03 15 クラス定義 新開
*/