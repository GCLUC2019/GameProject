#include "Task.h"

Task::Task() {
}

void Task::Draw() {
    printf("TaskDraw\n");
}

void Task::Add(Task*_t)
{
    //head��null�Ȃ�head��_t�����ĕԂ�
    if (head == nullptr) {
        head = _t;
        return;
    }
    Task*t = _t;
    Task*n = head;
    //�^�X�N���Ȃ���
    //head��next������Ύ��̂���̎��̂�ɂ���������΂��̎��݂�����
    while (n->GetNext()) {
        n = n->GetNext();
    }
    //�Ō���̃^�X�N��next,prev��ǉ�
    n->SetNext(t);
    t->SetPrev(n);
    last = t;

}

void Task::TaskSort(float _comp)
{

}

void Task::Insert(Task * _t, int _in)
{
    Task*t = _t;
    Task*n = head;
    for (int i = 0; i < _in; ++i) {

    }

}



