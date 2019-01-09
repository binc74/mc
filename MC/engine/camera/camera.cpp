#include "camera.h"

namespace engine{
	Camera::Camera() {
		direction_up = glm::vec3(0.f, 0.f, 1.f);
		camera_front = glm::vec3(0.f, 0.f, -1.f);
		camera_position = new glm::vec3(0.f, 0.f, 4.f);
		camera_up = direction_up;
		speed = 3.f;
		sensitivity = 5.f;
		pitch = 0.f;
		yaw = -90.f;
		roll = 0.f;
		camera_right = glm::vec3(0.f);
		y_enable = false;
		y_reverse = false;

		updateVectors();
	}

	Camera::~Camera() {
		delete camera_position;
	}

	void Camera::updateVectors() {
		camera_front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
		camera_front.y = sin(glm::radians(pitch));
		camera_front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));

		camera_front = glm::normalize(camera_front);
		camera_right = glm::normalize(glm::cross(camera_front, direction_up));
		camera_up = glm::normalize(glm::cross(camera_right, camera_front));
	}

	void Camera::setDirectionUp(float x, float y, float z) {
		direction_up = glm::vec3(x, y, z);
	}

	void Camera::setCameraFront(float x, float y, float z) {
		camera_front = glm::vec3(x, y, z);
	}

	void Camera::setCameraPosition(float x, float y, float z) {
		camera_position = new glm::vec3(x, y, z);
	}

	void Camera::goFront(float dt) {
		*camera_position += camera_front * speed * dt;
	}

	void Camera::goBack(float dt) {
		*camera_position -= camera_front * speed * dt;
	}

	void Camera::goLeft(float dt) {
		*camera_position -= camera_right * speed * dt;
	}

	void Camera::goRight(float dt) {
		*camera_position += camera_right * speed * dt;
	}

	void Camera::updateByMouseInput(float dt, double offset_x, double offset_y) {
		float dp = static_cast<float>(offset_y) * sensitivity * dt;

		if (y_reverse)
			pitch += dp;
		else
			pitch -= dp;
			
		if (pitch > 80.f)
			pitch = 80.f;
		else if (pitch < -80.f)
			pitch = -80.f;

		yaw += static_cast<float>(offset_x) * sensitivity * dt;

		if (yaw > 360.f || yaw < -360.f)
			yaw = 0.f;
	}

	glm::mat4 Camera::getViewMatrix() {
		updateVectors();

		return glm::lookAt(*camera_position, *camera_position + camera_front,
			camera_up);
	}
}