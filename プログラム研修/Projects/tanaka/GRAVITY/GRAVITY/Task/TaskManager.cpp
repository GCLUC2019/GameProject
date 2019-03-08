#include "TaskManager.h"
Task* TaskManager::mp_head = nullptr;
Task* TaskManager::mp_last = nullptr;
TaskManager::TaskManager()
{
}
void TaskManager::UpdateAll()
{
}
void TaskManager::DrawAll()
{
    Task*t = mp_head;
    while (t) {
        t->Draw();
        /*if (t->GetNext() == nullptr)
            t = mp_head;
        else*/
        t = t->GetNext();
    }
}
void TaskManager::Add(Task*_t)
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
        //タスクをつなげる
        //headにnextがあれば次のやつその次のやつにも次があればその次みたいな
        while (n->GetNext()) {
            n = n->GetNext();
        }
        //最後尾のタスクにnext,prevを追加
        n->SetNext(t);
        t->SetPrev(n);
        mp_last = t;
    }
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
        while (t->GetUpdatePrio() > n->GetUpdatePrio()) {
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

