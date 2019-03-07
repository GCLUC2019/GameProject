#include <stdio.h>
#include <iostream>

class Task {
public:
	Task*  pre_point;
	Task*  next_point;
public:
	Task();
	void Draw();
};

Task::Task()
{
	pre_point = NULL;
	next_point = NULL;
}

void Task::Draw()
{
	printf("TaskDraw\n");
}

Task* head;


int main() {
	//�^�X�N�������
	head = new Task();
	//�R�̃^�X�N��ǉ�
	for (int i = 0; i < 3; ++i) {
		Task *t = new Task();
		//�^�X�N���Ȃ���
		Task* search = head;
		while (search->next_point != NULL) {
			search = search->next_point;
		}
		if (search->next_point == NULL) {
			search->next_point = t;
			t->pre_point = search;
		}
	}

	//head����Ō�̃^�X�N��Draw�֐���
	Task *t = head;
	while (t->next_point != NULL){
		t->Draw();
		t = t->next_point;
	}
	t->Draw();

	//float t = 0;
	///*printf("�v���������b������͂��Ă�������");
	//scanf_s("%f", &t);*/
	//float P = 29.4 - 4.9 * t * (t - 1);
	///*printf("%f", P);*/
	//for (int i = 0; i < 6; ++i) {
	//	P = 29.4 - 4.9 * i * (i - 1);
	//	printf("%d�b��%f��\n", i, P);
	//}
	////getchar();

	system("pause");
	return 0;
}

