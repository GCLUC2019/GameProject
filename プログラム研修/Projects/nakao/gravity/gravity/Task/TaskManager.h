#pragma once
#include"Task.h"

class TaskManager {
private:
	static Task * m_head;	//先頭ポインタ
	static Task * m_last;	//末尾ポインタ

public:
	TaskManager();
	/*!
	@brief	先頭に接続
	@param	Task* t			[in] 作成したオブジェクトのポインタ
	**/
	static void Addf(Task* t);
	/*!
	@brief	末尾に接続
	@param	Task* t			[in] 作成したオブジェクトのポインタ
	**/
	static void Add(Task* t);
	static Task* GetHead() {
		return m_head;
	}
	static Task* GetLast() {
		return m_last;
	}
	/*!
	@brief	末尾に接続
	@param	bool f			[in]フラグ　tureなら昇順flseなら降順 
	**/
	static void TaskSort(bool f);
	
	static void SetHead(Task* t) {
		m_head = t;
	}
	static void SetLast(Task* t) {
		m_last = t;
	}
	/*!
	@brief	入れ替え関数　t1とt2を入れ替える
	@param	Task* t1			[in] 入れ替えたいオブジェクトのポインタ
	@param	Task* t2			[in] 入れ替えたいオブジェクトのポインタ
	**/
	static void Swap(Task* t1, Task* t2);
	/*!
	@brief	リスト全てのDraw関数を呼び出す
	@param	Task* t			[in] オブジェクトのポインタ
	@param	bool f			[in] フラグ　tureなら先頭からflseなら末尾から
	**/
	static void DrawAll(Task* t, bool f);
};
