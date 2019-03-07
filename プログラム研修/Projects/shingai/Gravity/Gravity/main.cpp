#include <stdio.h>

/*
実践問題
5秒間放物線のシミュレーションを行う
初速度 4.9m/s
初期高さ 29.4m
重力 9.8m/s


*/

class Task;
static Task* head_task = nullptr;

class Task {
private:
	Task * m_next_task = nullptr;
public:
	Task();
	void Draw();
	static void DrawAll();
	void SetNextTask(Task* _next) { m_next_task = _next; };
	Task* GetNextTask() { return m_next_task; };
	static Task* GetHead(){return head_task; };
	static void AddTask(Task* _task) {
		if (head_task == nullptr) {
			head_task = _task;
			return;
		}

		Task* t = head_task;
		while (true) {
			if (t->GetNextTask() != nullptr) {
				t = t->GetNextTask();
			}
			else {
				t->SetNextTask(_task);
				break;
			}
		}
		
	}
};


void Task::DrawAll() {
	Task* t = Task::GetHead();
	while (true) {
		t->Draw();
		t = t->GetNextTask();
		if (t == nullptr) break;
	}
}


Task::Task() {
	Task::AddTask(this);
}


void Task::Draw() {
	printf("TaskDraw\n");
}


Task* head;

int main() {
	//タスクを1つ生成
	//head = new Task;


	for (int i = 0; i < 4; i++) {
		new Task();
		//Task::AddTask(new Task);
	}

	Task::DrawAll();
	

	//Task* t = head;
	//3つのタスクを追加
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
	double v0 = 4.9;//初速度
	double h0 = 29.4;


	int t = 5;//秒数

	//高さを求めるかな

	
	
	for (int i = 0; i <= t; i++) {
		double h = h0 + v0 * i + (g / 2.0) *(i*i);
		printf("%d秒後%lfm\n", i,h);
	}
	*/
	

	getchar();
	getchar();
	return 0;
};