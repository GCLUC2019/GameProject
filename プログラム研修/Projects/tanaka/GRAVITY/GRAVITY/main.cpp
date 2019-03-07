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
    @brief          新規タスクを末尾に追加
    @param  [in]    追加するタスク
    */
    static void Add(Task*_t,int _num = 1);
    /*
    @brief          連結順番を変更する
    @param  [in]    比較対象
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
    //headがnullならheadに_tをいれてnumを減算
    if (head == nullptr) {
        head = _t;
        _num -= 1;
    }
    for (int i = 0; i < _num; ++i) {
        Task*t = _t;
        Task*n = head;
        //タスクをつなげる
        //headにnextがあれば次のやつその次のやつにも次があればその次みたいな
        while (n->GetNext()) {
            n = n->GetNext();
        }
        //最後尾のタスクにnextを追加
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
    //後ろから表示
    t = last;
    while (t) {
        t->Draw();
        t = t->GetPrev();
    }

   /* double V0 = 4.9f;
    double h0 = 29.4f;
    for (int i = 0; i < 6; ++i) {
        double h = h0 + V0 * i + (GRAVITY*i*i)/2;
        printf("%d 秒後 %f m\n", i, h);
}*/
    getchar();
    return 0;
}