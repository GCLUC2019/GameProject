#pragma once
#include "TaskManager.h"

class Task {
private:
	//フレンドクラスとしてタスクマネージャを指定
	friend class TaskManager;

	int m_task_id;

	//描画優先度 高い程優先して描画される == 後から描画される(優先度が高い程 画面の前に出やすくなる)
	int m_draw_priority = 0;

	//削除フラグ(一括削除の方が軽いケースなどに用いる)
	bool m_is_delete = false;

	Task * m_before_task = nullptr;
	Task * m_next_task = nullptr;

	//TaskManagerクラスが使用する関数
	void SetBeforeTask(Task* _before) { m_before_task = _before; };
	Task* GetBeforeTask() { return m_before_task; };

	void SetNextTask(Task* _next) { m_next_task = _next; };
	Task* GetNextTask() { return m_next_task; };

	//@brief タスクを即座に削除する。
	void Delete();
public:
	//@brief タスククラスコンストラクタ
	//@param [in] _task_id タスク識別用のID
	//@param [in] _draw_priority 描画優先度(値の大きいものを優先して手前に描画する)
	Task(int _task_id = 0,int _draw_priority = 0);

	//@brief タスククラスデストラクタ
	virtual ~Task();

	//@brief 更新用関数(更新の前に呼ばれる更新処理)
	virtual void BeforeUpdate();

	//@brief 更新用関数
	virtual void Update();

	//@brief 更新用関数(後に呼ばれる更新処理)
	virtual void AfterUpdate();

	//@brief 描画更新用関数
	virtual void Draw();

	//@brief 衝突チェック前更新関数
	virtual void BeforeCollisionCheck();


	//@brief 衝突チェック用関数
	virtual void CollisionCheck(Task* _collision_task);
	

	//@brief 描画優先度の設定
	//@param [in] _priority 描画優先度 高い程、手前に描画する。
	void SetDrawPriority(int _priority) { m_draw_priority = _priority; };

	//@brief 描画優先度の取得
	int GetDrawPriority() { return m_draw_priority; };

	//@brief タスクIDの設定
	//@param [in] _priority _task_id 設定するタスクID
	void SetTaskId(int _task_id) { m_task_id = _task_id; };

	//@brief タスクIDの取得
	int GetTaskId() { return m_task_id; };

	

	//@brief タスクに削除フラグを設定する。(更新処理が終了後、一括に削除される)
	void SetIsDelete() {m_is_delete = true; };//削除フラグをオンにする

	//@brief 削除フラグの可否を取得する。
	bool GetIsDelete() { return m_is_delete; };
};

/*
2019/03/07 Taskクラス定義。基本機能実装。 by shingai
2019/03/08 TaskManagerクラスへの修正に合わせた小規模な修正。 by shingai
2019/03/11 BeforeUpdate等、ゲームの制御に役に立つメンバ関数追加。
*/
