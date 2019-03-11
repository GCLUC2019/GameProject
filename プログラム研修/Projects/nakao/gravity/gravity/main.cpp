#include <stdio.h>
#include"Task/Task.h"
#include"Task/TaskManager.h"

#define T_MN TaskManager
#define T_AD(n) TaskManager::Add(n)
#define T_ADF(n) TaskManager::Addf(n)


class A :public Task {
private:

public:
	A();
	void Draw();
};

A::A():Task()
{
	
}

void A::Draw() {
	printf("A_%d\n",m_S_Weigh);
}

int main() {
	
	//タスクをひとつ生成
	T_AD(new Task());
	//タスクを追加
	
	for (int i = 0; i < 5;++i) {
		T_AD(new Task(i, eBack));
	/*
		Task *t = new A();
		Task* n = head;
		while ( n->GetNext() != nullptr) {
			n = n->GetNext();
		}
		n->SetNext(t);
		t->SetPrev(n);
		last = t;*/
		/*last->next = t;
		t->old = last;
		last = t;*/
	}
	
	
	//headから最後のタスクまでのDoraw関数を呼び出す
	T_MN::DrawAll(T_MN::GetHead() , true);
	printf("\n終了\n\n");
	//TaskManager::Swap(TaskManager::GetLast()->GetPrev(), TaskManager::GetHead()->GetNext());
	T_MN::Exclusion(T_MN::GetHead()->GetNext());
	T_MN::DrawAll(T_MN::GetHead(), true);
	printf("\n終了\n\n");
	T_MN::Exclusion(T_MN::GetHead());
	T_MN::Exclusion(T_MN::GetLast());
	T_AD(new A());
	//T_ADF(new Task(10));
	T_MN::DrawAll(T_MN::GetHead()->GetNext()->GetNext(), true);

	//float Gravity = -9.8;
	//float spd, spd_0, h, h_0;
	//int time;

	//spd_0 = 4.9;
	//h_0 = 29.4;
	//for (time = 0; time < 5; time++) {
	//	h = h_0 + spd_0 * time + Gravity * (time*time) / 2;
	//	printf("%d秒後%.5f\n",time,h);	
	//}
	//

	
	printf("\n終了\n");
	T_MN::ExclusionDelete();
	getchar();
	return 0;
}