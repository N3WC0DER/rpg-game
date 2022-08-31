#pragma once

#include "Events.h"

#include "../utils/Logger.h"

#include <SFML/Graphics.hpp>

class EventListener {
public:
	void pollEvent(sf::RenderWindow* window);
};