#include <iostream>
#include <gl/glew.h>
#include <GLFW/glfw3.h>
#include "graphics/Shader.hpp"
#include "graphics/Window.hpp"
#include "input/Keyboard.hpp"
#include "input/Mouse.hpp"

int main() {
	using namespace engine;
	using namespace input;
	using namespace graphics;

	Window* window = new Window(100, 100, "");
	Input* i = window->GetInput();
	Keyboard* kb = i->getKeyboard();
	Mouse* mouse = i->getMouse();
	while (!window->ShouldClose()) {
		glfwSetWindowUserPointer(window->GetWindow(), window);
		if (kb->btnJustDown(KEY_A))
			std::cout << "A " << window->GetNow() << std::endl;

		if (kb->btnJustUp(KEY_B))
			std::cout << "B " << window->GetNow() << std::endl;

		if (kb->btnDown(KEY_C))
			std::cout << "C " << window->GetNow() << std::endl;

		if (kb->btnUp(KEY_D) && kb->btnDown(KEY_LSHIFT))
			std::cout << "D " << window->GetNow() << std::endl;

		if (kb->btnDown(KEY_LCTRL) && kb->btnDown(KEY_1))
			std::cout << "MOUSE X" << mouse->mouseX << " Y" << mouse->mouseY << std::endl;

		if (kb->btnDown(KEY_LCTRL) && kb->btnDown(KEY_2))
			std::cout << "MOUSE LEFT" << mouse->btnDown(MOUSE_LEFT) << std::endl;

		if (kb->btnDown(KEY_LCTRL) && kb->btnDown(KEY_3))
			std::cout << "MOUSE MID" << mouse->btnDown(MOUSE_MIDDLE) << std::endl;

		if (kb->btnDown(KEY_LCTRL) && kb->btnDown(KEY_4))
			std::cout << "MOUSE RIGHT" << mouse->btnDown(MOUSE_RIGHT) << std::endl;
		window->Update();
	}
}