#pragma once

//起動時の処理

class CLoadResorce {
private:
	bool m_is_loaded = false;
public:
	CLoadResorce();
	static CLoadResorce* GetInstance();
	void LoadResorce();
	void ReadResorceFile(char* _file_path);
};