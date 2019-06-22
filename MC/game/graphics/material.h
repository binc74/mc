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

namespace game {
	class Material {
	private:
		glm::vec3 ambient;
		glm::vec3 diffuse;
		glm::vec3 specular;

	public:
		Material();
		Material(const glm::vec3& ambient, const glm::vec3& diffuse, const glm::vec3& specular);
		~Material();
		void sendToShader(Shader* shader_id, GLint diffuse_tex, GLint specular_tex);
	};
}

#endif
