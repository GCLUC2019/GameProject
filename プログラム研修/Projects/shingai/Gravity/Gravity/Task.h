#pragma once
#include "TaskManager.h"


//挿入処理

class Task {
private:
	int m_task_id;

	//そのままZソートみたいなこともできるようにする。
	//高い程優先して描画される == 後から描画される(優先度が高い程 画面の前に出やすくなる)
	int m_draw_priority = 0;

	//削除フラグ(一括削除の方が軽いケースなどに用いる)
	bool m_is_delete = false;

	Task * m_before_task = nullptr;
	Task * m_next_task = nullptr;

public:
	//@brief タスククラスコンストラクタ
	//@param [in] _task_id タスク識別用のID
	//@param [in] _draw_priority 描画優先度(値の大きいものを優先して手前に描画する)
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

	void Delete();//即座に自分を削除する。

	void SetIsDelete() {m_is_delete = true; };//削除フラグをオンにする
	bool GetIsDelete() { return m_is_delete; };
};

/*
2019/03/07 Taskクラス定義。基本機能実装。 by shingai
2019/03/08 TaskManagerクラスへの修正に合わせた小規模な修正。 by shingai
*/
