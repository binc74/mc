#ifndef INPUT_COMMAND_H
#define INPUT_COMMAND_H

#include <iostream>

namespace mc {
	class InputCommand {
	public:
		virtual void execute(float dt) = 0;
	};
}

#endif
