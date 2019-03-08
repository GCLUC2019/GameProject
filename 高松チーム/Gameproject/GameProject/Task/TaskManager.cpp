#include "TaskManager.h"
#include "Task.h"

Task* TaskManager::mp_head = nullptr;
Task* TaskManager::mp_last = nullptr;
TaskManager* TaskManager::mp_instance = nullptr;

TaskManager::TaskManager() {

}

void TaskManager::AddTask(Task * _t)
{
	if (mp_head == nullptr && mp_last == nullptr) {
		mp_head = _t;
		mp_last = _t;
		return;
	}
	else {

		Task* t = mp_head;
		while (t->GetNext() != nullptr) {
			t = t->GetNext();
		}

		t->SetNext(_t);
		_t->SetPrev(_t);
		SetLast(_t);
	}

}

void TaskManager::UpdateAll()
{
	Task* d = mp_head;

	while (d) {
		d->Update();
		d = d->GetNext();
	}
}

void TaskManager::DrawAll()
{
	Task* d = mp_head;

	while (d) {
		d->Draw();
		d = d->GetNext();
	}
}

void TaskManager::Kill(Task * _t)
{
	Task* k = mp_head;

}

void TaskManager::KillAll()
{
	Task* k = mp_head;
	
}

void TaskManager::Search()
{

}

void TaskManager::Swap(Task * t1, Task * t2)
{
	if (t1 == t2 || t1 == nullptr || t2 == nullptr)
		return;
	Task *s1 = t1->GetNext();
	Task *s2 = t2->GetNext();
	t1->SetNext(s2);
	if (s2 == nullptr)
		SetLast(t1);
	else
		s2->SetPrev(t1);
	t2->SetNext(s1);
	if (s1 == nullptr)
		SetLast(t2);
	else
		s1->SetPrev(t2);
	s1 = t1->GetPrev();
	s2 = t2->GetPrev();
	t1->SetPrev(s2);
	if (s2 == nullptr)
		SetHead(t1);
	else
		s2->SetNext(t1);
	t2->SetPrev(s1);
	if (s1 == nullptr)
		SetHead(t2);
	else
		s1->SetNext(t2);
}

TaskManager * TaskManager::GetInstance()
{
	if (mp_instance == nullptr)mp_instance = new TaskManager();
	return mp_instance;
}

void TaskManager::ClearInstance()
{
	if (mp_instance != nullptr) delete mp_instance;
	mp_instance = nullptr;
}
