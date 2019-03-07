#include <stdio.h>

/*
���H���
5�b�ԕ������̃V�~�����[�V�������s��
�����x 4.9m/s
�������� 29.4m
�d�� 9.8m/s


*/

class Task;
static Task* head_task = nullptr;

class Task {


private:
	Task * m_next_task = nullptr;
public:
	Task();
	void Draw();
	void SetNextTask(Task* _next) { m_next_task = _next; };
	Task* GetNextTask() { return m_next_task; };
	static Task* GetHead(){return head_task; };
	static void AddTask(Task* _task) {
		if (head_task == nullptr) {
			head_task = _task;
			return;
		}
	}
};



Task::Task() {
	
}


void Task::Draw() {
	printf("TaskDraw\n");
}


Task* head;

int main() {
	//�^�X�N��1����
	head = new Task;

	Task* t = head;
	//3�̃^�X�N��ǉ�
	for (int i = 0; i < 3; i++) {
		t->SetNextTask(new Task());
		t = t->GetNextTask();
	}

	t = head;
	for (int i = 0; i < 4;i++) {
		t->Draw();
		t = t->GetNextTask();
	}
	

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