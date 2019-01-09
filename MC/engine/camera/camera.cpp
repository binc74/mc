#include "camera.h"

namespace engine{
	Camera::Camera() {
		direction_up = new glm::vec3(0.f, 0.f, 1.f);
		camera_front = new glm::vec3(0.f, 0.f, -1.f);
		camera_position = new glm::vec3(0.f);
	}

	Camera::~Camera() {
		delete direction_up;
		delete camera_front;
		delete camera_position;
	}

	void Camera::setDirectionUp(float x, float y, float z) {
		direction_up = new glm::vec3(x, y, z);
	}

	void Camera::setCameraFront(float x, float y, float z) {
		camera_front = new glm::vec3(x, y, z);
	}

	void Camera::setCameraPosition(float x, float y, float z) {
		camera_position = new glm::vec3(x, y, z);
	}

	void Camera::rotateCamX(float d) {
		camera_front->x += d;
	}

	void Camera::rotateCamY(float d) {
		camera_front->y += d;
	}

	void Camera::rotateCamZ(float d) {
		camera_front->z += d;
	}

	void Camera::goFront(float d) {
		*camera_position += *camera_front * d;
	}

	void Camera::goBack(float d) {
		*camera_position -= *camera_front * d;
	}

	void Camera::goLeft(float d) {

	}

	void Camera::goRight(float d) {

	}

	glm::mat4 Camera::getViewMatrix() {
		return glm::lookAt(*camera_position, *camera_position + *camera_front,
			*direction_up);
	}
}