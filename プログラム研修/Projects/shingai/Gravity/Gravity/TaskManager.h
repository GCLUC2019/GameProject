#pragma once
#include "Task.h"

enum {
	eTaskManagerIdGeneral,
	eTaskManagerMax,
};
class TaskManager {
private:
	int m_task_num = 0;
	Task * m_head_task = nullptr;
public:
	Task* GetHead() { return m_head_task; };
	void AddTask(Task* _task);
	Task* FindTask(int _task_id);
	void DeleteTask(Task* _task);

	void UpdateAll();
	void UpdateAllSort();
	void DrawAll();
	void DrawAllSort();
	

	static void CheckInit();
	static TaskManager* GetTaskManagerPointer(int _task_manager_id);
};

/*
2019/03/07 TaskManagerクラス定義。基本機能実装。 by shingai
*/
