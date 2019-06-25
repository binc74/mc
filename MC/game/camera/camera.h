#ifndef CAMERA_H
#define CAMERA_H

#include <glm.hpp>
#include <gtc\matrix_transform.hpp>

namespace mc {
	class Camera {
	private:
		glm::vec3 direction_up;
		glm::vec3 camera_up;
		glm::vec3 camera_front;
		glm::vec3 camera_right;
		float pitch;
		float yaw;
		float roll;
		float speed;
		float sensitivity;
		bool y_enable;
		bool y_reverse;

		void updateVectors();
	public:
		glm::vec3* camera_position;

		Camera();
		~Camera();
		void setDirectionUp(float x, float y, float z);
		void setCameraFront(float x, float y, float z);
		void moveFront(float dt);
		void moveBack(float dt);
		void moveLeft(float dt);
		void moveRight(float dt);
		void moveUp(float dt);
		void moveDown(float dt);

		void setPosition(float px, float py, float pz);
		void updateByMouseInput(float dt, double offset_x, double offset_y);
		glm::mat4 getViewMatrix();
	};
}

#endif
