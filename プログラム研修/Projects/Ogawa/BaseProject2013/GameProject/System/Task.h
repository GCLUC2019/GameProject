/**
* @Brief	タスクシステム基底
*/

#ifndef TASK_GUARD
#define TASK_GUARD

#include "TaskLinker.h"
#include "../GID.h"

class Task
{
protected:
	TaskLinker m_updateLink;				//更新用リンク 
	TaskLinker m_renderLink;				//描画用リンク 
	int		   m_id;						//タスクID
	bool	   m_destroyFlg;				//削除フラグ

public:
	Task();						    
	Task(int id, int updateprio, int renderPrio);
	virtual ~Task();
	virtual void Update(float delta_time);
	virtual void Render();					//派生先で描画
	void ChangeUpdatePrio(int updatePrio);	//更新順位変更
	void ChangeRenderPrio(int renderPrio);	//描画順位変更
								
	void SetKill()							//削除フラグON 
	{
		m_destroyFlg = true;
	}

	inline int GetUpdatePrio() const		//更新順位取得関数
	{
		return m_updateLink.GetPriority();
	}

	inline int GetRenderPrio() const		//描画順位取得関数
	{
		return m_renderLink.GetPriority();
	}

	inline int GetID() const				//タスクID取得 
	{
		return m_id; 
	}

	friend class TaskManager;
};

#endif