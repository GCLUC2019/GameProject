#pragma once
class Task;


//コメントを書きましょう
//privateに大事な情報はしまう
//コンストラクタでタイプと優先度を与えてやる
//先頭から調べていき優先度が低くなるところへ挿入
//フレンドクラスを利用して特定のオブジェクトには使用させる   friend class Task
//friend class TaskManager
//





class TaskManager {
public:
	static TaskManager* mp_instance;
	static Task* mp_head;
public:
	static TaskManager* GetInstance() {
		//インスタンスを一度のみ生成して格納
		if (mp_instance == nullptr) mp_instance = new TaskManager();
		//それを返す
		return mp_instance;
	}

	void Add(Task* a);
	void DrawAll();
	void Delete(Task* a);
	struct SearchID* Search(int id);
};

struct SearchID
{
	Task* s_point = nullptr;
	SearchID* s_next = nullptr;
};
