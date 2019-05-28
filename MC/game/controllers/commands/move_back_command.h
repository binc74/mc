#ifndef MOVE_BACK_COMMAND_H
#define MOVE_BACK_COMMAND_H

#include "input_command.h"
#include "../../camera/camera.h"

namespace game {
	class MoveBackCommand : public InputCommand {
	private:
		game::Camera* camera;

	public:
		MoveBackCommand() {

		}

		MoveBackCommand(game::Camera* camera) {
			this->camera = camera;
		}

		void execute(float dt) {
			camera->goBack(dt);
		}
	};
}

#endif
