#ifndef MOVE_LEFT_COMMAND_H
#define MOVE_LEFT_COMMAND_H

#include "input_command.h"
#include "../../camera/camera.h"

namespace game {
	class MoveLeftCommand : public InputCommand {
	private:
		game::Camera* camera;

	public:
		MoveLeftCommand() {

		}

		MoveLeftCommand(game::Camera* camera) {
			this->camera = camera;
		}

		void execute(float dt) {
			camera->goLeft(dt);
		}
	};
}

#endif
