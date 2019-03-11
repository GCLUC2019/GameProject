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

	//該当のIDのTaskを全て返す
	Task** FindTaskArray(int _task_id);

	//即座に該当タスクを削除する
	void DeleteTask(Task* _task);
	void DeleteAllTask();

	//削除フラグがtrueになっているタスクを全て削除する
	void CheckDeleteAll();

	void UpdateAll();
	void CollisionAll();
	void DrawAll();
	void Sort();
	void QuickSort(Task** _task_array,int* _task_dp_array,int _task_num);

	static TaskManager* GetInstance();
	static void ClearInstance();
};

/*
2019/03/07 TaskManagerクラス定義。基本機能実装。by shingai
2019/03/08 バグ修正やソート部分をクイックソートに変更。 by shingai
*/
