#pragma once
#include"Task.h"

class TaskManager {
private:
	static Task* m_head;	//先頭ポインタ
	static Task* m_last;	//末尾ポインタ
	static Task* m_exclude;	//除外リスト先頭ポインタ
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
	
	static Task* GetExclude() {
		return m_exclude;
	}
	
	static void SetHead(Task* t) {
		m_head = t;
	}
	static void SetLast(Task* t) {
		m_last = t;
	}
	/*!
	@brief
	@param	bool f			[in]フラグ　tureなら昇順flseなら降順
	**/
	static void TaskSort(bool f);
	/*!
	@brief	入れ替え関数　t1とt2を入れ替える
	@param	Task* t1			[in] 入れ替えたいオブジェクトのポインタ
	@param	Task* t2			[in] 入れ替えたいオブジェクトのポインタ
	**/
	static void Swap(Task* t1, Task* t2);
	
	/*!
	@brief	リストから除外して除外リストに追加
	@param	Task* t			[in] 除外するオブジェクトのポインタ
	**/
	static void Exclusion(Task* t);
	
	/*!
	@brief	除外リストを空にする（リスト内全削除）
	**/
	static void  ExclusionDelete();
	/*!
	@brief	リスト全てのDraw関数を呼び出す
	@param	Task* t			[in] オブジェクトのポインタ
	@param	bool f			[in] フラグ　tureなら先頭からflseなら末尾から
	**/
	static void DrawAll(Task* t, bool f);

};
