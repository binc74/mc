#include "shader.h"

namespace engine {
	std::string Shader::loadShaderSource(const char* filename) {
		std::string temp = "";
		std::string src = "";
		std::ifstream in_file;

		in_file.open(filename);

		// Vertex
		if (in_file.is_open()) {
			while (std::getline(in_file, temp)) {
				src += temp + "\n";
			}
		}
		else {
			std::cerr << "Error loading vertext file " << filename << std::endl;
		}

		in_file.close();

		return src;
	}

	GLuint Shader::loadShader(GLenum type, const char* filename) {		
		GLint success;

		GLuint shader = glCreateShader(type);
		const GLchar* src = loadShaderSource(filename).c_str();
		glShaderSource(shader, 1, &src, NULL);
		glCompileShader(shader);

		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

		if (!success) {
			char info_log[512];

			glGetShaderInfoLog(shader, 512, NULL, info_log);
			std::cerr << "Error loading shader" << std::endl;
			std::cerr << info_log << std::endl;
		}

		return shader;
	}

	void Shader::linkProgram(GLuint vertexShader, GLuint geometryShader, GLuint fragShader) {
		GLint success;

		id = glCreateProgram();

		glAttachShader(id, vertexShader);

		if (geometryShader) {
			glAttachShader(id, geometryShader);
		}

		glAttachShader(id, vertexShader);

		glLinkProgram(id);

		glGetProgramiv(id, GL_LINK_STATUS, &success);

		if (!success) {
			char info_log[512];

			glGetProgramInfoLog(id, 512, NULL, info_log);
			std::cerr << "Error loading program" << std::endl;
			std::cerr << info_log << std::endl;
		}

		unuse();
	}

	Shader::Shader(const char* vertex_file, const char* frag_file, const char* geo_file) {
		GLuint vertexShader = 0, geometryShader = 0, fragShader = 0;

		vertexShader = loadShader(GL_VERTEX_SHADER, vertex_file);

		if (geo_file != "")
			geometryShader = loadShader(GL_GEOMETRY_SHADER, geo_file);

		fragShader = loadShader(GL_FRAGMENT_SHADER, frag_file);

		linkProgram(vertexShader, geometryShader, fragShader);

		// End	
		glDeleteShader(vertexShader);
		glDeleteShader(geometryShader);
		glDeleteShader(fragShader);
	}

	Shader::~Shader() {
		glDeleteProgram(id);
	}

	void Shader::use() {
		glUseProgram(id);
	}

	void Shader::unuse() {
		glUseProgram(0);
	}

	void Shader::setUniform1i(GLint value, const GLchar* name) {
		glUniform1i(glGetUniformLocation(id, name), value);
	}

	void Shader::setUniform1f(GLfloat value, const GLchar* name) {
		glUniform1f(glGetUniformLocation(id, name), value);
	}

	void Shader::setUniform2fv(glm::fvec2 value, const GLchar* name) {
		glUniform2fv(glGetUniformLocation(id, name), 1, glm::value_ptr(value));
	}

	void Shader::setUniform3fv(glm::fvec3 value, const GLchar* name) {
		glUniform3fv(glGetUniformLocation(id, name), 1, glm::value_ptr(value));
	}

	void Shader::setUniform4fv(glm::fvec4 value, const GLchar* name) {
		glUniform4fv(glGetUniformLocation(id, name), 1, glm::value_ptr(value));
	}

	void Shader::setUniformMat3fv(glm::fmat3 value, const GLchar* name, bool transpose) {
		glUniformMatrix3fv(glGetUniformLocation(id, name), 1, transpose, glm::value_ptr(value));
	}

	void Shader::setUniformMat4fv(glm::fmat4 value, const GLchar* name, bool transpose) {
		glUniformMatrix4fv(glGetUniformLocation(id, name), 1, transpose, glm::value_ptr(value));
	}
}