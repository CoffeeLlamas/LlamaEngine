#pragma once
#include <GLFW/glfw3.h>
namespace engine {
	namespace input {
		
		class Controller {
		public:
			GLFWwindow* window;
			Controller(GLFWwindow* window);
			double button[512];
			bool btnDown(int btn);
			bool btnJustDown(int btn);
			bool btnUp(int btn);
			bool btnJustUp(int btn);
		};

	}
}