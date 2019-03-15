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
<<<<<<< HEAD
=======
		ESPEEDENEMY,
		EBOSSBULLET,
		EARROW,
		EENEMY1,      //’Ç‰Á@Š˜“c
		EENEMY2,
		EITEM,


>>>>>>> 7b7833fccc61631035d5b5e9c0ad3425b18ce63d
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