#include<stdio.h>
#include"TaskManager.h"

Task* TaskManager::m_head = nullptr;
 Task*  TaskManager::m_last = nullptr;
 Task*  TaskManager::m_exclude = nullptr;
TaskManager::TaskManager()
{
}
void TaskManager::Addf(Task* t) {
	if (m_head == nullptr&&m_last == nullptr) {
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
	t->SetPrev(nullptr);
	SetHead(t);
}

void TaskManager::Add(Task* t) {
	if (m_head == nullptr&&m_last == nullptr) {
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
	t->SetNext(nullptr);
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
void TaskManager::Exclusion(Task * t)
{
	if (t == nullptr)
		return;
	Task *s;
	if (t == m_head) {
		s = t->GetNext();
		s->SetPrev(nullptr);
		SetHead(s);
		t->SetNext(nullptr);
	}else if (t == m_last) {
		s = t->GetPrev();
		s->SetNext(nullptr);
		SetLast(s);
		t->SetPrev(nullptr);
	}
	else {
		s = t->GetPrev();
		s->SetNext(t->GetNext());
		s = t->GetNext();
		s->SetPrev(t->GetPrev());
		t->SetPrev(nullptr);
		t->SetNext(nullptr);
	}
	
	if (m_exclude == nullptr)
		m_exclude = t;
	else
	{
		s = m_exclude;
		while (s->GetNext()!=nullptr)
		{
			s = s->GetNext();
		}
		s->SetNext(t);
	}
}
void TaskManager::ExclusionDelete()
{
	Task *s = m_exclude;
	while (s) {
		m_exclude = m_exclude->GetNext();
		delete (s);
		printf("削除\n");
		s = m_exclude;
	}
	m_exclude = nullptr;
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

