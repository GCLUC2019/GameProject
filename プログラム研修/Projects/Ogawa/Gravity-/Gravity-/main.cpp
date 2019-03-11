#include<stdio.h>
#include<iostream>

class Task{
public:
	Task*mp_next;
public:
	Task();
	virtual void Draw();
	virtual void Delete();
};

Task::Task() :mp_next(nullptr){
}

void Task::Draw(){
	printf("TaskDraw\n");
}
void Task::Delete(){
	printf("TaskDelete\n");
}

class TaskManager{
private:
	Task*head;
	static TaskManager*instance;
public:
	TaskManager();
	static TaskManager*GetInstance();
	static void ClearInstance();

	void DrawAll();
	void Add(Task*t);
	void DeleteAll(Task*t);
};
TaskManager*TaskManager::instance = nullptr;

TaskManager::TaskManager() :head(nullptr){
}

TaskManager*TaskManager::GetInstance(){
	if (instance == nullptr)instance = new TaskManager();
	return instance;
}
void TaskManager::ClearInstance(){
	if (instance == nullptr)return;
	delete instance;
}
void TaskManager::DrawAll(){
	//headから最後のタスクのDraw関数を呼び出す
	Task*t = head;
	while (t){
		t->Draw();
		t = t->mp_next;
	}
}

void TaskManager::Add(Task*t){

}

void TaskManager::DeleteAll(Task*t){

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
	TaskManager m;
	m.Add(new Task());
	//タスクを1つ作成

	//3つのタスクを追加
	for (int i = 0; i < 3; ++i){
		m.Add(new A());
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