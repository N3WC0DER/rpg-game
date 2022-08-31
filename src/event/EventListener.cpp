#include "EventListener.h"

void EventListener::pollEvent(sf::RenderWindow* window) {
	sf::Event event;
	while (window->pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			WindowCloseEvent ev;
			ev.window = window;
			ev.call();
		} else if (event.type == sf::Event::Resized) {
			WindowResizeEvent ev;
			ev.size = event.size;
			ev.call();
		} else if (event.type == sf::Event::LostFocus) {
			WindowFocusEvent ev;
			ev.focus = false;
			ev.call();
		} else if (event.type == sf::Event::GainedFocus) {
			WindowFocusEvent ev;
			ev.focus = true;
			ev.call();
		} else if (event.type == sf::Event::TextEntered) {
			if (event.text.unicode < 128) {
				TextEnterEvent ev;
				ev.unicode = static_cast<char>(event.text.unicode);
				ev.call();
			} else {
				Logger::getInstance()->debug(LogMessage() << "Not ASCII: " << static_cast<char>(event.text.unicode));
			}
		} else if (event.type == sf::Event::KeyPressed) {
			KeyPressEvent ev;
			ev.pressed = true;
			ev.code = event.key.code;
			ev.alt = event.key.alt;
			ev.control = event.key.control;
			ev.shift = event.key.shift;
			ev.system = event.key.system;
			ev.call();
		} else if (event.type == sf::Event::KeyReleased) {
			KeyPressEvent ev;
			ev.pressed = false;
			ev.code = event.key.code;
			ev.alt = event.key.alt;
			ev.control = event.key.control;
			ev.shift = event.key.shift;
			ev.system = event.key.system;
			ev.call();
		} else if (event.type == sf::Event::MouseWheelScrolled) {
			MouseWheelEvent ev;
			ev.direction = event.mouseWheelScroll.wheel;
			ev.delta = event.mouseWheelScroll.delta;
			ev.mousePosition = sf::Vector2i(event.mouseWheelScroll.x, event.mouseWheelScroll.y);
			ev.call();
		} else if (event.type == sf::Event::MouseButtonPressed) {
			MouseClickEvent ev;
			ev.button = event.mouseButton.button;
			ev.mousePosition = sf::Vector2i(event.mouseButton.x, event.mouseButton.y);
			ev.call();
		} else if (event.type == sf::Event::MouseMoved) {
			MouseMoveEvent ev;
			ev.mousePosition = sf::Vector2i(event.mouseMove.x, event.mouseMove.y);
			ev.call();
		} else if (event.type == sf::Event::MouseEntered) {
			MouseEnterEvent ev;
			ev.entered = true;
			ev.call();
		} else if (event.type == sf::Event::MouseLeft) {
			MouseEnterEvent ev;
			ev.entered = false;
			ev.call();
		} else if (event.type == sf::Event::JoystickButtonPressed) {
			JoystickButtonEvent ev;
			ev.pressed = true;
			ev.joystickID = event.joystickButton.joystickId;
			ev.button = event.joystickButton.button;
			ev.call();
		} else if (event.type == sf::Event::JoystickMoved) {
			JoystickMoveEvent ev;
			ev.axis = event.joystickMove.axis;
			ev.joystickID = event.joystickMove.joystickId;
			ev.position = event.joystickMove.position;
			ev.call();
		} else if (event.type == sf::Event::JoystickConnected) {
			JoystickConnectEvent ev;
			ev.connected = true;
			ev.call();
		} else if (event.type == sf::Event::JoystickDisconnected) {
			JoystickConnectEvent ev;
			ev.connected = false;
			ev.call();
		}
	}
}