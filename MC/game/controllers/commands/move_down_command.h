#ifndef MOVE_DOWN_COMMAND_H
#define MOVE_DOWN_COMMAND_H

#include "input_command.h"
#include "../../player/player.h"

namespace mc {
	class Player;

	class MoveDownCommand : public InputCommand {
	private:
		mc::Player* player;

	public:
		MoveDownCommand() {

		}

		MoveDownCommand(mc::Player* player) {
			this->player = player;
		}

		void execute(float dt) {
			player->moveDown(dt);
		}
	};
}

#endif
