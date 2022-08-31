#pragma once

#include "EventHandler.h"

template <typename Ev>
class Event {
public:
	void call() {
		EventHandler<Ev>::getInstance()->callEvent(static_cast<const Ev&>(*this));
	}
};