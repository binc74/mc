#ifndef MOVE_RIGHT_COMMAND_H
#define MOVE_RIGHT_COMMAND_H

#include "input_command.h"
#include "../../camera/camera.h"

namespace game {
	class MoveRightCommand : public InputCommand {
	private:
		game::Camera* camera;

	public:
		MoveRightCommand() {

		}

		MoveRightCommand(game::Camera* camera) {
			this->camera = camera;
		}

		void execute(float dt) {
			camera->goRight(dt);
		}
	};
}

#endif
