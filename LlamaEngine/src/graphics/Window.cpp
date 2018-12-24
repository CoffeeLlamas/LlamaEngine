#include "Window.hpp"

namespace engine {
	namespace graphics {

		Window::Window(int width, int height, const char* title) {
			m_Width = width;
			m_Height = height;
			m_Title = title;

			if (!glfwInit()) {
				printf("Unable to initialze GLFW, stopping window creation...");
				glfwTerminate();
				return;
			}

			m_Window = glfwCreateWindow(width, height, title, NULL, NULL);
			if (!m_Window) {
				printf("Unable to create GLFWWindow, stopping window creation...");
				glfwTerminate();
				return;
			}

			glfwDefaultWindowHints();
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

			glfwMakeContextCurrent(m_Window);
			glfwSwapInterval(1);
		}

		Window::~Window() {
			glfwDestroyWindow(m_Window);
			glfwTerminate();
		}

		void Window::Update() const {
			glfwSwapBuffers(m_Window);
			glfwPollEvents();
		}
	}
}