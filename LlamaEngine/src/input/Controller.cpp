#include "Controller.hpp"
#include "../graphics/Window.hpp"
#include <iostream>
namespace engine {
	namespace input {

		using namespace graphics;
		Controller::Controller(GLFWwindow* window) {
			this->window = window;
			for (int i = 0; i < 512; i++)
				this->button[i] = -0.1f;
		}

		bool Controller::btnDown(int btn) {
			return this->button[btn] > 0;
		}

		bool Controller::btnUp(int btn) {
			return this->button[btn] < 0;
		}

		bool Controller::btnJustDown(int btn) {
			
			return this->button[btn] == ((Window*) glfwGetWindowUserPointer(window))->GetNow();
		}

		bool Controller::btnJustUp(int btn) {
			return this->button[btn] == -((Window*) glfwGetWindowUserPointer(window))->GetNow();
		}

	}
}