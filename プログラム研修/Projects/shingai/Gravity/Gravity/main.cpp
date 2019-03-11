#include <stdio.h>
#include <stdlib.h>
/*
実践問題
5秒間放物線のシミュレーションを行う
初速度 4.9m/s
初期高さ 29.4m
重力 9.8m/s


*/
#include "Task.h"
#include "TaskManager.h"

enum {
	eTaskIdNone,
	eTaskIdPlayer,
};

class A : public Task {
private:
public:
	A();
	void Draw();
};

A::A() : Task(eTaskIdNone,1){

}

void A::Draw() {
	printf("Task A Draw\n");
}




//Task* head;

int main() {
	//タスクを1つ生成
	//head = new Task;


	new A();
	
	//Task* p = new Task();
	//p->SetTaskId(eTaskIdPlayer);

	new Task(eTaskIdPlayer,0);
	new Task(eTaskIdPlayer,4);
	new Task(eTaskIdPlayer,3);
	new Task(eTaskIdPlayer, 1);
	new Task(eTaskIdPlayer, 2);
	new Task(eTaskIdPlayer, 5);
	new Task(eTaskIdPlayer, 24);
	new Task(eTaskIdPlayer, 500);
	new Task(eTaskIdPlayer, 2424);
	new Task(eTaskIdPlayer, 54);
	new Task(eTaskIdPlayer, 78);
	new Task(eTaskIdPlayer, 32);
	new Task(eTaskIdPlayer, 66);
	new Task(eTaskIdPlayer, 22);


	

	TaskManager::GetInstance()->Sort();//ソートする
	TaskManager::GetInstance()->DrawAll();
	TaskManager::GetInstance()->UpdateAll();
	TaskManager::GetInstance()->CollisionAll();


	
	/*
	//プレイヤーだけ削除
	Task** players = TaskManager::GetInstance()->FindTaskArray(eTaskIdPlayer);
	if (players != nullptr) {
		for (int i = 0; players[i] != nullptr; i++) {
			players[i]->Delete();
		}
		free(players);//配列の情報を破棄
	}
	*/
	//TaskManager::GetInstance()->DeleteAllTask();


	//タスク検索
	//TaskManager::GetInstance()->FindTask(eTaskIdPlayer)->Delete();
	//TaskManager::GetInstance()->FindTask(eTaskIdPlayer)->Delete();

	//Task* t = head;
	//3つのタスクを追加
	//for (int i = 0; i < 3; i++) {
	//	/*
	//	t->SetNextTask(new Task());
	//	t = t->GetNextTask();
	//	*/
	//	//Task::AddTask(new Task);
	//}


	/*
	t = head;
	while(true) {
		t->Draw();
		t = t->GetNextTask();
		if (t == nullptr) break;
	}
	*/
	

	/*
	double g = (-9.8);
	double v0 = 4.9;//初速度
	double h0 = 29.4;


	int t = 5;//秒数

	//高さを求めるかな

	
	
	for (int i = 0; i <= t; i++) {
		double h = h0 + v0 * i + (g / 2.0) *(i*i);
		printf("%d秒後%lfm\n", i,h);
	}
	*/
	

	getchar();
	getchar();
	return 0;
};