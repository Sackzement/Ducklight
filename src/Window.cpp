#include "../inc/Window.h"
#include "../inc/Log.h"



Window::Window() : m_sdlWindow(nullptr), m_sdlRenderer(nullptr) {}


bool Window::create(const char* title,int x,int y,int w,int h,Uint32 flags) {

	if (m_sdlWindow) {
		Log("\nCan not create Window.  Window already exists.");
		return false;
	}

	m_sdlWindow = SDL_CreateWindow(title, x, y, w, h, flags);

	if (!m_sdlWindow) {
		Log(std::string("\n") + SDL_GetError());
		return false;
	}

	m_sdlRenderer = SDL_GetRenderer(m_sdlWindow);
	if (m_sdlRenderer) {
		SDL_DestroyRenderer(m_sdlRenderer);
		m_sdlRenderer = nullptr;
	}

	m_sdlRenderer = SDL_CreateRenderer(m_sdlWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);

	if (!m_sdlRenderer) {
		Log(std::string("\n") + SDL_GetError());
		SDL_DestroyWindow(m_sdlWindow);
		return false;
	}

	return true;
}


void Window::destroy() {

	SDL_DestroyRenderer(m_sdlRenderer);
	m_sdlRenderer = nullptr;

	SDL_DestroyWindow(m_sdlWindow);
	m_sdlWindow = nullptr;
}




























