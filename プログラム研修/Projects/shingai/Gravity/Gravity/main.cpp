#include <stdio.h>

/*
���H���
5�b�ԕ������̃V�~�����[�V�������s��
�����x 4.9m/s
�������� 29.4m
�d�� 9.8m/s


*/
#include "Task.h"
#include "TaskManager.h"

class A : public Task {
private:
public:
	A();
	void Draw();
};

A::A() : Task(eTaskManagerIdGeneral,eTaskIdNone,1,2){

}

void A::Draw() {
	printf("A�N���X Draw\n");
}



//Task* head;

int main() {
	//�^�X�N��1����
	//head = new Task;


	new A();
	
	//Task* p = new Task();
	//p->SetTaskId(eTaskIdPlayer);

	new Task(eTaskManagerIdGeneral,eTaskIdPlayer,0,1);
	new Task(eTaskManagerIdGeneral, eTaskIdPlayer,4,2);

	Task* t[4];

	for (int i = 0; i < 4; i++) {
		t[i] = new Task(eTaskManagerIdGeneral,eTaskIdNone,6,3);
		//Task::AddTask(new Task);
	}

	TaskManager::GetTaskManagerPointer(eTaskManagerIdGeneral)->DrawAllSort();
	TaskManager::GetTaskManagerPointer(eTaskManagerIdGeneral)->UpdateAllSort();

	
	//�^�X�N����
	TaskManager::GetTaskManagerPointer(eTaskManagerIdGeneral)->FindTask(eTaskIdPlayer)->Delete();
	TaskManager::GetTaskManagerPointer(eTaskManagerIdGeneral)->FindTask(eTaskIdPlayer)->Delete();


	


	//�^�X�N�폜
	for (int i = 0; i < 3; i++) {
		t[i]->Delete();
	}

	TaskManager::GetTaskManagerPointer(eTaskManagerIdGeneral)->DrawAll();

	//Task* t = head;
	//3�̃^�X�N��ǉ�
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
	double v0 = 4.9;//�����x
	double h0 = 29.4;


	int t = 5;//�b��

	//���������߂邩��

	
	
	for (int i = 0; i <= t; i++) {
		double h = h0 + v0 * i + (g / 2.0) *(i*i);
		printf("%d�b��%lfm\n", i,h);
	}
	*/
	

	getchar();
	getchar();
	return 0;
};