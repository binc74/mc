#ifndef PLAYER_H
#define PLAYER_H

#include "../camera/camera.h"

namespace game {
	class Camera;

	class Player {
	private:
		Camera camera;

	public:
		Player();
		Player(float px, float py, float pz);
		~Player();

		void moveFront(float dt);
		void moveBack(float dt);
		void moveLeft(float dt);
		void moveRight(float dt);
		void moveUp(float dt);
		void moveDown(float dt);
	};
}


#endif