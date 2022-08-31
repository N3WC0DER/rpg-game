#pragma once

#include "../utils/Exception.h"

#include "SFML/Graphics.hpp"

class Object : public sf::Drawable {
protected:
	sf::Texture* texture = nullptr;
	sf::Sprite* sprite = nullptr;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:
	Object();
	Object(const sf::Texture& texture, sf::IntRect rect = sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(0, 0)));
	Object(const sf::Sprite& sprite);
	Object(const Object& other);
	Object& operator=(const Object& other);
	~Object();
	
	virtual void update(float elapsedTime);

protected:
	void setPosition(const sf::Vector2f& position);
	sf::Vector2f getPosition() const;

	void setTexture(const sf::Texture& texture);
	sf::Texture getTexture() const;

	void setSprite(const sf::Sprite& sprite);
	sf::Sprite getSprite() const;

	void callibrateOrigin();
};