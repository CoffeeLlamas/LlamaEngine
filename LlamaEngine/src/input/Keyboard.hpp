#pragma once
#include <GLFW/glfw3.h>
#include "Controller.hpp"
namespace engine {
	namespace input {

		class Keyboard : public Controller {
		public:
			Keyboard(GLFWwindow* window);
		};

	}
}