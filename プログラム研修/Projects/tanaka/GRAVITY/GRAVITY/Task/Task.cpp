#include "Task.h"
Task::Task(int _eType, int _eUpdatePrio, int _eDrawPrio) :
    m_type(_eType),
    m_updateprio(_eUpdatePrio),
    m_drawprio(_eDrawPrio),
    mp_next(nullptr),
    mp_prev(nullptr)
{
    
}

void Task::Draw() {
    printf("%d\n",GetUpdatePrio());
}
