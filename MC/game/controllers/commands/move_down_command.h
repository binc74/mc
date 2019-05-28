#ifndef MOVE_DOWN_COMMAND_H
#define MOVE_DOWN_COMMAND_H

#include "input_command.h"
#include "../../camera/camera.h"

namespace game {
	class MoveDownCommand : public InputCommand {
	private:
		game::Camera* camera;

	public:
		MoveDownCommand() {

		}

		MoveDownCommand(game::Camera* camera) {
			this->camera = camera;
		}

		void execute(float dt) {
			camera->goDown(dt);
		}
	};
}

#endif
