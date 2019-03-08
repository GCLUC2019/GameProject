#include <stdio.h>
#include <list>
#include "Task/Task.h"
#define GRAVITY -9.8f

int main() {  
    Task::Add(new A());
    //head = new Task();
    //for (int i = 0; i < 3; ++i) {
    //    Task*t = new A();
    //    Task*n = head;
    //    //タスクをつなげる
    //    //headにnextがあれば次のやつその次のやつにも次があればその次みたいな
    //    while (n->GetNext()) {
    //        n = n->GetNext();
    //    }
    //    //最後尾のタスクにnextを追加
    //    n->SetNext(t);
    //    t->SetPrev(n);
    //    last = t;
    //}

    //headからタスクのDraw関数を呼び出す
    Task*t = head;
    while (t) {
        t->Draw();
        t = t->GetNext();
    }
    ////後ろから表示
    //t = last;
    //while (t) {
    //    t->Draw();
    //    t = t->GetPrev();
    //}

   /* double V0 = 4.9f;
    double h0 = 29.4f;
    for (int i = 0; i < 6; ++i) {
        double h = h0 + V0 * i + (GRAVITY*i*i)/2;
        printf("%d 秒後 %f m\n", i, h);
}*/
    getchar();
    return 0;
}