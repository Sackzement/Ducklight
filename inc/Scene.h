#pragma once
#include <vector>
#include <SDL/SDL_events.h>

class Scene {
public:
	virtual void load() = 0;
	virtual void input(std::vector<SDL_Event>* events) = 0;
	virtual void update() = 0;
	virtual void render() = 0;
	virtual void unload() = 0;
};