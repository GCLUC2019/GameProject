#include<stdio.h>
#include<iostream>
#include<list>

using namespace std;

class Task{
public:
	Task*mp_next;
public:
	Task();
	virtual void Draw();
};
Task::Task():mp_next(nullptr){
}

void Task::Draw(){
	printf("TaskDraw\n");
}

class TaskManager{
private:
	Task*head;
	static TaskManager*instance;
public:
	TaskManager();
	void DrawAll();
	void Add(Task*t);
	void Delete(Task*t);

};

TaskManager::TaskManager(){

}

class A :public Task{
public:
	void Draw();
};

void A::Draw(){
	printf("ADraw\n");
}


Task*head;

int main(){
	//�^�X�N���P����
	head = new Task();

	//�R�̃^�X�N��ǉ�
	for (int i = 0; i < 3; ++i){
		Task*t = new A();
		Task*n = head;
		//�����̃^�X�N�܂Ői�߂�
		while (n->mp_next){
			n = n->mp_next;
		}
		n->mp_next = t;
		//�^�X�N���Ȃ���

	}

	//head����Ō�̃^�X�N��Draw�֐����Ăяo��
	Task*t = head;
	while (t){
		t->Draw();
		t = t->mp_next;
	}
	system(" pause");
	return 0;
	
}


