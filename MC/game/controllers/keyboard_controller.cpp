#include "keyboard_controller.h"

namespace game {
	KeyboardController::KeyboardController() : Controller() {

	}

	KeyboardController::KeyboardController(GLFWwindow* window, Camera* camera) : Controller(window) {
		this->camera = camera;
	}

	void KeyboardController::updateInput(float dt) {
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
	}
}