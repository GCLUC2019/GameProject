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
		_t->SetPrev(t);
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

void TaskManager::HitCheckAll()
{
    //Task* d = mp_head;
    //Task* d2 = d->GetNext();
    ////総当たりならこれでいける？
    //while (d) {
    //	while (d2) {
    //		d->HitCheck(d2);
    //		d2->GetNext();
    //	}		
    //	d = d->GetNext();
    //}

    Task* d = mp_head;
    while (d) {
        Task* d2 = d->GetNext();
        while (d2) {
            d->HitCheck(d2);
            d2->HitCheck(d);
            d2 = d2->GetNext();
        }
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
/*
作成　田中
*/
void TaskManager::CheckKillAll()
{
    Task*next = nullptr;
    Task* k = mp_head;
    do {
        //キルフラグがtrueなら
        if (k->m_kill_flg) {
            //前後を繋ぎなおす
            if (k== mp_head) {
                mp_head = k->mp_next;
                k->mp_next->SetPrev(nullptr);
                next = k->mp_next;
            }
            else if (k == mp_last) {
                mp_last = k->mp_prev;
                k->mp_prev->SetNext(nullptr);
                next = nullptr;
            }
            else {
                k->mp_prev->SetNext(k->mp_next);
                k->mp_next->SetPrev(k->mp_prev);
                next = k->mp_next;
            }
            //削除
            delete k;
            //次のタスク
            k = next;
        }
        else
            //次のタスク
            k = k->GetNext();
    } while (k);

	//k = mp_head;
	//while (k->GetPrev() != nullptr)
	//	k = k->GetPrev();
	//mp_head = k;
	//while (k->GetNext() != nullptr)
	//	k = k->GetNext();
	//mp_last = k;
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

void TaskManager::TaskSort(float _comp)
{

}

void TaskManager::Insert(Task * _t)
{
	//headがnullならheadに_tを入れて返す
	if (mp_head == nullptr) {
		mp_head = _t;
		mp_last = _t;
		return;
	}
	else {
		Task*t = _t;
		Task*n = mp_head;
		bool check = false;
		while (t->m_updateprio > n->m_updateprio) {
			if (n == mp_last) {
				//mp_last = t;
				check = true;
				break;
			}
			if (n->GetNext())
				n = n->GetNext();
			else
				break;
		}
		ReLink(check, t, n);

		/*t->SetNext(n);
		if (n->GetPrev()) {
		t->SetPrev(n->GetPrev());
		}
		else {
		t->SetPrev(nullptr);
		mp_head = t;
		}

		n->GetPrev()->SetPrev(t);
		n->SetPrev(t);*/
	}
}

void TaskManager::ReLink(bool _fb, Task*_t1, Task * _t2)
{
	Task*t1 = _t1;
	Task*t2 = _t2;
	//前に追加してつなぎなおす
	if (_fb == false) {
		t1->SetNext(t2);
		if (t2->GetPrev() == nullptr) {
			t1->SetPrev(nullptr);
			mp_head = t1;
		}
		else
			t1->SetPrev(t2->GetPrev());

		t2->SetPrev(t1);
	}
	//後ろに追加してつなぎなおす
	if (_fb == true) {
		t1->SetPrev(t2);
		if (t2->GetNext() == nullptr) {
			t1->SetNext(nullptr);
			mp_last = t1;
		}
		else
			t1->SetNext(t2->GetNext());

		t2->SetNext(t1);
	}
}
/*担当
田中*/
Task * TaskManager::FindObject(int _type)
{
    Task*t = mp_head;
    while (t->GetType() != _type) {

        if (t->GetNext())
            t = t->GetNext();
        else
            return nullptr;
    }
    return t;
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
