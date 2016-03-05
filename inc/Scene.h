#pragma once
#include <vector>
#include <SDL/SDL_events.h>
#include "types.h"




class Scene : public GameObject {

	static const Size2<int> m_aspectR;
	static double m_scale;

public:
	virtual void load() = 0;
	virtual void input(std::vector<SDL_Event>* events) = 0;
	virtual void update() = 0;
	virtual void render(Transform2d offset = Transform2d()) = 0;
	virtual void unload() = 0;

	static void rescale(int w,int h);
	static Size2<int> getAspectR();
	static double getScale();
};


