#include <stdio.h>
#include <list>
#define GRAVITY -9.8f
class Task {
private:
    Task * mp_next;
    Task * mp_prev;
public:
    Task();
    virtual void Draw();
    /*
    @brief          �V�K�^�X�N�𖖔��ɒǉ�
    @param  [in]    �ǉ�����^�X�N
    */
    static void Add(Task*_t,int _num = 1);
    /*
    @brief          �A�����Ԃ�ύX����
    @param  [in]    ��r�Ώ�
    */
    static void TaskSort(float _comp);

    Task*GetNext() {//
        return mp_next;
    }
    Task*GetPrev() {
        return mp_prev;
    }
    void SetNext(Task*t) {
        mp_next = t;
    }
    void SetPrev(Task*t) {
        mp_prev = t;
    }
};
Task*head;
Task*last;
Task::Task(){}

void Task::Draw() {
    printf("TaskDraw\n");
}

void Task::Add(Task*_t, int _num)
{
    //head��null�Ȃ�head��_t�������num�����Z
    if (head == nullptr) {
        head = _t;
        _num -= 1;
    }
    for (int i = 0; i < _num; ++i) {
        Task*t = _t;
        Task*n = head;
        //�^�X�N���Ȃ���
        //head��next������Ύ��̂���̎��̂�ɂ���������΂��̎��݂�����
        while (n->GetNext()) {
            n = n->GetNext();
        }
        //�Ō���̃^�X�N��next��ǉ�
        n->SetNext(t);
        t->SetPrev(n);
        last = t;
    }
}

void Task::TaskSort(float _comp)
{

}



class A :public Task {
private:
public:
    void Draw();
};
void A::Draw() {
    printf("ADraw\n");
}

int main() {  
    Task::Add(new A(), 5);
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
    //��납��\��
    t = last;
    while (t) {
        t->Draw();
        t = t->GetPrev();
    }

   /* double V0 = 4.9f;
    double h0 = 29.4f;
    for (int i = 0; i < 6; ++i) {
        double h = h0 + V0 * i + (GRAVITY*i*i)/2;
        printf("%d �b�� %f m\n", i, h);
}*/
    getchar();
    return 0;
}