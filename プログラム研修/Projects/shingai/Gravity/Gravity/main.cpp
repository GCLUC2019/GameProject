#include <stdio.h>

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
	printf("Aクラス Draw\n");
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

	Task* t[4];

	for (int i = 0; i < 4; i++) {
		t[i] = new Task(eTaskIdNone,6);
		//Task::AddTask(new Task);
	}

	TaskManager::GetInstance()->DrawAll();
	TaskManager::GetInstance()->UpdateAll();

	
	//タスク検索
	TaskManager::GetInstance()->FindTask(eTaskIdPlayer)->Delete();
	TaskManager::GetInstance()->FindTask(eTaskIdPlayer)->Delete();


	


	//タスク削除
	for (int i = 0; i < 3; i++) {
		t[i]->Delete();
	}

	TaskManager::GetInstance()->DrawAll();

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