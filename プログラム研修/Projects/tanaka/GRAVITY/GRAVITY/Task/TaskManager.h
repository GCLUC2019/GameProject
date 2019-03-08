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
    */
    static void Insert(Task*_t);
    Task* GetHead() {
        return mp_head;
    }
    Task* GetLast() {
        return mp_last;
    }
    static void SetHead(Task* t) {
        mp_head = t;
    }
    static void SetLast(Task* t) {
        mp_last = t;
    }
    /*!
    @brief	����ւ��֐��@t1��t2�����ւ���
    @param	Task* t1			[in] ����ւ������I�u�W�F�N�g�̃|�C���^
    @param	Task* t2			[in] ����ւ������I�u�W�F�N�g�̃|�C���^
    **/
    static void Swap(Task* t1, Task* t2);
    /*!
    @brief	����ւ��֐��@t1��t2�����ւ��� 
    @param  [in]false�őO�ɑ}���Atrue�Ō��ɑ}��
    @param	Task* t1			[in] ����ւ������I�u�W�F�N�g�̃|�C���^
    @param	Task* t2			[in] �}���������ꏊ�̃|�C���^
    **/
    static void ReLink(bool _fb, Task* t1, Task* t2);
};