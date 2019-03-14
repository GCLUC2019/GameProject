#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif

#define FULL_SCREEN 0
#define GAME_MODE	1


#include "stdafx.h"
#include "Global.h"
#include "../GLLibrary/CFPS.h"
#include "Base\Task.h"
#include "Base\TaskManager.h"
#include "Game\Scene\GameScene.h"

//--------------------------------------------
//グローバル変数領域
//--------------------------------------------
enum PadButton {
	e1,
	e2,
	e3,
	e4,
	e5,
	e6,
	e7,
	e8,
	e9,
	e10,
	e11,
};
void MainLoop(void) {

	//--------------------------------------------------------------
	//ゲーム中の動きはここに書く
	//ゲーム中はこの関数_を1秒間に60回呼び出している
	//--------------------------------------------------------------

    TaskManager::GetInstance()->CheckKillAll();

	TaskManager::GetInstance()->HitCheckAll();

	TaskManager::GetInstance()->UpdateAll();

	TaskManager::GetInstance()->DrawAll();


	

	//速すぎ防止
	//Sleep(rand() % 10);
	Sleep(1);
}
void Init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);

	glEnable(GL_DEPTH_TEST);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);//ブレンドの有効化
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);


	glEnable(GL_ALPHA_TEST);

	//フレームレート設定
	CFPS::SetFPS(60);
	//フレーム制御初期化
	CFPS::Init();
	//ボタンの設定
	CInput::Init();
	CInput::Init();

	/*CInput::SetButton(0, CInput::eUp, 'W');
	CInput::SetButton(0, CInput::eLeft, 'A');
	CInput::SetButton(0, CInput::eDown, 'S');
	CInput::SetButton(0, CInput::eRight, 'D');*/
	//しゃがみ
	CInput::SetButton(0, CInput::eButton1, VK_SHIFT);
	CInput::SetPadButton(0, CInput::eButton1, PadButton::e3);
	//近接攻撃
	CInput::SetPadButton(0, CInput::eButton2, PadButton::e4);
	CInput::SetButton(0, CInput::eButton2, 'Z');
	//ジャンプ
	CInput::SetButton(0, CInput::eButton3,VK_SPACE);
	CInput::SetPadButton(0, CInput::eButton3, PadButton::e1);
	//遠距離攻撃
	CInput::SetPadButton(0, CInput::eButton4, PadButton::e2);
	CInput::SetButton(0, CInput::eButton4, 'X');
	//必殺攻撃
	CInput::SetPadButton(0, CInput::eButton5, PadButton::e8);
	CInput::SetButton(0, CInput::eButton5, 'Q');

	CInput::SetButton(0, CInput::eButton10, VK_RETURN);
	CInput::SetButton(0, CInput::eUp, VK_UP);
	CInput::SetButton(0, CInput::eDown, VK_DOWN);
	CInput::SetButton(0, CInput::eLeft, VK_LEFT);
	CInput::SetButton(0, CInput::eRight, VK_RIGHT);
	CInput::SetButton(0, CInput::eMouseL, VK_LBUTTON);
	CInput::SetButton(0, CInput::eMouseR, VK_RBUTTON);
	CInput::SetButton(0, CInput::eMouseC, VK_MBUTTON);


#ifdef DEBUG
	CInput::SetMouseInside(true);
#endif // DEBUG
	CInput::UpDate();
	CInput::UpDate();



	SetCurrentDirectory("data");

	CSound::GetInstance();

	//-----------------------------------------------------
	//初期化の命令を書く
	//ゲーム起動時に一度だけ呼ばれる
	//-----------------------------------------------------
	new GameScene();

}

void release()
{
	CSound::ClearInstance();
	CResourceManager::ClearInstance();
}
static void ResizeCallback(GLFWwindow* window, int w, int h)
{
	glViewport(0, 0, w, h);


	GL::UpdateWindosRect(GL::window_x, GL::window_y, w, h);

}
static void WheelCallback(GLFWwindow *_window, double _offsetx, double _offsety) {
	CInput::AddMouseWheel((int)_offsety);

}
static void PosCallback(GLFWwindow *_window, int x, int y) {
	GL::UpdateWindosRect(x, y, GL::window_width, GL::window_height);

}
static void FocusCallback(GLFWwindow *_window, int f) {
	CInput::UpdateClipCursor(f);
	GL::focus = f;
}

static void error_callback(int error, const char* description)
{
	printf("Error: %s\n", description);
}

int __main(int* argcp, char** argv) {
	// メモリリーク検出
	//	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF | _CRTDBG_CHECK_ALWAYS_DF);
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


	glfwSetErrorCallback(error_callback);
	if (!glfwInit()) return -1;

	GL::window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Simple", nullptr, nullptr);
	glfwGetWindowSize(GL::window, &GL::window_width, &GL::window_height);
	glfwGetWindowPos(GL::window, &GL::window_x, &GL::window_y);

	glfwSetFramebufferSizeCallback(GL::window, ResizeCallback);
	glfwSetScrollCallback(GL::window, WheelCallback);
	glfwSetWindowFocusCallback(GL::window, FocusCallback);
	glfwSetWindowPosCallback(GL::window, PosCallback);
	if (!GL::window) {
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(GL::window);
	glfwSwapInterval(0);
	ResizeCallback(GL::window, SCREEN_WIDTH, SCREEN_HEIGHT);

	GLenum err = glewInit();
	if (err == GLEW_OK) {
		printf("%s\n", glewGetString(GLEW_VERSION));
	}
	else {
		printf("%s\n", glewGetErrorString(err));
		getchar();
		return -1;
	}
	HDC glDc = wglGetCurrentDC();
	GL::hWnd = WindowFromDC(glDc);


	GL::PrintDeviceInformation();

	Init();



	while (!glfwWindowShouldClose(GL::window)) {

		CInput::UpDate();
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		MainLoop();
		glfwSwapBuffers(GL::window);


		CFPS::Wait();

		char title[32];
		sprintf_s(title, "sample fps:%d dt:%.3f", CFPS::GetFPS(), CFPS::GetDeltaTime());
		glfwSetWindowTitle(GL::window, title);

		glfwPollEvents();
		if (glfwGetKey(GL::window, GLFW_KEY_ESCAPE)) {
			glfwSetWindowShouldClose(GL::window, GL_TRUE);
		}

	}

	glfwTerminate();




	release();
	return 0;
}

INT WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR argv, INT argc)
{
	return __main(&__argc, __argv);
}

int main(int argc, char** argv)
{
	return __main(&argc, argv);
}


