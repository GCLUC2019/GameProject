#include "stdio.h"



class Task {
public:
	Task * prev;
	Task* next;
	bool killFlag;
	Task();
	void Add(Task *_mp);
	virtual void Draw();
	void DrawAll();
};

class TaskA :public Task {
public:
	TaskA();
	void Draw();
};

Task* head;

int main() {

    head = new Task();
	
	for (int i = 0; i < 3; ++i) {
		head->Add(new TaskA());
	}
	//head����Ō�̃^�X�N��Draw�֐����Ăяo���B
	head->DrawAll();


	/*double v, v0;
	double g, ti;
	double h, h0;
	
	v0 = 4.9;
	h0 = 29.4;
	g = 9.8;

	for (int i = 0; i < 6; i++) {
		ti = i;
		h = h0+(v0*t) - (0.5*g * ti*ti);
		printf("%d�b��F%f���[�g���̍����ɂȂ�܂�\n", i, h);
	}*/
	


	getchar();
	return 0;
}

Task::Task():
prev(nullptr),
next(nullptr)
{
}

void Task::Add(Task  *_mp)
{
	Task *t = _mp;
	Task*p = head;
	while (p->next != nullptr)
	{
		p = p->next;
	}
	
	p->next = t;
	t->prev = p;
	t->killFlag = false;
}

void Task::Draw()
{
	printf("TaskDraw\n");
}

void Task::DrawAll()
{
	Task *t = head;
	while (t) {
		t->Draw();
		t = t->next;
	}
}

TaskA::TaskA()
{
}

void TaskA::Draw()
{
	printf("TaskA\n");
}
