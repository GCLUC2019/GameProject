#pragma once
#include <stdio.h>
#include "TaskManager.h"

class Task {
private:
	Task *mp_next = nullptr;
	Task *mp_prev = nullptr;


public:
	Task();
	virtual void Update();
	virtual void Draw();
	
	Task *GetNext() { return mp_next; }
	Task *GetPrev()   { return mp_prev; }
	void SetNext(Task *_var) { mp_next = _var; }
	void SetPrev(Task *_var)   { mp_prev = _var; }

};