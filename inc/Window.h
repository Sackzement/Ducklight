#pragma once
#include <SDL/SDL_video.h>

struct GammaRamp {
	Uint16 red, green, blue;
}

class Window {

	SDL_Window*     m_sdlWindow;

	const char*     m_title;

	vec<2,int>      m_pos;
	vec<2,int>      m_size;

	Uint32          m_flags;

	float           m_brightness;

	int             m_displayIdx;
	SDL_DisplayMode m_displayMode;  //when fulscreen

	Uint32          m_id;
	GammaRamp       m_gammaRamp;
	bool            m_grab;
	vec<2,int>      m_maxSize;
	vec<2,int>      m_minSize;

	Uint32          m_pixelFormat;
	SDL_SysWMinfo   m_winSysInfo;

	bool            m_hidden;
	bool            m_minimized;
	bool            m_maximized;
	bool            m_borderless;


public:
	Window();
	bool create(const char* title,int x,int y,int w,int h,Uint32 flags)
}