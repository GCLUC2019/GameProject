#pragma once
#include "stdio.h"

class Task {
protected:
	int cnt;
	Task* mp_task;    //現在のポインタ
	Task* mp_prev;    //前のポインタ
	Task* mp_next;    //次のポインタ
	int  m_id;      //タスクのID
	int  m_priority;  //優先度
	bool mp_killFlag; //生存フラグ
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