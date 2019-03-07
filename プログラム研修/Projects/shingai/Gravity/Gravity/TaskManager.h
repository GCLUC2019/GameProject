#pragma once

class Task;

//挿入ができれば描画順番とかをバブルソートとか負荷の高い事をしなくてよい


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
	void DrawAll();
	void Sort();

	static TaskManager* GetInstance();
	static void ClearInstance();
};

/*
2019/03/07 TaskManagerクラス定義。基本機能実装。 by shingai
*/
