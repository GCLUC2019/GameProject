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
    //    //�^�X�N���Ȃ���
    //    //head��next������Ύ��̂���̎��̂�ɂ���������΂��̎��݂�����
    //    while (n->GetNext()) {
    //        n = n->GetNext();
    //    }
    //    //�Ō���̃^�X�N��next��ǉ�
    //    n->SetNext(t);
    //    t->SetPrev(n);
    //    last = t;
    //}

    //head����^�X�N��Draw�֐����Ăяo��
    Task*t = head;
    while (t) {
        t->Draw();
        t = t->GetNext();
    }
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