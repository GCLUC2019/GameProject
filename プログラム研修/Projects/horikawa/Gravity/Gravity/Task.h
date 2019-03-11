#pragma once
#include <stdio.h>
#include "TaskManager.h"

class Task {
public:
	Task* mp_prev;
	Task* mp_next;

	int m_id;

public:
	Task();
	virtual void Draw();
};