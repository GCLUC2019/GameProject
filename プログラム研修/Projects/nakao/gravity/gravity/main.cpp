#include <stdio.h>



class Task {
private:
	
	
public:
	Task * old;
	Task * next;
	Task();
	void Doraw();

};


Task::Task(){

}

void Task::Doraw() {
	printf("TaskDoraw\n");
}

int main() {
	Task* head;
	//�^�X�N���ЂƂ���
	head = new Task();
	//�^�X�N��ǉ�
	Task* last = head;
	for (int i = 0; i < 3;++i) {
		Task *t = new Task();
		last->next = t;
		t->old = last;
		last = t;
	}
	last->next = nullptr;
	Task *t = head;
	while (t!=nullptr)
	{
		t->Doraw();
		t = t->next;
	}
	//head����Ō�̃^�X�N��Doraw�֐����Ăяo��




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