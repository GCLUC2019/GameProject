#include <stdio.h>
#include <list>
#include "Task/Task.h"
#include "Task/TaskManager.h"
#define GRAVITY -9.8f

int main() {  
    for (int i = 0; i < 3; ++i) {
        TaskManager::Add(new Task(1, 1, 1));
    }
    TaskManager::Insert(new Task(1, 2, 1));
    TaskManager::Insert(new Task(1, 5, 1));

    TaskManager::DrawAll();
    ////head����^�X�N��Draw�֐����Ăяo��
    //Task*t = head;
    //while (t) {
    //    t->Draw();
    //    t = t->GetNext();
    //}
    ////��납��\��
    //t = last;
    //while (t) {
    //    t->Draw();
    //    t = t->GetPrev();
    //}

   /* double V0 = 4.9f;
    double h0 = 29.4f;
    for (int i = 0; i < 6; ++i) {
        double h = h0 + V0 * i + (GRAVITY*i*i)/2;
        printf("%d �b�� %f m\n", i, h);
}*/
    getchar();
    return 0;
}