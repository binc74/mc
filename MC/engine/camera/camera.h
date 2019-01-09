#ifndef CAMERA_H
#define CAMERA_H

#include <glm.hpp>
#include <gtc\matrix_transform.hpp>

namespace engine {
	class Camera {
	private:
		glm::vec3* direction_up;
		glm::vec3* camera_front;
		
	public:
		glm::vec3* camera_position;

		Camera();
		~Camera();
		void setDirectionUp(float x, float y, float z);
		void setCameraFront(float x, float y, float z);
		void setCameraPosition(float x, float y, float z);
		void rotateCamX(float d);
		void rotateCamY(float d);
		void rotateCamZ(float d);
		void goFront(float d);
		void goBack(float d);
		void goLeft(float d);
		void goRight(float d);

		glm::mat4 getViewMatrix();
	};
}

#endif
