#pragma once
#include "TaskManager.h"


//�}������

class Task {
private:
	int m_task_id;

	//���̂܂�Z�\�[�g�݂����Ȃ��Ƃ��ł���悤�ɂ���B
	//�������D�悵�ĕ`�悳��� == �ォ��`�悳���(�D��x�������� ��ʂ̑O�ɏo�₷���Ȃ�)
	int m_draw_priority = 0;

	//�폜�t���O(�ꊇ�폜�̕����y���P�[�X�Ȃǂɗp����)
	bool m_is_delete = false;

	Task * m_before_task = nullptr;
	Task * m_next_task = nullptr;

public:
	//@brief �^�X�N�N���X�R���X�g���N�^
	//@param [in] _task_id �^�X�N���ʗp��ID
	//@param [in] _draw_priority �`��D��x(�l�̑傫�����̂�D�悵�Ď�O�ɕ`�悷��)
	Task(int _task_id,int _draw_priority = 0);


	virtual ~Task();

	virtual void Update();
	virtual void Draw();
	virtual void CollisionCheck(Task* _collision_task);
	
	void SetDrawPriority(int _priority) { m_draw_priority = _priority; };
	int GetDrawPriority() { return m_draw_priority; };

	void SetTaskId(int _task_id) { m_task_id = _task_id; };
	int GetTaskId() { return m_task_id; };

	void SetBeforeTask(Task* _before) { m_before_task = _before; };
	Task* GetBeforeTask() { return m_before_task; };

	void SetNextTask(Task* _next) { m_next_task = _next; };
	Task* GetNextTask() { return m_next_task; };

	void Delete();//�����Ɏ������폜����B

	void SetIsDelete() {m_is_delete = true; };//�폜�t���O���I���ɂ���
	bool GetIsDelete() { return m_is_delete; };
};

/*
2019/03/07 Task�N���X��`�B��{�@�\�����B by shingai
2019/03/08 TaskManager�N���X�ւ̏C���ɍ��킹�����K�͂ȏC���B by shingai
*/
