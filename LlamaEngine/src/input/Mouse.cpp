#include "Mouse.hpp"
#include "../graphics/Window.hpp"
namespace engine {
	namespace input {

		using namespace graphics;
		static void mouseCallback(GLFWwindow* window, int btn, int action, int mods) {
			Mouse* mouse = ((Window*)glfwGetWindowUserPointer(window))->GetInput()->getMouse();
			mouse->button[btn] = action;
		}

		static void mousePosCallback(GLFWwindow* window, double x, double y) {
			Window* win = ((Window*)glfwGetWindowUserPointer(window));
			Mouse* mouse = win->GetInput()->getMouse();
			mouse->mouseX = x;
			mouse->mouseY = win->GetHeight() - y - 1;
		}

		Mouse::Mouse(GLFWwindow* window) : Controller(window) {
			glfwSetMouseButtonCallback(this->window, mouseCallback);
			glfwSetCursorPosCallback(this->window, mousePosCallback);
		}

	}
}