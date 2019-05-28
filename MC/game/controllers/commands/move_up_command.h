#ifndef MOVE_UP_COMMAND_H
#define MOVE_UP_COMMAND_H

#include "input_command.h"
#include "../../camera/camera.h"

namespace game {
	class MoveUpCommand : public InputCommand {
	private:
		game::Camera* camera;

	public:
		MoveUpCommand() {

		}

		MoveUpCommand(game::Camera* camera) {
			this->camera = camera;
		}

		void execute(float dt) {
			camera->goUp(dt);
		}
	};
}

#endif
