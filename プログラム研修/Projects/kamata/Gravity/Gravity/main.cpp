#include<stdio.h>
#include<iostream>
using namespace std;

//int main(){
//	float h=0;
//	int t=0;
//
//	for (t = 0; t <= 5; t += 1) {
//		h = 29.4 + 4.9*t + 0.5*((-9.8)*(t * 2));
//		cout <<t<< "�b���"<<h<<"m" << endl;
//	}
//
//	system("pause");
//	return 0;
//}

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
	static TaskManager*instrance;
public:
	TaskManager();

	void DrawAll();
	void Add(Task*t);
	void Delete(Task*t);
};
TaskManager*TaskManager = nullptr;

TaskManager::TaskManager() {
}

void TaskManager::Add(Task*t){

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
	//�^�X�N��1����
	head = new Task();

	//3�̃^�X�N��ǉ�
	for (int i = 0; i < 3; ++i){
		Task*t = new A();
		Task*n = head;
		//�����̃^�X�N�܂Ői�߂�
		while (n->mp_next){
			n = n->mp_next;
		}
		n->mp_next = t;
		//Task*t = new Task();
		//�^�X�N���q����
	}

	//head����Ō�̃^�X�N��Draw�֐����Ăяo��
	Task*t = head;
	while(t){
		t->Draw();
		t = t->mp_next;
	}

	system("pause");
	return 0;
}