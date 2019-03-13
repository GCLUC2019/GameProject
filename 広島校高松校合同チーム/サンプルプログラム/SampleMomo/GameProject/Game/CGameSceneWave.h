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


//�|�C���^�ŊǗ���
class CGameSceneWave : public CObject {
private:
	int m_pop_enemy_num = 0;
	int m_count_dead = 0;
	CCharacter* m_pop_enemy_p[GAME_WAVE_ENEMY_MAX];
public:
	CGameSceneWave(int _wave_id);
	~CGameSceneWave();
	void CheckDeadCount();

	void Init();

	//�|�b�v�������G���|���ꂽ�ꍇ�̏���
	void DeadEnemy(int _character_id);
};