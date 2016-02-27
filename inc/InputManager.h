#pragma once

#include <SDL/SDL_events.h>
#include <vector>


struct InputManager {
private:
	std::vector<SDL_Event> m_polledEvents;
public:
	InputManager();

	void pollEvents();
	std::vector<SDL_Event> * getPolledEvents();
	//void executePolledEvents();
};