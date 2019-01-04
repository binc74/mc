#include "libs.h"
#include "window.h"

int main() {
	engine::Window window(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME);
	window.Init(4, 4, false);

	while (!window.ShouldClose()) {
		window.Update();
	}

	window.~Window();
	return 0;
}