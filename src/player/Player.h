#pragma once

#include <SFML/Graphics.hpp>

#include "Entity.h"

namespace {
enum State {
	Stay,
	MoveUp,
	MoveDown,
	MoveLeft,
	MoveRight
};
}

class Player : public Entity {
private:
	void control(float elapsedTime);

public:
	Player();
	Player(const sf::Texture& texture, sf::IntRect rect = sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(0, 0)));
	Player(const sf::Sprite& sprite);
	Player(const Player& other);
	~Player();

	void update(float elapsedTime);
};

