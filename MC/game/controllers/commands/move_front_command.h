#ifndef MOVE_FRONT_COMMAND_H
#define MOVE_FRONT_COMMAND_H

#include "input_command.h"
#include "../../camera/camera.h"

namespace mc {
	class MoveFrontCommand : public InputCommand {
	private:
		mc::Camera* camera;

	public:
		MoveFrontCommand() {

		}

		MoveFrontCommand(mc::Camera* camera) {
			this->camera = camera;
		}

		void execute(float dt) {
			camera->moveFront(dt);
		}
	};
}

#endif
