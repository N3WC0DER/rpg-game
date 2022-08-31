#pragma once

#include "../Event.h"

class TextEnterEvent : public Event<TextEnterEvent> {
public:
	char unicode;
};