#include "Input.hpp"
namespace engine {
	namespace input {
	
		Input::Input(GLFWwindow* window) {
			this->window = window;
			this->controllers[0] = new Keyboard(window);
			this->controllers[1] = new Mouse(window);
		}

	}
}