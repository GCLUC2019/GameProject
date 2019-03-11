#pragma once

enum Weigh
{
	w_eBack = 0,
	w_eObj = 100,
	w_eUI = 200,
};
enum Type
{
	eBack,
	eObj,
	eUI,
	e_TypeMax,
};
class Task {
protected:
	int m_type;
	Task * m_prev;
	Task* m_next;
	int m_S_Weigh;
public:
	Task();
	Task(int _m_S_Weigh, int _m_type);

	Task * GetPrev() {
		return m_prev;
	}
	Task* GetNext() {
		return m_next;
	}
	void SetPrev(Task * p) {
		m_prev = p;
	}
	void SetNext(Task * n) {
		m_next = n;
	}
	void SetWeigh(int Weigh) {
		m_S_Weigh = Weigh;
	}
	void PlusWeigh(int Weigh) {
		m_S_Weigh += Weigh;
	}
	void MinusWeigh(int Weigh) {
		m_S_Weigh -= Weigh;
	}

	int GetWeigh() {
		return m_S_Weigh;
	}
	
	virtual void Draw();
	virtual ~Task();
};
