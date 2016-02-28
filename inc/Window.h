#pragma once
#include <SDL/SDL_video.h>
#include <SDL/SDL_render.h>

struct GammaRamp {
	Uint16 red, green, blue;
};

struct Size2i {
	int x = 0,
		y = 0;
};
class Window {

	SDL_Window*     m_sdlWindow;
	SDL_Renderer*   m_sdlRenderer;

	Size2i            m_size;


public:
	Window();
	bool create(const char* title,int x,int y,int w,int h,Uint32 flags);
	void destroy();
};