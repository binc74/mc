#ifndef MOVE_BACK_COMMAND_H
#define MOVE_BACK_COMMAND_H

#include "input_command.h"
#include "../../camera/camera.h"

namespace mc {
	class MoveBackCommand : public InputCommand {
	private:
		mc::Camera* camera;

	public:
		MoveBackCommand() {

		}

		MoveBackCommand(mc::Camera* camera) {
			this->camera = camera;
		}

		void execute(float dt) {
			camera->moveBack(dt);
		}
	};
}

#endif
