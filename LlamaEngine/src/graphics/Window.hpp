#pragma once
#include <GLFW/glfw3.h>
#include <stdio.h>

namespace engine {
	namespace graphics {

		class Window {

			GLFWwindow* m_Window;
			int m_Width, m_Height;
			const char* m_Title;

		public:
			Window(int width, int height, const char* title);

			~Window();

			void Update() const;

			inline bool ShouldClose() const { return glfwWindowShouldClose(m_Window); }

			inline int GetWidth() const { return m_Width; }

			inline int GetHeight() const { return m_Height; }

			inline const char* GetTitle() const { return m_Title; }
		};

} }