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
	this->window->setKeyRepeatEnabled(false);

	sf::Texture texture;
	if (!texture.loadFromFile("resources/_Crouch.png")) {
		throw Exception() << "Texture not found";
	}

	Player player(texture);

	this->addObject(player);
	EventHandler<WindowCloseEvent>::getInstance()->addCallable([] (const WindowCloseEvent& event) {
		if (event.window)
			event.window->close();
		else
			throw Exception() << "Window not closed";
	});

	this->update();
}

void Core::update() {
	sf::Clock clock;
	EventListener listener;
	while (this->window->isOpen()) {
		float time = clock.getElapsedTime().asSeconds();
		clock.restart();

		listener.pollEvent(this->window.get());

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