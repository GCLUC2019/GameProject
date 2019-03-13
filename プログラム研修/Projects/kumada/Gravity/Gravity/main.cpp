#include<iostream>
#include<stdint.h>
#include<list>

//std::list<int> list;

using namespace std;

//int main() {
//	
//	
//	float v0, h0, g, v;
//	int t,h;
//	v0 = 4.9;
//	h0 = 29.4;
//	g = 9.8;
//
//
//	for (int t = 0; t < 6; t++) {
//		if (h = h0 + v0 * t + 0.5 * (-g)*t*t);
//		cout << t << "秒後の高さは" <<h<< "\n";
//	}
//	
//	
//	//getchar();
//	system("pause");
//	return 0;
//
//	
//	
//
//	
//
//
//}
class Task {
public:
	Task*mp_next;

public:
	Task();
	virtual void Draw();

};
Task::Task() :mp_next(nullptr) {

}
void Task::Draw() {
	printf("TaskDraw\n");
}

class TaskManager {
private:
	Task*head;
	static TaskManager*instance;
public:
	TaskManager();
	static TaskManager*GetInstance();
	static void ClearInstance();
	
	void DrawAll();
	void Add(Task*t);
	void Delete();
};
TaskManager*TaskManager::instance = nullptr;

TaskManager::TaskManager() :head(nullptr) {

}

//TaskManager*TaskManager::GetInstance {
//	//if (instance = nullptr) instance = new TaskManeger();
//    return instance;
//}
void TaskManeger::ClearInstance() {
	if (instance = nullptr) return;
	delete instance;
}


void TaskManager::DrawAll() {

}
void TaskManager::Add(Task*t) {

}
void TaskManager::Delete() {

}


class A :public Task {
public:
	void Draw();
};
void A::Draw() {
	printf("ADraw\n");
}

Task*head;
int main() {
	TaskManager  m;
	m.Add(new Task());

	//タスクを1つ生成
	head = new Task();
	//3つのタスクを追加
	for (int i = 0; i < 3; ++i) {
		Task*t = new A();
		Task*n = head;
		//タスクをつなげる
		while (n->mp_next) {
			n = n->mp_next;

		}
		n->mp_next = t;
	}
	//headから最後のタスクのDraw関数を呼び出す
	Task*t = head;
	while (t) {
		t->Draw();
		t = t->mp_next;
	}

	system("pause");
	return 0;
}
