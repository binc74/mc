#ifndef CAMERA_H
#define CAMERA_H

#include <glm.hpp>
#include <gtc\matrix_transform.hpp>

namespace engine {
	class Camera {
	private:
		glm::vec3 direction_up;
		glm::vec3 camera_front;
		
	public:
		glm::vec3 camera_position;

		Camera();
		~Camera();
		void setDirectionUp(float x, float y, float z);
		void setCameraFront(float x, float y, float z);
		void setCameraPosition(float x, float y, float z);
		glm::mat4 getViewMatrix();
	};
}

#endif
