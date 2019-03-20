#include "CRectangle.h"
#include "CTask.h"

void CTaskManager::Update(){
	CTask*task = mpHead;
	while (task){
		task->Update();
		task = task->mpNext;
	}
}

void CTaskManager::Render(){
	CTask*task = mpHead;
	while (task){
		task->Render();
		task = task->mpNext;
	}
}

void CTaskManager::Remove(){
	CTask*prev = 0;
	CTask*col = mpHead;
	while (col){
		if (!col->mEnabled){
			if (prev == 0){
				mpHead = col->mpNext;
				delete col;
				col = mpHead;
			}
			else{
				prev->mpNext = col->mpNext;
				delete col;
				col = prev->mpNext;
			}
		}
		else{
			prev = col;
			col = col->mpNext;
		}
	}
	mpTail = prev;
}


CTaskManager*CTaskManager::mpInstance = 0;

CTaskManager*CTaskManager::Get(){
	if (mpInstance == 0){
		mpInstance = new CTaskManager();
	}
	return mpInstance;
}

void CTaskManager::Add(CTask*p){
	if (mpHead == 0){
		mpHead = p;
		mpTail = p;
		mpTail->mpNext = 0;
	}
	else{
		mpTail->mpNext = p;
		mpTail = p;
		mpTail->mpNext = 0;
	}
}

void CTaskManager::Destroy(){
	CTask*col = mpHead;
	while (col){
		mpHead = col->mpNext;
		delete col;
		col = mpHead;
	}
	mpTail = 0;
	delete mpInstance;
	mpInstance = 0;
}
