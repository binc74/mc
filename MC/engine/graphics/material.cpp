#include "material.h"

namespace engine {
	Material::Material() {

	}


	Material::Material(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular) {
		this->ambient = ambient;
		this->diffuse = diffuse;
		this->specular = specular;
	}

	Material::~Material() {

	}

	void Material::sendToShader(Shader& shader, GLint diffuse_tex, GLint specular_tex) {
		shader.setUniform3fv(ambient, "material.ambient");
		shader.setUniform3fv(diffuse, "material.diffuse");
		shader.setUniform3fv(specular, "material.specular");
		shader.setUniform1i(diffuse_tex, "material.diffuse_tex");
		shader.setUniform1i(specular_tex, "material.specular_tex");
	}
}