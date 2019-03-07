#include <stdio.h>
#pragma once

class Task {
public:
	Task* mp_prev;
	Task* mp_next;
public:
	Task();
	virtual void Draw();
};


