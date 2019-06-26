#ifndef MOVE_UP_COMMAND_H
#define MOVE_UP_COMMAND_H

#include "input_command.h"
#include "../../player/player.h"

namespace mc {
	class Player;

	class MoveUpCommand : public InputCommand {
	private:
		mc::Player* player;

	public:
		MoveUpCommand() {

		}

		MoveUpCommand(mc::Player* player) {
			this->player = player;
		}

		void execute(float dt) {
			player->moveUp(dt);
		}
	};
}

#endif
