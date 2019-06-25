#ifndef MOVE_DOWN_COMMAND_H
#define MOVE_DOWN_COMMAND_H

#include "input_command.h"
#include "../../camera/camera.h"

namespace mc {
	class MoveDownCommand : public InputCommand {
	private:
		mc::Camera* camera;

	public:
		MoveDownCommand() {

		}

		MoveDownCommand(mc::Camera* camera) {
			this->camera = camera;
		}

		void execute(float dt) {
			camera->moveDown(dt);
		}
	};
}

#endif
