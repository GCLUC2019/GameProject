#include "CSwitchScreen.h"
#include "../Global.h"

static int s_default_window_pos_x;
static int s_default_window_pos_y;

static bool s_is_fullscreen = false;

void CSwitchScreen::Init()
{
	glfwGetWindowPos(GL::window, &s_default_window_pos_x, &s_default_window_pos_y);
}

void CSwitchScreen::InputSwitchScreen()
{
	if (glfwGetKey(GL::window, GLFW_KEY_LEFT_ALT) == GLFW_PRESS
		&& glfwGetKey(GL::window, GLFW_KEY_ENTER) == GLFW_PRESS) {
		SwitchFullScreen();
	}
}

void CSwitchScreen::SwitchFullScreen()
{
	if (s_is_fullscreen == false) {
		s_is_fullscreen = true;
		glfwSetWindowMonitor(GL::window, glfwGetPrimaryMonitor(), 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 60);
	}
	else {
		s_is_fullscreen = false;
		glfwSetWindowMonitor(GL::window, nullptr, s_default_window_pos_x, s_default_window_pos_y, SCREEN_WIDTH, SCREEN_HEIGHT, 60);
		//glViewport(0, 0, Get_Screen_Width(), Get_Screen_Height());
	}
}
