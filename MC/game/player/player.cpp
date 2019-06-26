#include "player.h"

namespace mc {
	Player::Player() {

	}

	Player::Player(float px, float py, float pz) : pos(px, py, pz) {
		this->moving_speed = 6.0f;
		this->camera.setPosition(px, py, pz);
		this->camera.setDirectionUp(0.f, 1.f, 0.f);
		this->camera.setCameraFront(0.f, 0.f, -1.f);
	}

	Player::~Player() {

	}

	void Player::moveFront(float dt) {
		float dist = moving_speed * dt;
		this->camera.moveFront(dist);
	}

	void Player::moveBack(float dt) {
		float dist = moving_speed * dt;
		this->camera.moveBack(dist);
	}

	void Player::moveLeft(float dt) {
		float dist = moving_speed * dt;
		this->camera.moveLeft(dist);
	}

	void Player::moveRight(float dt) {
		float dist = moving_speed * dt;
		this->camera.moveRight(dist);
	}

	void Player::moveUp(float dt) {
		float dist = moving_speed * dt;
		this->camera.moveUp(dist);
	}

	void Player::moveDown(float dt) {
		float dist = moving_speed * dt;
		this->camera.moveDown(dist);
	}

	glm::mat4 Player::getViewMatrix() {
		return camera.getViewMatrix();
	}
}