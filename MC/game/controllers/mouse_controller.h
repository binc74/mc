#ifndef MOUSE_CONTROLLER_H
#define MOUSE_CONTROLLER_H

#include "controller.h"
#include "../camera/camera.h"

namespace mc {
	class MouseController : public Controller {
	private:
		Camera* camera;
		
		double last_mouse_x;
		double last_mouse_y;
		double mouse_x;
		double mouse_y;
		double mouse_offset_x;
		double mouse_offset_y;
		bool is_first_mouse;

		void initParams();

	public:
		MouseController();
		MouseController(GLFWwindow* window, Camera* camera);

		void updateInput(float dt);
	};
}

#endif
