#ifndef MOVE_LEFT_COMMAND_H
#define MOVE_LEFT_COMMAND_H

#include "input_command.h"
#include "../../camera/camera.h"

namespace mc {
	class MoveLeftCommand : public InputCommand {
	private:
		mc::Camera* camera;

	public:
		MoveLeftCommand() {

		}

		MoveLeftCommand(mc::Camera* camera) {
			this->camera = camera;
		}

		void execute(float dt) {
			camera->moveLeft(dt);
		}
	};
}

#endif
