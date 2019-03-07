#pragma once

class TaskManager;

enum {
	eTaskIdNone = 0,
	eTaskIdPlayer,
};

class Task {
private:
	int m_task_id;
	int m_task_manager_id;


	//そのままZソートみたいなこともできるようにする。
	//高い程優先して描画される == 後から描画される(優先度が高い程 画面の前に出やすくなる)
	int m_draw_priority = 0;

	Task * m_before_task = nullptr;
	Task * m_next_task = nullptr;
public:
	Task(int _task_manager_id,int _task_id,int _draw_priority = 0);
	~Task();

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


	/*
	static void UpdateAll();
	static void DrawAll();
	static Task* GetHead() { return s_head_task; };
	static void AddTask(Task* _task);
	static Task* FindTask(int _task_id);
	static void DeleteTask(Task* _task);
	*/
};

/*
2019/03/07 Taskクラス定義。基本機能実装。 by shingai
*/
