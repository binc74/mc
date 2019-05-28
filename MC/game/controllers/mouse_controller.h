#ifndef MOUSE_CONTROLLER_H
#define MOUSE_CONTROLLER_H

#include "controller.h"

namespace game {
	class MouseController : public Controller {
	private:
		GLFWwindow* window;

		void initParams();

	public:
		MouseController();
		MouseController(GLFWwindow* window);

		void updateInput();
	};
}

#endif
