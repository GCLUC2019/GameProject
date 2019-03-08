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
    @brief          �V�K�^�X�N�𖖔��ɒǉ�
    @param  [in]    �ǉ�����^�X�N
    */
    static void Add(Task*_t);
    /*
    @brief          �A�����Ԃ�ύX����
    @param  [in]    ��r�Ώ�
    */
    static void TaskSort(float _comp);
    /*
    @brief          �V���ȃ^�X�N��}������
    @param  [in]    �}������^�X�N
    @param  [in]    �}������ꏊ
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