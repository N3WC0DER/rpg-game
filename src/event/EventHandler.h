#pragma once

#include <vector>
#include <functional>

#include "Event.h"

template <typename Ev>
class EventHandler {
private:
	std::vector<std::function<void (const Ev&)>> funcPool;

	EventHandler() = default;
	EventHandler(const EventHandler<Ev>&) = delete;
	EventHandler operator=(const EventHandler<Ev>&) = delete;

	static std::unique_ptr<EventHandler<Ev>> instance;

public:
	static EventHandler<Ev>* getInstance() {
		if (!instance)
			instance.reset(new EventHandler<Ev>());
		return instance.get();
	}

	void addCallable(std::function<void (const Ev&)> func) {
		this->funcPool.push_back(func);
	}

	void callEvent(const Ev& event) {
		for (auto func = this->funcPool.begin(); func != this->funcPool.end(); func++) {
			(*func)(event);
		}
	}
};

template <typename Ev> std::unique_ptr<EventHandler<Ev>> EventHandler<Ev>::instance = nullptr;