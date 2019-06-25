#include "player.h"

namespace game {
	Player::Player() {

	}

	Player::Player(float px, float py, float pz) {
		camera.setPosition(px, py, pz);
	}

	Player::~Player() {

	}

	void Player::moveFront(float dt) {
		camera.moveFront(dt);
	}

	void Player::moveBack(float dt) {
		camera.moveBack(dt);
	}

	void Player::moveLeft(float dt) {
		camera.moveLeft(dt);
	}

	void Player::moveRight(float dt) {
		camera.moveRight(dt);
	}

	void Player::moveUp(float dt) {
		camera.moveUp(dt);
	}

	void Player::moveDown(float dt) {
		camera.moveDown(dt);
	}
}