#include "Task.h"

Task::Task() {
}

void Task::Draw() {
    printf("TaskDraw\n");
}

void Task::Add(Task*_t)
{
    //headがnullならheadに_tを入れて返す
    if (head == nullptr) {
        head = _t;
        return;
    }
    Task*t = _t;
    Task*n = head;
    //タスクをつなげる
    //headにnextがあれば次のやつその次のやつにも次があればその次みたいな
    while (n->GetNext()) {
        n = n->GetNext();
    }
    //最後尾のタスクにnext,prevを追加
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



