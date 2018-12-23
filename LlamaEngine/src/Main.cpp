#include <iostream>
#include <gl/glew.h>
#include <GLFW/glfw3.h>
#include "graphics/Shader.hpp"
int main() {
	using namespace engine;
	using namespace graphics;

	if (!glfwInit()) {
		std::cout << "Failed to initialise GLFW" << std::endl;
		return -1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	GLFWwindow* window = glfwCreateWindow(1280, 720, "Hello World!", nullptr, nullptr);
	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK) {
		std::cout << "Failed to initialise GLEW" << std::endl;
		return -1;
	}

	Shader* shader = new Shader("res/shader/Basic.glsl");
	shader->bind();

	while (!glfwWindowShouldClose(window)) {
		glClearColor(1, 1, 1, 1);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}