#pragma once
#include <stdio.h>
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
    static void Add(Task*_t);
    /*
    @brief          連結順番を変更する
    @param  [in]    比較対象
    */
    static void TaskSort(float _comp);
    /*
    @brief          新たなタスクを挿入する
    @param  [in]    挿入するタスク
    @param  [in]    挿入する場所
    */
    static void Insert(Task*_t, int _in);

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

Task*head = nullptr;
Task*last = nullptr;

class A :public Task {
private:
public:
    void Draw();
};
void A::Draw() {
    printf("ADraw\n");
}