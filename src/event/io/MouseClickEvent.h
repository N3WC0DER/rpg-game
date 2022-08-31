#pragma once

#include "../Event.h"

#include <SFML/Graphics.hpp>

class MouseClickEvent : public Event<MouseClickEvent> {
public:
	sf::Mouse::Button button;
	sf::Vector2i mousePosition;
};