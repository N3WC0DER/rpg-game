#include "Object.h"
#include <iostream>

void Object::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(*sprite, states);
}

Object::Object() {}

Object::Object(const sf::Texture& texture, sf::IntRect rect)
	: Object() {
	this->texture = new sf::Texture(texture);
	if (rect.height == 0 && rect.width == 0) {
		this->sprite = new sf::Sprite(texture);
	} else {
		this->sprite = new sf::Sprite(texture, rect);
	}

	this->callibrateOrigin();
}

Object::Object(const sf::Sprite& sprite)
	: Object() {
	this->texture = new sf::Texture(*(sprite.getTexture()));
	this->sprite = new sf::Sprite(sprite);
	this->callibrateOrigin();
}


Object::Object(const Object& other)
	: Object() {
	this->texture = new sf::Texture(other.getTexture());
	this->sprite = new sf::Sprite(other.getSprite());
	this->callibrateOrigin();
}

Object& Object::operator=(const Object& other) {
	this->texture = new sf::Texture(other.getTexture());
	this->sprite = new sf::Sprite(other.getSprite());
	this->callibrateOrigin();
	return *this;
}

Object::~Object() {
	if (this->texture)
		delete this->texture;
	if (this->sprite)
		delete this->sprite;
}

void Object::update(float elapsedTime) {
	
}

void Object::setPosition(const sf::Vector2f& position) {
	this->sprite->setPosition(position);
}

sf::Vector2f Object::getPosition() const {
	return this->sprite->getPosition();
}

void Object::setSprite(const sf::Sprite& sprite) {
	if (this->texture)
		delete this->texture;
	if (this->sprite)
		delete this->sprite;
	this->texture = new sf::Texture(*(sprite.getTexture()));
	this->sprite = new sf::Sprite(sprite);
	this->callibrateOrigin();
}

sf::Sprite Object::getSprite() const {
	if (this->sprite)
		return *this->sprite;
	else 
		throw Exception() << "Object Object does not have a sprite";
}


void Object::setTexture(const sf::Texture& texture) {
	delete this->texture;
	delete this->sprite;
	this->texture = new sf::Texture(texture);
	this->sprite = new sf::Sprite(texture);
	this->callibrateOrigin();
}

sf::Texture Object::getTexture() const {
	if (this->sprite)
		return *this->texture;
	else 
		throw Exception() << "Object Object does not have a texture";
}

void Object::callibrateOrigin() {
	if (this->sprite)
		this->sprite->setOrigin((float) this->sprite->getTextureRect().width / 2, (float) this->sprite->getTextureRect().height / 2);
}