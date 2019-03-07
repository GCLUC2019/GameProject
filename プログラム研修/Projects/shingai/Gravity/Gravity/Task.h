#pragma once
#include "TaskManager.h"


//�}������

class Task {
private:
	int m_task_id;

	//���̂܂�Z�\�[�g�݂����Ȃ��Ƃ��ł���悤�ɂ���B
	//�������D�悵�ĕ`�悳��� == �ォ��`�悳���(�D��x�������� ��ʂ̑O�ɏo�₷���Ȃ�)
	int m_draw_priority = 0;

	Task * m_before_task = nullptr;
	Task * m_next_task = nullptr;

public:
	Task(int _task_id,int _draw_priority = 0);
	virtual ~Task();

	virtual void Update();
	virtual void Draw();
	
	void SetDrawPriority(int _priority) { m_draw_priority = _priority; };
	int GetDrawPriority() { return m_draw_priority; };

	void SetTaskId(int _task_id) { m_task_id = _task_id; };
	int GetTaskId() { return m_task_id; };

	void SetBeforeTask(Task* _before) { m_before_task = _before; };
	Task* GetBeforeTask() { return m_before_task; };

	void SetNextTask(Task* _next) { m_next_task = _next; };
	Task* GetNextTask() { return m_next_task; };

	void Delete();
};

/*
2019/03/07 Task�N���X��`�B��{�@�\�����B by shingai
*/
