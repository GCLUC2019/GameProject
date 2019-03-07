#include <stdio.h>
#include <list>
#define GRAVITY -9.8f
class Task {
private:
    
public:
    Task * mp_next;
    Task * mp_prev;
    Task();
    virtual void Draw();
};

Task::Task(){}

void Task::Draw() {
    printf("TaskDraw\n");
}

Task*head;
class A :public Task {
private:
public:
    void Draw();
};
void A::Draw() {
    printf("ADraw\n");
}
int main() {    
    head = new Task();

    for (int i = 0; i < 3; ++i) {
        Task*t = new A();
        Task*n = head;
        //タスクをつなげる
        //headにnextがあれば次のやつその次のやつにも次があればその次みたいな
        while (n->mp_next) {
            n->mp_next->mp_prev = n;//nextのprevにnを入れる
            n = n->mp_next;
        }
        //最後尾のタスクにnextを追加
        n->mp_next = t;
    }

    //headからタスクのDraw関数を呼び出す
    Task*t = head;
    while (t) {
        t->Draw();
        t = t->mp_next;
    }
    getchar();
    return 0;
    /*double V0 = 4.9f;
    double h0 = 29.4f;
    for (int i = 0; i < 6; ++i) {
        double h = h0 + V0 * i + (GRAVITY*i*i)/2;
        printf("%d 秒後 %f m\n", i, h);
}
    getchar();
    return 0;*/
}