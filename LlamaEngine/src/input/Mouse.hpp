#pragma once
#include <GLFW/glfw3.h>
#include "Controller.hpp"
#include "KeyCode.hpp"
namespace engine {
	namespace input {

		class Mouse : public Controller {
		public:
			Mouse(GLFWwindow* window);
			double mouseX, mouseY;
		};

	}
}