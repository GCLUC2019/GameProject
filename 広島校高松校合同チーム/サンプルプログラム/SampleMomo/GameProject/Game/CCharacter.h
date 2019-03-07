#pragma once
#include "CObject.h"

class CCharacter : public CObject {
private:
protected:
public:
	CCharacter(int _id,int _up,int _rd);
	virtual ~CCharacter();
	virtual void Update(float delta_time);
	virtual void Render();
};