#ifndef CAMERA_H
#define CAMERA_H

#include <glm.hpp>
#include <gtc\matrix_transform.hpp>

namespace engine {
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
		void setCameraPosition(float x, float y, float z);
		void goFront(float dt);
		void goBack(float dt);
		void goLeft(float dt);
		void goRight(float dt);
		void goUp(float dt);
		void goDown(float dt);

		void updateByMouseInput(float dt, double offset_x, double offset_y);
		glm::mat4 getViewMatrix();
	};
}

#endif
