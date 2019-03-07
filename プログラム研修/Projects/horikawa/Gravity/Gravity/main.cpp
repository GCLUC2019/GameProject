#include <stdio.h>
#include <iostream>

class Task {
public:
	Task*  pre_point;
	Task*  next_point;
public:
	Task();
	void Draw();
};

Task::Task()
{
	pre_point = NULL;
	next_point = NULL;
}

void Task::Draw()
{
	printf("TaskDraw\n");
}

Task* head;


int main() {
	//タスクを一つ生成
	head = new Task();
	//３つのタスクを追加
	for (int i = 0; i < 3; ++i) {
		Task *t = new Task();
		//タスクをつなげる
		Task* search = head;
		while (search->next_point != NULL) {
			search = search->next_point;
		}
		if (search->next_point == NULL) {
			search->next_point = t;
			t->pre_point = search;
		}
	}

	//headから最後のタスクのDraw関数を
	Task *t = head;
	while (t->next_point != NULL){
		t->Draw();
		t = t->next_point;
	}
	t->Draw();

	//float t = 0;
	///*printf("計測したい秒数を入力してください");
	//scanf_s("%f", &t);*/
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

