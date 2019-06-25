#ifndef MAIN_CONTROLLER_H
#define MAIN_CONTROLLER_H

#include <vector>

#include <glfw3.h>

#include "controller.h"

namespace mc {
	class MainController {
	private:
		std::vector<Controller*> controllers;

		// Use to calculate dt
		float dt;
		float last_time;

		void initParams();
		void updateTime();

	public:
		MainController();
		~MainController();

		void addController(Controller* cont);
		void updateInput();
	};
}

#endif