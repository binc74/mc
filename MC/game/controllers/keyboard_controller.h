#ifndef KEYBOARD_CONTROLLER_H
#define KEYBOARD_CONTROLLER_H

#include <glew.h>
#include <glfw3.h>
#include <unordered_set>
#include <unordered_map>

#include "controller.h"
#include "commands/input_command.h"

namespace mc {
	class KeyboardController : public Controller {
	private:
		std::unordered_set<int> keys;
		std::unordered_map<int,InputCommand*> commands;

	public:
		KeyboardController(GLFWwindow* window);
		~KeyboardController();

		void addInputCommand(int key, InputCommand* command);
		void updateInput(float dt);
	};
}

#endif