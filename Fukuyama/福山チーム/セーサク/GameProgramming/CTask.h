#ifndef CTASK_H
#define CTASK_H

class CTask{
public:
	bool mEnabled;
	CTask()
		:mEnabled(true)
	{}
	enum ETaskTag{
		EPLAYERTANK,
		EENEMYTANK,
		EPLAYERBULLET,
		EENEMYBULLET,
		EARROW,
		EENEMY1,
		EITEM,

	};
	ETaskTag mTaskTag;
	CTask*mpNext;
	virtual void Init(){};
	virtual void Update(){};
	virtual void Render(){};
	virtual void Remove(){};
};

class CTaskManager{
private:
	static CTaskManager*mpInstance;
	CTask*mpHead;
	CTask*mpTail;
	CTaskManager()
		:mpHead(0)
		, mpTail(0)
	{}
public:
	static CTaskManager*Get();
	void Add(CTask*p);
	void Update();
	void Render();
	void Remove();
	void Destroy();
};

#endif