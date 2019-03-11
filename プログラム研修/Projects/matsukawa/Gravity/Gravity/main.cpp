#include "stdio.h"
#include "TaskManagement.h"
#include "TaskManager.h"
#include "Task.h"
#include "TaskA.h"

//TaskManager* head;


int main() {
	
	for (int i = 0; i < 3; ++i) {
	/*	TaskManager::GetInstance()->AddTask(new TaskA());*/
		TaskManagement::GetIns()->Add(new TaskA());
	}
	for (int i = 0; i < 4; ++i) {
		/*TaskManager::GetInstance()->AddTask(new Task());*/
		TaskManagement::GetIns()->Add(new Task());
	}
	for (int i = 0; i < 3; ++i) {
	/*	TaskManager::GetInstance()->AddTask(new TaskA());*/
		TaskManagement::GetIns()->Add(new TaskA());
	}
	for (int i = 0; i < 4; ++i) {
	/*	TaskManager::GetInstance()->AddTask(new Task());*/
		TaskManagement::GetIns()->Add(new Task());
	}

	//headから最後のタスクのDraw関数を呼び出す。
	/*TaskManager::GetInstance()->UpdateAll();
	TaskManager::GetInstance()->DrawAll();
	TaskManager::GetInstance()->KillAll();
	TaskManager::GetInstance()->DrawAll();*/
	TaskManagement::GetIns()->UpdateAll();
	TaskManagement::GetIns()->DrawAll();
	printf("\n");
	TaskManagement::GetIns()->DrawTailAll();
	//TaskManagement::GetIns()->KillFlagAll();
	//TaskManagement::GetIns()->FlagKill();
	TaskManagement::GetIns()->KillAll();
	
	printf("終了\n");

	/*double v, v0;
	double g, ti;
	double h, h0;
	
	v0 = 4.9;
	h0 = 29.4;
	g = 9.8;

	for (int i = 0; i < 6; i++) {
		ti = i;
		h = h0+(v0*t) - (0.5*g * ti*ti);
		printf("%d秒後：%fメートルの高さになります\n", i, h);
	}*/
	


	getchar();
	return 0;
}






