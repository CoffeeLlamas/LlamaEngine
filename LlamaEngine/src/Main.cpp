#include <iostream>
#include <gl/glew.h>
#include <GLFW/glfw3.h>
#include "graphics/Shader.hpp"
#include "graphics/Window.hpp"
#include "math/Vector3.hpp"

int main() {
	using namespace engine;
	using namespace graphics;
	using namespace math;
	Window* window = new Window(400, 600, "TestWindow");

	if (glewInit() != GLEW_OK) {
		std::cout << "Failed to initialise GLEW" << std::endl;
		system("PAUSE");
		return -1;
	}
	Shader* shader = new Shader("res/shader/Basic.glsl");
	shader->bind();

	Vector3 vector = Vector3::identity().set(1, 5, 3);
	Vector3 vector2 = Vector3::identity().set(5, 2, 2);
	vector = vector.normalize();

	std::cout << vector.x << ", " << vector.y << ", " << vector.z;

	while (!window->ShouldClose()) {
		glClearColor(1, 1, 1, 1);
		glClear(GL_COLOR_BUFFER_BIT);

		window->Update();
	}
	
	delete(window);
	system("PAUSE");
}