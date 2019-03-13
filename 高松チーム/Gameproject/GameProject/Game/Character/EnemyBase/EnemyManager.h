#pragma once
#include "../../../Base/Task.h"
/*�@�S��
�@�@����
*/

class EnemyManager : public Task {
private:
	enum {
		eWave1_1,
		eWave1_2,
		eWave2_1,
		eWave2_2,
	};

private:
	int m_wave_flg;		//�E�F�[�u�t���O
	int m_appear_type;	//�`��^�C�v
	int m_cnt;
	
	//�e�E�F�[�u�t���O//
	bool m_wave1_1_flg; 
	bool m_wave1_2_flg;
	bool m_wave2_1_flg;
	bool m_wave2_2_flg;

protected:
	CVector2D m_pos;	//�G�ʒu
public:
	EnemyManager();
	void Update();
	void Draw();

};