#ifndef MOUSE_CONTROLLER_H
#define MOUSE_CONTROLLER_H

#include <glew.h>
#include <glfw3.h>

#include "controller.h"
#include "../player/player.h"

namespace mc {
	class MouseController : public Controller {
	private:
		mc::Player* player;
		
		double last_mouse_x;
		double last_mouse_y;
		double mouse_x;
		double mouse_y;
		double mouse_offset_x;
		double mouse_offset_y;
		bool is_first_mouse;

		void initParams();

	public:
		MouseController(GLFWwindow* window, mc::Player* player);

		void updateInput(float dt);
	};
}

#endif
