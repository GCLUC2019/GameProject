#pragma once
#include "Task.h"
#include <list>

class TaskManager
{
private:
	//タスクマネージャーのインスタンス
	static TaskManager* mp_instance;
protected:
	Task * mp_head;  //リストの先頭
	Task * mp_tail;  //リストの末尾
public:
	TaskManager();
	~TaskManager();
	void AddTask(Task* p);    //タスクの追加
	void SelectKill();        //指定したタスクのみを破棄
	void SetKillAll();        //全てのタスクの破棄フラグを立てる
	void UpdateAll();         //タスクを全てアップデート
	void DrawAll();           //タスクを全て描画
	void KillAll();           //タスクを全て破棄
	//タスクの優先順位の変更
	void ChangePrio(Task* p, int priorty);
	void RemoveTask(Task*p);  //タスクの連結を外す

	void Kill(Task* p);
	static TaskManager* GetInstance();
};