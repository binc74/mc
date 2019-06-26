#ifndef MOVE_LEFT_COMMAND_H
#define MOVE_LEFT_COMMAND_H

#include "input_command.h"
#include "../../player/player.h"

namespace mc {
	class Player;

	class MoveLeftCommand : public InputCommand {
	private:
		mc::Player* player;

	public:
		MoveLeftCommand() {

		}

		MoveLeftCommand(mc::Player* player) {
			this->player = player;
		}

		void execute(float dt) {
			player->moveLeft(dt);
		}
	};
}

#endif
