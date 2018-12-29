#include "Shader.hpp"
#include <gl/glew.h>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

namespace engine {
	namespace graphics {

		Shader::Shader(const char* file) : Shader(Shader::parse(Shader::read(file))) { }
		Shader::Shader(ShaderSource* source) {
			this->program = glCreateProgram();
			unsigned int vertex = glCreateShader(GL_VERTEX_SHADER);
			unsigned int fragment = glCreateShader(GL_FRAGMENT_SHADER);

			Shader::compile(vertex, source->vertex.c_str());
			Shader::compile(fragment, source->fragment.c_str());

			glAttachShader(this->program, vertex);
			glAttachShader(this->program, fragment);
			glLinkProgram(this->program);

			int linked;
			glGetProgramiv(this->program, GL_LINK_STATUS, &linked);
			if (!linked) {
				int length = 0;
				char message[1024];
				glGetProgramInfoLog(this->program, 1024, &length, message);
				std::cout << "[PROGRAM] " << message << std::endl;
			}

			glDeleteShader(vertex);
			glDeleteShader(fragment);
			delete source;
		}

		std::string Shader::read(const char* file) {
			std::fstream stream(file);
			std::string line;
			std::stringstream contents;
			while (std::getline(stream, line))
				contents << line << std::endl;

			return contents.str();
		}

		ShaderSource* Shader::parse(std::string contents) {
			std::istringstream stuff(contents);
			std::stringstream shaders[2];
			std::string line;
			int mode = -1;
			while (std::getline(stuff, line)) {
				if (line.compare(0, 7, "#vertex") == 0)
					mode = 0;
				else if (line.compare(0, 9, "#fragment") == 0)
					mode = 1;
				else if (mode != -1)
					shaders[mode] << line << std::endl;
			}

			return new ShaderSource {
				shaders[0].str(),
				shaders[1].str()
			};
		}

		void Shader::compile(unsigned int shader, const char* src) {
			glShaderSource(shader, 1, &src, 0);
			glCompileShader(shader);
			int compiled;
			glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
			if (!compiled) {
				int length = 0;
				char message[1024];
				glGetShaderInfoLog(shader, 1024, &length, message);
				std::cout << "[SHADER] " << message << std::endl;
			}
		}


		void Shader::bind() {
			glUseProgram(this->program);
		}

		void Shader::unbind() {
			glUseProgram(0);
		}

	}
}