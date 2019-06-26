#include "game/game.h"
#include "const.h"

using namespace mc;

int main() {
	Game game(WINDOW_WIDTH, WINDOW_HEIGHT);

	// Main loop
	while (!game.shouldClose()) {
		game.update();
		game.render();
	}

	return 0;
}