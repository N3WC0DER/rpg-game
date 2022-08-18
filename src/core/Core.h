#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>

class Core {
private:
	std::unique_ptr<sf::RenderWindow> window = nullptr;
public:
	Core();
};