#include "camera.h"

namespace engine{
	Camera::Camera() {
	}

	Camera::~Camera() {
		// Nothing
	}

	void Camera::setDirectionUp(float x, float y, float z) {
		direction_up = glm::vec3(x, y, z);
	}

	void Camera::setCameraFront(float x, float y, float z) {
		camera_front = glm::vec3(x, y, z);
	}

	void Camera::setCameraPosition(float x, float y, float z) {
		camera_position = glm::vec3(x, y, z);
	}

	glm::mat4 Camera::getViewMatrix() {
		glm::mat4 view_matrix(1.f);

		return glm::lookAt(camera_position, camera_position + camera_front,
			direction_up);
	}
}