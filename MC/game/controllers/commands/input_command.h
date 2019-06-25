#ifndef INPUT_COMMAND_H
#define INPUT_COMMAND_H

namespace mc {
	class InputCommand {
	public:
		virtual void execute(float dt) = 0;
	};
}

#endif
