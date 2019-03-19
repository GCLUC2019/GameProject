#pragma once

class Task;
class TaskManager {
private:
	static Task *mp_head;
	static Task *mp_last;
	static TaskManager* mp_instance;

protected:
	
public:
	Task * GetHead() { return mp_head; }
	Task* GetLast() { return mp_last; }
	static void SetHead(Task *t) { mp_head = t; }
	static void SetLast(Task *t) { mp_last = t; }
	
	TaskManager();
	static void AddTask(Task *_t);
	static void UpdateAll();
	static void DrawAll();
	static void HitCheckAll();
	static void Kill(Task* _t);
	static void KillAll();
    static void CheckKillAll();
	static void Swap(Task* t1, Task* t2);
    static void TaskSort(/*Task*_this, float _value*/);//ソート用
	/*
	@brief          新たなタスクを挿入する
	@param  [in]    挿入するタスク
	*/
	static void Insert(Task*_t);
	static void ReLink(bool _fb, Task* t1, Task* t2);

    static Task*FindObject(int _type);
	static TaskManager* GetInstance();
	static void ClearInstance();
	
};

