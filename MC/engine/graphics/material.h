#ifndef MATERIAL_H
#define MATERIAL_H

#include <glew.h>
#include <glfw3.h>
#include <glm.hpp>
#include <vec2.hpp>
#include <vec3.hpp>
#include <vec4.hpp>
#include <mat4x4.hpp>
#include <gtc\type_ptr.hpp>

#include "shader.h"

namespace engine {
	class Material {
	private:
		glm::vec3 ambient;
		glm::vec3 diffuse;
		glm::vec3 specular;
		GLint diffuse_tex;
		GLint specular_tex;

	public:
		Material(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular,
			GLint diffuse_tex, GLint specular_tex);
		~Material();
		void sendToShader(Shader& shader_id);
	};
}

#endif
