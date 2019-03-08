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
	static void SetHead(Task *t) { t = mp_head; }
	static void SetLast(Task *t) { t = mp_last; }
	
	TaskManager();
	static void AddTask(Task *_t);
	static void UpdateAll();
	static void DrawAll();
	static void Kill(Task* _t);
	static void KillAll();
	static void Search();
	static void Swap(Task* t1, Task* t2);

	static TaskManager* GetInstance();
	static void ClearInstance();
	
};

