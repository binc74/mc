#include <iostream>
#include <fstream>
#include <string>
#include <glm.hpp>

#include "const.h"
#include "game/window/window.h"

using namespace game;

int main() {
	Window window(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME);
	window.init(4, 4, false);

	// Main loop
	while (!window.shouldClose()) {
		window.update();
		window.render();
	}

	// Free resources and end program

	return 0;
}