#ifndef MODEL_MATRIX_H
#define MODEL_MATRIX_H

#include <glm.hpp>
#include <gtc\matrix_transform.hpp>

namespace mc {
	class ModelMatrix {
	private:
	public:
		glm::vec3 position;
		glm::vec3 rotation;
		glm::vec3 scale;

		ModelMatrix();
		ModelMatrix(float x, float y, float z);
		~ModelMatrix();
		void setPosition(float x, float y, float z);
		void setPosition(glm::vec3 position);
		void setRotation(float x, float y, float z);
		void setRotation(float x);
		void setRotation(glm::vec3 rotation);
		void setScale(float x, float y, float z);
		void setScale(float x);
		void changePosition(float dx, float dy, float dz);
		void changeRotation(float dx, float dy, float dz);
		void changeScale(float dx, float dy, float dz);
		glm::mat4 getMatrix();
	};
}

#endif

