#include "Entity.h"

Entity::Entity()
	: Object() {}

Entity::Entity(const sf::Texture& texture, sf::IntRect rect) 
	: Object(texture, rect) {}

Entity::Entity(const sf::Sprite& sprite)
	: Object(sprite) {}

Entity::Entity(const Entity& other)
	: Object(other) {}

Entity::~Entity() {}

void Entity::update(float elapsedTime) {}
