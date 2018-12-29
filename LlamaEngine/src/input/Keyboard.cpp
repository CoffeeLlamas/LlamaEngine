#include <GLFW/glfw3.h>
#include "Keyboard.hpp"
#include "../graphics/Window.hpp"
#include "KeyCode.hpp"
#include <iostream>
namespace engine {
	namespace input {

		using namespace graphics;
		static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
			if (action == 2) return;
			Window* win = ((Window*)glfwGetWindowUserPointer(window));
			Keyboard* kb = win->GetInput()->getKeyboard();
			kb->button[key] = (action == BTN_RELEASE ? -win->GetNow() : win->GetNow());
		}
		
		Keyboard::Keyboard(GLFWwindow* window) : Controller(window) {
			glfwSetKeyCallback(this->window, keyCallback);
		}

	}
}