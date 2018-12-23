#include <iostream>
#include <gl/glew.h>
#include <GLFW/glfw3.h>
#include "graphics/Window.hpp"

int main() {
	using namespace engine;
	using namespace graphics;
	Window* window = new Window(400, 600, "TestWindow");

	if (glewInit() != GLEW_OK) {
		std::cout << "Failed to initialise GLEW" << std::endl;
		system("PAUSE");
		return -1;
	}
	

	while (!window->ShouldClose()) {
		glClearColor(1, 1, 1, 1);
		glClear(GL_COLOR_BUFFER_BIT);

		window->Update();
	}
	
	delete(window);
	system("PAUSE");
}