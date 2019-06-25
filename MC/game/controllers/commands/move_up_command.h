#ifndef MOVE_UP_COMMAND_H
#define MOVE_UP_COMMAND_H

#include "input_command.h"
#include "../../camera/camera.h"

namespace mc {
	class MoveUpCommand : public InputCommand {
	private:
		mc::Camera* camera;

	public:
		MoveUpCommand() {

		}

		MoveUpCommand(mc::Camera* camera) {
			this->camera = camera;
		}

		void execute(float dt) {
			camera->moveUp(dt);
		}
	};
}

#endif
