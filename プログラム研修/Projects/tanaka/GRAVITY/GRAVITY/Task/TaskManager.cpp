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
        t = t->GetNext();
    }
}
void TaskManager::Add(Task*_t)
{
    //head��null�Ȃ�head��_t�����ĕԂ�
    if (mp_head == nullptr) {
        mp_head = _t;
        mp_last = _t;
        return;
    }
    else {
        Task*t = _t;
        Task*n = mp_head;
        //�^�X�N���Ȃ���
        //head��next������Ύ��̂���̎��̂�ɂ���������΂��̎��݂�����
        while (n->GetNext()) {
            n = n->GetNext();
        }
        //�Ō���̃^�X�N��next,prev��ǉ�
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
    //head��null�Ȃ�head��_t�����ĕԂ�
    if (mp_head == nullptr) {
        mp_head = _t;
        mp_last = _t;
        return;
    }
    else {
        Task*t = _t;
        Task*n = mp_head;

        while (n->GetNext()&&t->GetUpdatePrio() > n->GetUpdatePrio()) {
            n = n->GetNext();
        }
        
        t->SetNext(n);
        if (n->GetPrev()) {
            t->SetPrev(n->GetPrev());
        }           
        else {
            t->SetPrev(nullptr);
            mp_head = t;
        }
        n->SetPrev(t);
    }
}



