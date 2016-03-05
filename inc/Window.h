#pragma once
#include <SDL/SDL_video.h>
#include <SDL/SDL_render.h>
#include "types.h"


struct GammaRamp {
	Uint16 red, green, blue;
};


class Window {

	SDL_Window*     m_sdlWindow;
	SDL_Renderer*   m_sdlRenderer;

	Size2<int>            m_size;


public:
	Window();
	bool create(const char* title,int x,int y,int w,int h,Uint32 flags);
	void destroy();

	SDL_Window*     getSdlWindow() const;
	SDL_Renderer*   getSdlRenderer() const;
	

	void pullSize();
	Size2<int> getSize() const;

};