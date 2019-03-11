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
	//Taskを継承したオブジェクトを作成した時に呼ばれ、最後尾に追加する
	void Add(Task* a);
	//全てのオブジェクトの描画処理
	void DrawAll();
	//引数で与えたオブジェクトの削除
	void Delete(Task* a);
	//引数で与えたIDを持つオブジェクトを単方向リストの構造体でまとめ、その先頭を返す
	struct SearchID* Search(int id);
};

//指定されたオブジェクトを見つけ単方向リストでまとめていく構造体
struct SearchID
{
	Task* point = nullptr;
	SearchID* next = nullptr;
};
