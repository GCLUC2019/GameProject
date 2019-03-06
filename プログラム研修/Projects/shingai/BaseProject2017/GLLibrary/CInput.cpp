#include "GL.h"
#include "CInput.h"

char		CInput::m_key_code[PAD_MAX][eKeyMax] = { 0 };
char		CInput::m_pad_code[PAD_MAX][16] = {
	{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 },
	{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 },
	{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 },
	{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 },
	{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 },
};
unsigned long CInput::m_key_old[PAD_MAX]={0};
unsigned long CInput::m_key_state[PAD_MAX][CInput::eStateMax]={0};
CVector2D CInput::m_mouse_vec;
CVector2D CInput::m_mouse_pos(0, 0);
CVector2D CInput::m_mouse_pos_old(0,0);
int CInput::m_mouse_wheel= 0;
int CInput::m_mouse_wheelOld= 0;
bool CInput::m_mouse_inside = false;


bool CInput::Init(){


	return true;


}

void CInput::SetMouseInside(bool f) {
	m_mouse_inside = f;
	UpdateClipCursor(true);
}
void CInput::UpDate() {
	for (int i = 0; i < PAD_MAX; i++) {
		unsigned long key = 0;
		unsigned long state = 0;
		for (int j = 0; j < eKeyMax; j++) {
			if (::GetKeyState(m_key_code[i][j]) & 0x80) {
				key |= 1 << j;
			}
		}


		m_key_state[i][ePush] = (~m_key_old[i]) & key;
		m_key_state[i][eHold] = m_key_old[i] & key;
		m_key_state[i][ePull] = m_key_old[i] & (~key);
		m_key_state[i][eFree] = (~m_key_old[i]) & (~key);
		m_key_old[i] = key;
	}

	m_mouse_pos_old = m_mouse_pos;
	double x, y;
	glfwGetCursorPos(GL::window, &x, &y);
	m_mouse_pos = CVector2D(x, y);
	m_mouse_vec = m_mouse_pos - m_mouse_pos_old;
	m_mouse_wheelOld = m_mouse_wheel;
	m_mouse_wheel = 0;
	
}

 void CInput::UpdateClipCursor(int f) {
	 if (f && m_mouse_inside) {
		 ClipCursor(&GL::window_rect);
	 } else {
		 ClipCursor(NULL);
	 }

}