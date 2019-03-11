#pragma once
#include "stdio.h"

class Task {
protected:
	int cnt;
	Task* mp_task;    //���݂̃|�C���^
	Task* mp_prev;    //�O�̃|�C���^
	Task* mp_next;    //���̃|�C���^
	int  m_id;      //�^�X�N��ID
	int  m_priority;  //�D��x
	bool mp_killFlag; //�����t���O
public:
	Task();
	Task(int id, int priority);
	virtual ~Task();
	virtual void Update();
	virtual void Draw();
	void ChangeTaskPrio(int priority);

	void SetKill() {
		mp_killFlag = true;
	}

	void SetPriority(int& priority) {
		m_priority = priority;
	}

	int GetPriorty() const {
		return m_priority;
	}

	int GetId()const {
		return m_id;
	}

	friend class TaskManagement;
	friend class TaskManager;
};