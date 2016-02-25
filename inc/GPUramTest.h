#pragma once
#include <SDL/SDL.h>
#include <SDL/SDL_video.h>
#include <SDL/SDL_render.h>
#include <iostream>

void testGPUram() {

	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* win = nullptr;
	win = SDL_CreateWindow("GPUramTest",100,100,800,600,SDL_WINDOW_SHOWN);
	SDL_Renderer* ren = nullptr;
	ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);

	SDL_Texture* textures[50] = {};

	for (int i = 0; i < 50; ++i) {
		textures[i] = SDL_CreateTexture(ren, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET,5000, 5000);
		if (textures[i] == nullptr) {
			std::cout << "\n" << SDL_GetError()
				<< "\nAllocated " << i << " Textures of 5000 x 5000 pixels with format rgba8888"
				<< "\n= " << i * 100 << " MB";
			break;
		}
	}
	for (int i = 0; i < 50; ++i) {
		if (textures[i]) {
			SDL_DestroyTexture(textures[i]);
			textures[i] = nullptr;
		}
	}

	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();
}