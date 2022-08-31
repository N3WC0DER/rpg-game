#pragma once

#include "../Event.h"

#include <SFML/Graphics.hpp>

class WindowCloseEvent : public Event<WindowCloseEvent> {
public:
	sf::Window* window = nullptr;
};