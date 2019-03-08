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
    static void Insert(Task*_t);

};