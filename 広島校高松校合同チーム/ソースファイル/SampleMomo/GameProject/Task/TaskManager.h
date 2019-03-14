#pragma once

class Task;

//挿入ができれば描画順番とかをバブルソートとか負荷の高い事をしなくてよい

class TaskManager {
private:
	friend class Task;
	int m_task_num = 0;
	Task * m_head_task = nullptr;

	void QuickSort(Task** _task_array, int* _task_dp_array, int _task_num);
	Task* GetHead() { return m_head_task; };
public:
	//@brief タスクを追加する
	//@param [in] _task 該当タスクへのポインタ
	void AddTask(Task* _task);

	//@brief タスクIDからタスクを探索し、一番最初に見つかったものを返す。
	//@param [in] _task_id 探すタスクのID
	Task* FindTask(int _task_id);

	//@brief タスクIDからタスクを探索し、該当IDのタスクで構成された配列を作成し、その配列のポインタを返す。使用後は、リーク防止のためにfree関数でクリアすること。
	//@param [in] _task_id 探すタスクのID
	Task** FindTaskArray(int _task_id);

	//@brief 該当タスクを削除する
	//@param [in] _task_id 削除するタスクのポインタ
	void DeleteTask(Task* _task);

	//@brief 全てのタスクを削除する
	void DeleteAllTask();

	//@brief 削除フラグを確認し、削除フラグが設定されているタスクを全て削除する
	void CheckDeleteAll();

	//@brief 全てのタスクのBeforeUpdate関数を実行する。
	void BeforeUpdateAll();

	//@brief 全てのタスクのUpdate関数を実行する。
	void UpdateAll();

	//@brief 全てのタスクのAfterUpdate関数を実行する。
	void AfterUpdateAll();


	//@brief 全てのタスクのBeforeCollisionCheck関数を実行する。
	void BeforeCollisionAll();

	//@brief 全てのタスクに対してCollisionCheck関数を実行する。
	void CollisionAll();

	//@brief 全てのタスクに対してDraw関数を実行する。
	void DrawAll();

	//@brief 描画優先度に応じてタスクの順番をソートする。
	void Sort();

	//@brief インスタンスを取得する。
	static TaskManager* GetInstance();

	//@brief インスタンスをクリア
	static void ClearInstance();
};

/*
2019/03/07 TaskManagerクラス定義。基本機能実装。by shingai
2019/03/08 バグ修正やソート部分をクイックソートに変更。 by shingai
2019/03/11 BeforeUpdate等追加に合わせた関数追加。
*/
