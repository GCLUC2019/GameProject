//�������V�~�����[�V����
#include <stdio.h>
#include "Task.h"

class A : public Task  {
private:

public:
	void Draw();
};
void A::Draw() {
	printf("ADraw\n");
}




int main() 
{
	Task::LinkDraw(new A(), 5);
	////�^�X�N�������
	//head = new Task();

	////3�̃^�X�N��ǉ�
	//for (int i = 0; i < 5; ++i) {
	//	
	//	
	//	
	//	

	////head����Ō�̃^�X�N��Draw�֐����Ăяo��
	//Task *t = head;
	//while (t) {
	//	t->Draw();
	//	t = t->GetSearch();
	//}

	//t = last;
	//while (t) {
	//	t->Draw();
	//	t = t->GetPrev();
	//}


	getchar();
	return 0;
}