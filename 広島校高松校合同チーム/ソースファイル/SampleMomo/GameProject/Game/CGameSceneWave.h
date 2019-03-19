#pragma once
#include "CObject.h"
#include "../Global.h"

class CCharacter;
class CCharacterEnemy;

#define GAME_WAVE_ENEMY_MAX (3000)

/*
�G�̃O���[�v���o�����ē|�����܂ł̃Q�[���V�[���ł̃E�F�[�u���Ǘ�����B
�M�~�b�N��1�Ƃ��Ď�舵���B
�E�F�[�u���������ꂽ��Q�[���V�[���Ɋ������ꂽ���Ƃ�񍐂���B
�G�̊Ǘ��ƃE�F�[�u�I����`���邾���̋@�\
*/

enum {
	eWave1,
	eWave2,
	eWave3,
	eWave4,
	eWave5,
	eWave6,
	eWave7,
	eWave8,
	eWave9,
	eWave10,
	eWave11,
	eWave12,
	eWave13,
	eWave14,
	eWave15,
	eWave16,
	eWave17,
	eWave18,
};


//�|�C���^�ŊǗ���
class CGameSceneWave : public CObject {
private:
	int m_wave_id;
	int m_next_wave_id;
	int m_pop_enemy_num = 0;
	int m_count_dead = 0;
	CCharacter* m_pop_enemy_p[GAME_WAVE_ENEMY_MAX];
public:
	CGameSceneWave(int _wave_id);
	~CGameSceneWave();
	void CheckDeadCount();

	void Init();
	void LoadWave(int _wave_id);

	//�|�b�v�������G���|���ꂽ�ꍇ�̏���
	void DeadEnemy(int _character_id);
};