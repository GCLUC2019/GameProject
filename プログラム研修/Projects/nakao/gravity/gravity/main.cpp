#include <stdio.h>



class Task {
private:
	Task * prev;
	Task* next;
public:
	Task * GetPrev() {
		return prev;
	}
	Task* GetNext() {
		return next;
	}
	void SetPrev(Task * p) {
		prev = p;
	}
	void SetNext(Task * n) {
		next = n;
	}
	Task();
	virtual void Draw();

};


Task::Task():
	prev(nullptr),
next(nullptr)
{

}
void Task::Draw() {
	printf("TaskDraw\n");
}

class A :public Task {
private:

public:
	void Draw();
};

void A::Draw() {
	printf("ADraw\n");
}

class TaskManager {
private:
	static Task * head;
	
public:
	TaskManager();
	static void Addf(Task* t);
	static void Add(Task* t);

	static void DrawAll(Task* t,bool f);
};
TaskManager::TaskManager()
{
}
void TaskManager:: Addf(Task* t) {
	
}

void TaskManager::Add(Task* t) {
	if (head == nullptr) {
		head = t;
		return;
	}
	Task* n = head;
	while (n->GetNext() != nullptr) {
		n = n->GetNext();
	}
	;
	n->SetNext(t);
	t->SetPrev(n);
}
void TaskManager::DrawAll(Task* t, bool f) {
	if (f) {
		while (t->GetPrev() != nullptr) {
			t = t->GetPrev();
		}
		while (t) {
			t->Draw();
			t = t->GetNext();
		}
	}
	else {
		while (t->GetNext() != nullptr) {
			t = t->GetNext();
		}
		while (t) {
			t->Draw();
			t = t->GetPrev();
		}
	}

}
Task* head;
Task* last;
int main() {
	head;
	//タスクをひとつ生成
	head = new Task();
	//タスクを追加
	last = head;
	for (int i = 0; i < 3;++i) {
		TaskManager::Add(new A);
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
	Task *t = head;
	TaskManager::DrawAll(t, true);
	printf("\n終了\n\n");
	 t = last;
	 TaskManager::DrawAll(t, false);
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
	getchar();
	return 0;
}