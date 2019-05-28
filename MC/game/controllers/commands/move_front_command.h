#ifndef MOVE_FRONT_COMMAND_H
#define MOVE_FRONT_COMMAND_H

#include "input_command.h"
#include "../../camera/camera.h"

namespace game {
	class MoveFrontCommand : public InputCommand {
	private:
		game::Camera* camera;

	public:
		MoveFrontCommand() {

		}

		MoveFrontCommand(game::Camera* camera) {
			this->camera = camera;
		}

		void execute(float dt) {
			camera->goFront(dt);
		}
	};
}

#endif
