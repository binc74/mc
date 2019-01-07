#ifndef SHADER_H
#define SHADER_H

#include <iostream>
#include <fstream>
#include <string>
#include <glew.h>
#include <glfw3.h>

#include <glm.hpp>
#include <vec2.hpp>
#include <vec3.hpp>
#include <vec4.hpp>
#include <mat4x4.hpp>
#include <gtc\type_ptr.hpp>

namespace engine {
	class Shader {
	private:
		GLuint id;
		GLenum type;

		std::string loadShaderSource(const char* filename);
		GLuint loadShader(GLenum type, const char* filename);
		void linkProgram(GLuint vertex_shader, GLuint geo_shader, GLuint frag_shader);

	public:
		Shader(const char* vertex_file, const char* frag_file, const char* geo_file = "");
		~Shader();
		void use();
		void unuse();
		void setUniform1i(GLint value, const GLchar* name);
		void setUniform1f(GLfloat value, const GLchar* name);
		void setUniform2fv(glm::fvec2 value, const GLchar* name);
		void setUniform3fv(glm::fvec3 value, const GLchar* name);
		void setUniform4fv(glm::fvec4 value, const GLchar* name);
		void setUniformMat3fv(glm::fmat3 value, const GLchar* name, bool transpose = GL_FALSE);
		void setUniformMat4fv(glm::fmat4 value, const GLchar* name, bool transpose = GL_FALSE);
	};
}

#endif
