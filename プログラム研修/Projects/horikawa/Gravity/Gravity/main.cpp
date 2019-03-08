#include <stdio.h>
#include <iostream>
#include "Task.h"
#include "TaskManager.h"



class A :public Task {
public:
	void Draw();
};
void A::Draw()
{
	printf("ADraw%d\n", m_id);
}

//Task* head;

int main() {
	//タスクを一つ生成
	/*head = new Task();*/

	//３つのタスクを追加
	for (int i = 0; i < 3; ++i) {
		new A();
		////タスクをつなげる
		//Task *search = head;
		//while (search->mp_next) {
		//	search = search->mp_next;
		//}
		//search->mp_next = t;
		//t->mp_prev = search;
	}

	A* d = new A();
	TaskManager::GetInstance()->Delete(d);

	//headから最後のタスクのDraw関数を呼び出す
	TaskManager::GetInstance()->DrawAll();


	
	SearchID* b = TaskManager::GetInstance()->Search(6);
	while (b->s_next) {
		b = b->s_next;
		TaskManager::GetInstance()->Delete(b->s_point);
	}
	
	//headから最後のタスクのDraw関数を呼び出す
	TaskManager::GetInstance()->DrawAll();





	/*Task *t = head;
	while (t->mp_next){
		t->Draw();
		t = t->mp_next;
	}
	t->Draw();*/

	//float t = 0;
	/*printf("計測したい秒数を入力してください");
	scanf_s("%f", &t);*/
	//float P = 29.4 - 4.9 * t * (t - 1);
	///*printf("%f", P);*/
	//for (int i = 0; i < 6; ++i) {
	//	P = 29.4 - 4.9 * i * (i - 1);
	//	printf("%d秒後%fｍ\n", i, P);
	//}
	////getchar();

	system("pause");
	return 0;
}

