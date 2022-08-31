#pragma once

#include "../Event.h"

class JoystickButtonEvent : public Event<JoystickButtonEvent> {
public:
	bool pressed;
	unsigned int joystickID;
	unsigned int button;
};