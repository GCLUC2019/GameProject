#include<stdio.h>
#include<iostream>

class Task{
public:
	Task*mp_next;
public:
	Task();
	virtual void Draw();
};

Task::Task() :mp_next(nullptr){
}

void Task::Draw(){
	printf("TaskDraw\n");
}
class A :public Task{
public:
	void Draw();
};

void A::Draw(){
	printf("ADraw\n");
}

Task*head;

using namespace std;

int main(){
	//�^�X�N��1�쐬
	head = new Task();

	//3�̃^�X�N��ǉ�
	for (int i = 0; i < 3; ++i){
		Task*t = new A();
		Task*n = head;
		//�����̃^�X�N�܂Ői�߂�
		while(n->mp_next){
			n = n->mp_next;
		}
		//�^�X�N���Ȃ���
		n->mp_next = t;
	}
	//head����Ō�̃^�X�N��Draw�֐����Ăяo��
	Task*t = head;
	while (t){
		t->Draw();
		t = t->mp_next;
	}
		system("pause");
		return 0;


	string input;
	//getchar();

	/*
	int V0 = 4.9;
	int H0 = 29.4;
	int Gravity = 9.8;
	int H;
	int t;

	for (int t = 0; t < 6; t++){
		H = H0 + V0*t + 0.5 * (-Gravity)*t*t; {
			cout << H << "\n";
		}
	}

	system("pause");
	return 0;
	*/
}