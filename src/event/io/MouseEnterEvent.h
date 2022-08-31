#pragma once

#include "../Event.h"

class MouseEnterEvent : public Event<MouseEnterEvent> {
public:
	bool entered;
};