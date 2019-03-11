#include <stdio.h>
#include <iostream>
//#include <string>
#include <list>

class Task{
public:
	Task *mp_next;
public:
    Task();
    void Draw();
};

Task::Task() : mp_next(nullptr){
}
void Task::Draw(){
    printf("TaskDraw\n");
}
class TaskManager {
private:
	Task* head;
	static TaskManager* instance;
public:
	TaskManager();
	//static TaskManager* GetInstance();
	//static void ClearInstance();
	void DrawAll();
	//void UpdateAll();
	void Add(Task *t);
	void Delete(Task *t);

};
TaskManager* TaskManager::instance=nullptr;

TaskManager::TaskManager() :head(nullptr){


}

//TaskManager* TaskManager::GetInstance(){
//
//
//}

//TaskManager::ClearInstance(){
//
//
//}

void TaskManager::DrawAll(){
	//headから最後のタスクのDraw関数を呼び出す
	Task*t = head;
	while (t)
}
void TaskManager::Add(Task *t){
	Task*n = head;
	//末尾のタスクまで進める
	while (n->mp_next){
		n = n->mp_next;
	}
	//タスクをつなげる


}
void TaskManager::Delete(Task *t){

}
class A : public Task{
public:
	void Draw();
};
void A::Draw(){
	printf("ADraw\n");
}

Task* head;

using namespace std;

int main(){
	//float v0, h0, g;
	//int h;
	//v0 = 4.9;
	//h0 = 29.4;
	//g = 9.8;
	//
	//for (int i = 0; i < 4; i++){
	//	if (h = h0 + v0 * i + 0.5 * (-g) *i*i);
	//	cout << i <<"秒後の高さは" << h << "\n";
	//}
	//タスクを1つ生成
	head = new Task();

	//3つのタスクを追加
	for (int i = 0;i < 3; ++i){
		Task *t = new A();
		Task *n = head;
		//タスクをつなげる
		while (n->mp_next){
			n = n->mp_next;
		}
		n->mp_next = t;
	}

	//headから最後のタスクのDraw関数を呼び出す
	Task *t = head;
	while (t){
		t->Draw();
		t = t->mp_next;
	}

	system("pause");
	return 0;
}