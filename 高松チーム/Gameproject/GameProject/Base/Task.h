#pragma once
#include <stdio.h>
#include "../stdafx.h"
#include "TaskManager.h"
#include "../Game/Character/enum.h"

class Task {
private:
    int m_updateprio;
    int m_drawprio;
    bool m_kill_flg = false;
    Task *mp_next = nullptr;
    Task *mp_prev = nullptr;
    Task *GetNext() { return mp_next; }
    Task *GetPrev() { return mp_prev; }
protected:
    int m_type;
    float m_depth;
public:
    Task(int _type);
    virtual void Update();
    virtual void HitCheck(Task* _t);
    virtual void Draw();    
    void SetNext(Task *_var) { mp_next = _var; }
    void SetPrev(Task *_var) { mp_prev = _var; }
    void SetKill() {
        m_kill_flg = true;
    }
    virtual int GetType() { return m_type; }
    virtual float GetDepth(){ return m_depth; }
    friend class TaskManager;

};