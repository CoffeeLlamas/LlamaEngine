#pragma once
#include <GLFW/glfw3.h>
#include <stdio.h>
#include "../input/Input.hpp"

namespace engine {
	namespace graphics {

		using namespace input;
		class Window {

			GLFWwindow* m_Window;
			int m_Width, m_Height;
			const char* m_Title;
			double m_Now;
			Input* m_Input = nullptr;

		public:
			Window(int width, int height, const char* title);

			~Window();

			void Update();

			inline bool ShouldClose() const { return glfwWindowShouldClose(m_Window); }

			inline int GetWidth() const { return m_Width; }

			inline int GetHeight() const { return m_Height; }

			inline const char* GetTitle() const { return m_Title; }

			inline GLFWwindow* GetWindow() const { return m_Window; }

			inline double GetNow() const { return m_Now; }

			inline Input* GetInput() const { return m_Input; }
		};

} }