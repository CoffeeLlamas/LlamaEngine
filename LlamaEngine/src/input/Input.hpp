#pragma once
#include <GLFW/glfw3.h>
#include "Controller.hpp"
#include "Keyboard.hpp"
#include "Mouse.hpp"
namespace engine {
	namespace input {
	
		class Input {
		public:
			GLFWwindow* window;
			Controller* controllers[5];
			Input(GLFWwindow* window);
			inline Keyboard* getKeyboard() const { return (Keyboard*) controllers[0]; }
			inline Mouse* getMouse() const { return (Mouse*) controllers[1]; }
		};

	}
}