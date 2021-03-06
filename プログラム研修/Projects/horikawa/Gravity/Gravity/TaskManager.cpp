#include "TaskManager.h"
#include "Task.h"
#include <stdlib.h>

TaskManager* TaskManager::mp_instance = nullptr;
Task* TaskManager::mp_head = nullptr;

void TaskManager::Add(Task* a)
{
	//headがまだ作られていなかった場合、格納し終了する
	if (mp_head == nullptr) {
		mp_head = a;
	}
	else {
		//二個め以降の場合、タスクをつなげる
		Task *search = mp_head;
		while (search->mp_next) {
			search = search->mp_next;
		}
		search->mp_next = a;
		a->mp_prev = search;
	}
}

void TaskManager::DrawAll()
{
	Task* d = mp_head;
	while (d->mp_next)
	{
		d->Draw();
		d = d->mp_next;
	}
	d->Draw();
}

void TaskManager::Delete(Task* a)
{
	
	if (a->mp_prev) {
		if (a->mp_next) {
			a->mp_prev->mp_next = a->mp_next;
			a->mp_next->mp_prev = a->mp_prev;
		}
		else a->mp_prev->mp_next = nullptr;
	}
	else if (a->mp_next) {
		mp_head = a->mp_next;
		a->mp_next->mp_prev = nullptr;
	}
	else mp_head = nullptr;
	delete this;
}

SearchID* TaskManager::Search(int id)
{
	Task* s = mp_head;
	SearchID* a = new SearchID;
	SearchID* b = a;
	while (s->mp_next) {
		if (s->m_id == id) {
			a->next = new SearchID;
			a->next->point = s;
			a = a->next;
		}
		s = s->mp_next;
	}if (s->m_id == id) {
		a->next = new SearchID;
		a->next->point = s;
		a = a->next;
	}

	/*++c;
	Task** a = (Task**)calloc(c,sizeof(Task*));

	s = mp_head;
	c = 0;
	while (s->mp_next) {
		if (s->m_id = id) {
			a[c] = s;
			++c;
		}
		s = s->mp_next;
	}if (s->m_id = id) {
		a[c] = s;
		++c;
	}
	a[c] = nullptr;*/
	
	return b;
}
