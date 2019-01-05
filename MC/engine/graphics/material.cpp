#include "material.h"

namespace engine {
	Material::Material(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular,
		GLint diffuse_tex, GLint specular_tex) {
		this->ambient = ambient;
		this->diffuse = diffuse;
		this->specular = specular;
		this->diffuse_tex = diffuse_tex;
		this->specular_tex = specular_tex;
	}

	Material::~Material() {

	}

	void Material::sendToShader(Shader& shader) {
		shader.setUniform3fv(ambient, "material.ambient");
		shader.setUniform3fv(diffuse, "material.diffuse");
		shader.setUniform3fv(specular, "material.specular");
		shader.setUniform1i(diffuse_tex, "material.diffuse_tex");
		shader.setUniform1i(specular_tex, "material.specular_tex");
	}
}