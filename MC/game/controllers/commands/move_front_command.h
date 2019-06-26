#ifndef MOVE_FRONT_COMMAND_H
#define MOVE_FRONT_COMMAND_H

#include "input_command.h"
#include "../../player/player.h"

namespace mc {
	class Player;

	class MoveFrontCommand : public InputCommand {
	private:
		mc::Player* player;

	public:
		MoveFrontCommand() {

		}

		MoveFrontCommand(mc::Player* player) {
			this->player = player;
		}

		void execute(float dt) {
			player->moveFront(dt);
		}
	};
}

#endif
