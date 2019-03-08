
#include"TaskManager.h"

Task* TaskManager::m_head = nullptr;
 Task*  TaskManager::m_last = nullptr;
TaskManager::TaskManager()
{
}
void TaskManager::Addf(Task* t) {
	if (m_head == nullptr&&m_head == nullptr) {
		m_head = t;
		m_last = t;
		return;
	}
	Task* n = m_last;
	while (n->GetPrev() != nullptr) {
		n = n->GetPrev();
	}
	n->SetPrev(t);
	t->SetNext(n);
	SetHead(t);
}

void TaskManager::Add(Task* t) {
	if (m_head == nullptr&&m_head == nullptr) {
		m_head = t;
		m_last = t;
		return;
	}
	Task* n = m_last;
	while (n->GetNext() != nullptr) {
		n = n->GetNext();
	}
	n->SetNext(t);
	t->SetPrev(n);
	SetLast(t);
}
void TaskManager::TaskSort(bool f)
{
	Task * now = nullptr;
	if (f) //昇順ソート
	{

	}
	else//降順ソート
	{

	}
}
void TaskManager::Swap(Task * t1, Task * t2)
{
	if (t1 == t2|| t1 == nullptr || t2 == nullptr)
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
void TaskManager::DrawAll(Task* t, bool f) {
	if (f) {
		while (t->GetPrev() != nullptr) {
			t = t->GetPrev();
		}
		while (t) {
			t->Draw();
			t = t->GetNext();
		}
	}
	else {
		while (t->GetNext() != nullptr) {
			t = t->GetNext();
		}
		while (t) {
			t->Draw();
			t = t->GetPrev();
		}
	}

}

