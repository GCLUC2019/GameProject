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
    @brief	入れ替え関数　t1とt2を入れ替える
    @param	Task* t1			[in] 入れ替えたいオブジェクトのポインタ
    @param	Task* t2			[in] 入れ替えたいオブジェクトのポインタ
    **/
    static void Swap(Task* t1, Task* t2);
    /*!
    @brief	入れ替え関数　t1とt2を入れ替える 
    @param  [in]falseで前に挿入、trueで後ろに挿入
    @param	Task* t1			[in] 入れ替えたいオブジェクトのポインタ
    @param	Task* t2			[in] 挿入したい場所のポインタ
    **/
    static void ReLink(bool _fb, Task* t1, Task* t2);
};