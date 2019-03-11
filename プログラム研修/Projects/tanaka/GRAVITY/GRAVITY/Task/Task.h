#pragma once
#include <stdio.h>
class Task {
protected:
    int m_type;
    int m_updateprio;
    int m_drawprio;
    Task * mp_next;
    Task * mp_prev;
    void SetNext(Task*t) {
        mp_next = t;
    }
    void SetPrev(Task*t) {
        mp_prev = t;
    }
public:
    Task(int _eType,int _eUpdatePrio,int _eDrawPrio);
    virtual void Draw();
    
    Task*GetNext() {
        return mp_next;
    }
    Task*GetPrev() {
        return mp_prev;
    }
    int GetType() {
        return m_type;
    }
    int GetUpdatePrio() {
        return m_updateprio;
    }
    int GetDrawPrio() {
        return m_drawprio;
    }
    friend class TaskManager;
};

//class A :public Task {
//private:
//public:
//    void Draw();
//};
//void A::Draw() {
//    printf("ADraw\n");
//}