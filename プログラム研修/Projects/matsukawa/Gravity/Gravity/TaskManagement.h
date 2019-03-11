#pragma once
#include "Task.h"
#include <list>

//タスクID
enum {
	Task_id = 0,
	TaskA_id = 1,
};

//タスク優先度
enum {
	Task_prio = 0,
	TaskA_prio = 1,
};


class TaskManagement
{
private:
	//タスクマネジメントシステムのインスタンス
	static TaskManagement* mp_t_ins;
protected:
	Task * mp_head;   //先頭ポインタ
	Task * mp_tail;   //末尾ポインタ
public:
	TaskManagement();
	~TaskManagement();
	//タスク追加関数（引数は追加したいタスクのポインタ）
	void Add(Task* _add);
	//先頭タスクセット関数（引数は先頭に置きたいタスクのポインタ）
	void SetHead(Task* add_t);
	//末尾タスクセット関数(引数は末尾に置きたいタスクのポインタ）
	void SetTail(Task* add_t, Task* now_t);
	//タスク挿入関数（引数は挿入したいたいタスクとその場所にあるタスク）
	void InsertTask(Task* add_t, Task* now_t);
	//タスクを全てアップデート
	void UpdateAll();       
	//タスクを全て描画
	void DrawAll();
	//末尾から順番に描画する
	void DrawTailAll();
	//フラグが立ったタスクだけキル
	void FlagKill();
	//破棄フラグを全て立てる関数
	void KillFlagAll();
	//タスクを全て破棄する関数
	void KillAll();
	//タスク離脱関数（引数は外したいタスク）
	void RemoveTask(Task* rem_p);
	//タスク優先度変更関数(引数は変えたいタスクと優先度）
	void ChangePrio(Task* change_p, int priority);
	//タスク破棄関数(引数は破棄したいタスク
	void Kill(Task* kill_p);

	//タスク取得関数(引数は取得したいタスクのID)
	Task* GetTask(int&id)const;
	//タスクリスト取得関数
	std::list<Task*> GetTasks(int& id) const;	
	//個数カウント関数
	int GetCount(int& id)const;

	//タスクマネジメントのポインタ生成取得
	static TaskManagement* GetIns();
	//インスタンスのクリア
	static void ClearIns();
};
