#ifndef MOVE_RIGHT_COMMAND_H
#define MOVE_RIGHT_COMMAND_H

#include "input_command.h"
#include "../../player/player.h"

namespace mc {
	class Player;

	class MoveRightCommand : public InputCommand {
	private:
		mc::Player* player;

	public:
		MoveRightCommand() {

		}

		MoveRightCommand(mc::Player* player) {
			this->player = player;
		}

		void execute(float dt) {
			player->moveRight(dt);
		}
	};
}

#endif
