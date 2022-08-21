#pragma once

#include "../core/Object.h"

#include <SFML/Graphics.hpp>

class Entity : public Object {
private:
	
public:
	Entity();
	Entity(const sf::Texture& texture, sf::IntRect rect = sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(0, 0)));
	Entity(const sf::Sprite& sprite);
	Entity(const Entity& other);
	// Entity& operator=(const Entity& other);
	~Entity();

	void move(sf::Vector2f position);
};

