#pragma once

#include "../Event.h"

#include <SFML/Graphics.hpp>

class MouseWheelEvent : public Event<MouseWheelEvent> {
public:
	sf::Mouse::Wheel direction;
	float delta;

	sf::Vector2i mousePosition;
};