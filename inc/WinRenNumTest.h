#pragma once
#include <SDL/SDL.h>
#include <SDL/SDL_video.h>
#include <SDL/SDL_render.h>
#include <iostream>

void testWinRen() {
	SDL_Init(SDL_INIT_EVERYTHING);

	// test num windows
	SDL_Window* wins[24] = {};

	for (int i = 0; i < 24; ++i) {
		wins[i] = SDL_CreateWindow("GPUramTest", 100, 100, 800, 600, SDL_WINDOW_SHOWN);
		if (wins[i] == nullptr) {
			std::cout << "\n " << i <<"  " << SDL_GetError();
		}
	}

	SDL_Renderer* rens[24] = {};
	for (int i = 0; i < 24; ++i) {
		rens[i] = SDL_CreateRenderer(wins[i], -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);
		if (rens[i] == nullptr) {
			std::cout << "\n " << i << "  " << SDL_GetError();
		}
	}
}