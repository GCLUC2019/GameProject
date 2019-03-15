
//§ì‘O‰ª

#include"Task.h"

//#include"CTexture.h"

class CMap :public Task{
public:
	
	enum EScneMap
	{
		EStat,
		EMap1,
		EMap2,
		EMap3,
		EEnd,

	};

	EScneMap mScneMap;
	virtual ~CMap(){}
	virtual void Init(){}
	virtual void Update(){}
};
