//放物線シミュレーション
#include <stdio.h>
#include "Task.h"
#include "TaskManager.h"

class A : public Task  {
private:

public:
	void Draw();
};
void A::Draw() {
	printf("A Draw\n");
}


int main()
{
	//Task::LinkDraw(new A(), 5);
	////タスクを一つ生成
	//head = new Task();

	TaskManager::AddTask(new A());
	//TaskManager::AddTask(new Task());
	////3つのタスクを追加
	for (int i = 0; i < 5; ++i) {
		TaskManager::GetInstance()->DrawAll();
	//	t[i] = TaskManager::Add(Task());
	}
	


	////headから最後のタスクのDraw関数を呼び出す
	//Task *t = head;
	//while (t) {
	//	t->Draw();
	//	t = t->GetSearch();
	//}

	//t = last;
	//while (t) {
	//	t->Draw();
	//	t = t->GetPrev();
	//}


	getchar();
	return 0;
}