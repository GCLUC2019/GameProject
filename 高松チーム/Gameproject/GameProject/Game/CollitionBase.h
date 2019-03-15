#pragma once
#include "../Base/Task.h"

class CollitionBase  {
private:

protected:

public:
	CollitionBase();
	void Update();

	static bool CollisionCheckRect(Task* b1, int _type);
	static Task* GetCollisionCheckRect(Task* b1, int _type);
	static bool CollitionCheckflip(int fliptype, Task* b1, Task*b2);
};