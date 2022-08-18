#include "Core.h"

Core::Core() {
	this->window.reset(new sf::RenderWindow(sf::VideoMode::getDesktopMode(), "RPGame"));
	this->window->setPosition(sf::Vector2i(0, 0));
	this->window->setVerticalSyncEnabled(true);

	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::White);

	while (this->window->isOpen()) {
		sf::Event event;
		while (this->window->pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				this->window->close();
		}

		this->window->clear();
		this->window->draw(shape);
		this->window->display();
	}
}