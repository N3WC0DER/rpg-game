#pragma once

#include "../Event.h"

class WindowFocusEvent : public Event<WindowFocusEvent> {
public:
	bool focus;
};