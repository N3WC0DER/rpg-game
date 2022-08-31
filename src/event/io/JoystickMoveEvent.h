#pragma once

#include "../Event.h"

#include <SFML/Graphics.hpp>

class JoystickMoveEvent : public Event<JoystickMoveEvent> {
public:
	sf::Joystick::Axis axis;
	unsigned int joystickID;
	float position;
};