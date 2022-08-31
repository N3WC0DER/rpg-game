#pragma once

#include "../Event.h"

class WindowResizeEvent : public Event<WindowResizeEvent> {
public:
	sf::Event::SizeEvent size;
};