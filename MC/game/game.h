#ifndef GAME_H
#define GAME_H

#include <glew.h>
#include <glfw3.h>

#include "controllers/commands/include_command.h"
#include "controllers/mouse_controller.h"
#include "controllers/keyboard_controller.h"
#include "controllers/main_controller.h"
#include "window/window.h"
#include "world/world.h"
#include "player/player.h"
#include "graphics/shader.h"
#include "graphics/material.h"
#include "objects/include.h"

namespace mc {
	class Game {
	private:
		mc::World* world;
		mc::MainController* mainController;
		mc::Player* player;

		// Only one shader and material currently
		mc::Material* material;
		int window_width, window_height;

		void init();
		void initController();
		void initWorld();

	public:
		mc::Window* window;

		Game(int window_width, int window_height);
		~Game();

		bool shouldClose();
		void update();
		void render();
	};
}

#endif