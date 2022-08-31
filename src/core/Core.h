#pragma once

#include <iostream>

#include "../utils/Logger.h"
#include "../utils/Exception.h"

#include "../player/Entity.h"
#include "../player/Player.h"

#include "Object.h"
#include "GameInfo.h"

#include "../event/EventHandler.h"
#include "../event/EventListener.h"

#include <SFML/Graphics.hpp>

class Core {
private:
	std::unique_ptr<sf::RenderWindow> window = nullptr;

	std::vector<Object> objects;

	void init();

public:
	Core();

	void update();

	void addObject(const Object& object);
};