#include <stdio.h>
#include"Task/Task.h"
#include"Task/TaskManager.h"






//class A :public Task {
//private:
//
//public:
//	void Draw();
//};
//
//void A::Draw() {
//	printf("ADraw\n");
//}

int main() {
	
	//�^�X�N���ЂƂ���
	TaskManager::Add(new Task());
	//�^�X�N��ǉ�
	
	for (int i = 0; i < 5;++i) {
		TaskManager::Addf(new Task(i));
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
	
	
	//head����Ō�̃^�X�N�܂ł�Doraw�֐����Ăяo��
	TaskManager::DrawAll(TaskManager::GetHead() , true);
	printf("\n�I��\n\n");
	TaskManager::Swap(TaskManager::GetLast()->GetPrev(), TaskManager::GetHead()->GetNext());
	 TaskManager::DrawAll(TaskManager::GetHead(), true);
	//float Gravity = -9.8;
	//float spd, spd_0, h, h_0;
	//int time;

	//spd_0 = 4.9;
	//h_0 = 29.4;
	//for (time = 0; time < 5; time++) {
	//	h = h_0 + spd_0 * time + Gravity * (time*time) / 2;
	//	printf("%d�b��%.5f\n",time,h);	
	//}
	//

	
	printf("\n�I��\n");
	getchar();
	return 0;
}