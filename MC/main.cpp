#include <iostream>
#include <fstream>
#include <string>
#include <glm.hpp>

#include "libs.h"
#include "engine/window/window.h"

#include "engine/graphics/shapes/triangle.h"

using namespace engine;

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