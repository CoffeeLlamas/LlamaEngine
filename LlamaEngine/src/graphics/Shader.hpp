#pragma once
#include <string>

namespace engine {
	namespace graphics {
		
		struct ShaderSource {
			std::string vertex;
			std::string fragment;
		};

		class Shader {
		public:
			unsigned int program;
			Shader(const char* file);
			Shader(ShaderSource* sources);
			static std::string read(const char* file);
			static ShaderSource* parse(std::string contents);
			static void compile(unsigned int shader, const char* src);

			void bind();
			void unbind();
		};

	}
}