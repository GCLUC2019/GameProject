#pragma once
#include "Task.h"

class TaskManager {
private:
    static Task * mp_head;
    static Task * mp_last;
public:
    TaskManager();
    static void UpdateAll();
    static void DrawAll();
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
    static void Insert(Task*_t);

};