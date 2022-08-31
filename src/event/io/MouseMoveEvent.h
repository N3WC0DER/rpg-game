#pragma once

#include "../Event.h"

#include <SFML/Graphics.hpp>

class MouseMoveEvent : public Event<MouseMoveEvent> {
public:
	sf::Vector2i mousePosition;
};