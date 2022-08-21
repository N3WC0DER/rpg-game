#include "Core.h"

Core::Core() {
	try {
		this->init();
	} catch (const Exception& ex) {
		Logger::getInstance()->critical(ex.what());
	}
}

void Core::init() {
	if (DEBUG)
		this->window.reset(new sf::RenderWindow(sf::VideoMode(1120, 630), "RPGame"));
	else 
		this->window.reset(new sf::RenderWindow(sf::VideoMode::getDesktopMode(), "RPGame", sf::Style::Fullscreen));

	this->window->setFramerateLimit(60);

	sf::Texture texture;
	if (!texture.loadFromFile("resources/_Crouch.png")) {
		throw Exception() << "Texture not found";
	}

	Entity entity(texture);

	this->addObject(entity);

	this->update();
}

void Core::update() {
	sf::Clock clock;
	while (this->window->isOpen()) {
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 1400;

		sf::Event event;
		while (this->window->pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				this->window->close();
		}

		this->window->clear();

		for (auto i = this->objects.begin(); i != this->objects.end(); i++) {
			i->update(time);
			window->draw(*i);
		}

		this->window->display();

	}
}

void Core::addObject(const Object& object) {
	this->objects.push_back(object);
}