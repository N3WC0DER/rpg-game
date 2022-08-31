#include "Player.h"

void Player::control(float elapsedTime) {

}

Player::Player()
	: Entity() {}

Player::Player(const sf::Texture& texture, sf::IntRect rect) 
	: Entity(texture, rect) {}

Player::Player(const sf::Sprite& sprite)
	: Entity(sprite) {}

Player::Player(const Player& other)
	: Entity(other) {}

Player::~Player() {}

void Player::update(float elapsedTime) {
	// this->control(elapsedTime);
}