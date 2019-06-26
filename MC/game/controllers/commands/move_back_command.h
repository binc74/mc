#ifndef MOVE_BACK_COMMAND_H
#define MOVE_BACK_COMMAND_H

#include "input_command.h"
#include "../../player/player.h"

namespace mc {
	class Player;

	class MoveBackCommand : public InputCommand {
	private:
		mc::Player* player;

	public:
		MoveBackCommand() {

		}

		MoveBackCommand(mc::Player* player) {
			this->player = player;
		}

		void execute(float dt) {
			player->moveBack(dt);
		}
	};
}

#endif
