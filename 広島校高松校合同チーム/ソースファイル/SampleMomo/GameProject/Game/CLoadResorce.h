#pragma once

//�N�����̏���

class CLoadResorce {
private:
	bool m_is_loaded = false;
public:
	CLoadResorce();
	static CLoadResorce* GetInstance();
	void LoadResorce();
};