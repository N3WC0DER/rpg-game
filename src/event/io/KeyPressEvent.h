#pragma once

#include "../Event.h"

#include <SFML/Graphics.hpp>

class KeyPressEvent : public Event<KeyPressEvent> {
public:
	bool pressed;
	sf::Keyboard::Key code;
	bool control;
	bool alt;
	bool shift;
	bool system;
};