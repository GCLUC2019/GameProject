#pragma once
#include "../../Base/Task.h"
/*担当
　国見　class Tutorial 
*/

class Tutorial : public Task {
private:
protected:
public:
	Tutorial();
	void Draw();
	void Update();
	/*
	　@brief　チュートリアル用説明UI
	*/
	void DescriptionUI();


};