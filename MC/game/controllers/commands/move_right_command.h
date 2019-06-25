#ifndef MOVE_RIGHT_COMMAND_H
#define MOVE_RIGHT_COMMAND_H

#include "input_command.h"
#include "../../camera/camera.h"

namespace mc {
	class MoveRightCommand : public InputCommand {
	private:
		mc::Camera* camera;

	public:
		MoveRightCommand() {

		}

		MoveRightCommand(mc::Camera* camera) {
			this->camera = camera;
		}

		void execute(float dt) {
			camera->moveRight(dt);
		}
	};
}

#endif
