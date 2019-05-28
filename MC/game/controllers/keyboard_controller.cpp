#include "keyboard_controller.h"

namespace game {
	KeyboardController::KeyboardController() : Controller() {

	}

	KeyboardController::KeyboardController(GLFWwindow* window) : Controller(window) {

	}

	KeyboardController::~KeyboardController() {
		for (auto it : commands) {
			delete it.second;
		}
	}

	void KeyboardController::addInputCommand(int key, InputCommand* command) {
		if (keys.find(key) == keys.end()) {
			keys.insert(key);
			commands[key] = command;
		}
	}

	void KeyboardController::updateInput(float dt) {
		for (int key: keys) {
			if (glfwGetKey(window, key) == GLFW_PRESS) {
				commands[key]->execute(dt);
			}			
		}
		/*
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
			glfwSetWindowShouldClose(window, GLFW_TRUE);
		}
		else if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
			camera->goFront(dt);
		}
		else if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
			camera->goBack(dt);
		}
		else if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
			camera->goLeft(dt);
		}
		else if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
			camera->goRight(dt);
		}
		else if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
			camera->goUp(dt);
		}
		else if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS) {
			camera->goDown(dt);
		}
		else if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS) {

		}
		else if (glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS) {

		}
		*/
	}
}