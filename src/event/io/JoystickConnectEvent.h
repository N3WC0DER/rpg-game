#pragma once

#include "../Event.h"

class JoystickConnectEvent : public Event<JoystickConnectEvent> {
public:
	bool connected;
};