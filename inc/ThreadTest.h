#pragma once
#include "Libs.h"
#include "HardwareInfo.h"
#include <iostream>
#include <SDL/SDL_events.h>
#include <SDL/SDL_video.h>
#include <SDL/SDL_render.h>
#include "Log.h"
#include <SDL/SDL_timer.h>
#include <SDL/SDL_thread.h>


bool           running   = true;
SDL_Window*    window    = nullptr;
SDL_Renderer*  renderer  = nullptr;
int *          array     = nullptr;
const size_t   lenArray  = 1200000000;  // 400 Million -> doing  %31 with it
const int     numThreads = 12;


void quit() {
	running = false;
}


bool openWindow() {
	if (window) {
		Log("\nCan not create Window.  Window already exists.");
		return false;
	}

	window = SDL_CreateWindow("ThreadTest", 1000, 100, 800, 600, SDL_WINDOW_SHOWN);

	if (!window) {
		Log(std::string("\n") + SDL_GetError());
		return false;
	}

	renderer = SDL_GetRenderer(window);
	if (renderer) {
		SDL_DestroyRenderer(renderer);
		renderer = nullptr;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);

	if (!renderer) {
		Log(std::string("\n") + SDL_GetError());
		SDL_DestroyWindow(window);
		return false;
	}

	return true;
}
void closeWindow() {
	SDL_DestroyRenderer(renderer);
	renderer = nullptr;

	SDL_DestroyWindow(window);
	window = nullptr;
}

struct ThreadData {
	size_t start = 0;
	size_t len   = lenArray;
};
int threadFunc(void* data) {
	ThreadData dat;
	dat.start  = ((ThreadData*)data)->start;
	dat.len    = ((ThreadData*)data)->len;
	size_t end = dat.start + dat.len;

	for (;dat.start<end;++dat.start) {
		array[dat.start] ++;
	}

	return 0;
}

void input() {
	SDL_Event ev;
	while (SDL_PollEvent(&ev)) {
		switch (ev.type)
		{
		case SDL_KEYDOWN:
			SDL_Scancode code = ev.key.keysym.scancode;
			switch (code) {
			case SDL_SCANCODE_Q:
				quit();
				break;
			}
			break;
		}
	}
}
int testState = 0;
void update() {
	int arrI = array[0];
	switch (testState) {
	case 0: { // SINGLE
		size_t passed = SDL_GetTicks();

		for (size_t i = 0; i < lenArray; ++i)
			array[i] ++;

		passed = SDL_GetTicks() - passed;
		std::cout << "\n\nSINGLE\t\t" << passed;

		++testState;
		break;
	}
	case 1: { // SINGLE THREAD
		ThreadData dat;
		size_t passed = SDL_GetTicks();


		SDL_Thread* thread = SDL_CreateThread(threadFunc, "singlethread", &dat);
		if (thread == nullptr)
			std::cout << "\n" << SDL_GetError();
		
		SDL_WaitThread(thread, nullptr);



		passed = SDL_GetTicks() - passed;
		std::cout << "\nSINGLE THREAD\t" << passed;

		++testState;
		break;
	}
	case 2: { // MULTI THREAD

		if (lenArray < numThreads) {
			// run single thread
		}
		else { 

			// print forst thread int
			std::cout << "\nBEFORE ";
			for(int i=0;i<numThreads;++i)
				std::cout << array[i*(lenArray / numThreads)] << " ";
			std::cout << array[lenArray-1] << " ";

			size_t passed = SDL_GetTicks();

			ThreadData thread_datas[numThreads];
			size_t offset = lenArray / numThreads;
			for (int i = 0; i < numThreads; ++i) {
				thread_datas[i].start = i * offset;
				thread_datas[i].len = offset;
			}
			size_t remainder = lenArray % numThreads;
			for (size_t i=0;i<remainder;++i)
				++thread_datas[i].len;
			for (int i = 1; i < numThreads; ++i)
				thread_datas[i].start = thread_datas[i-1].start + thread_datas[i-1].len;


			SDL_Thread* threads[numThreads-1] = {};

			for (int i=0;i<(numThreads-1);++i) {
				std::string name = std::string("thread");
				name += i;
				threads[i] = SDL_CreateThread(threadFunc, name.c_str(), &thread_datas[i]);
				if (threads[i] == nullptr)
					std::cout << "\n" << SDL_GetError();
			}
			threadFunc(&thread_datas[numThreads-1]);

			for (int i = 0; i < (numThreads - 1); ++i)
				SDL_WaitThread(threads[i],nullptr);

			passed = SDL_GetTicks() - passed;
			std::cout << "\nMULTI THREAD\t" << passed;

			std::cout << "\nAFTER ";
			for (int i = 0; i<numThreads; ++i)
				std::cout << array[i*(lenArray / numThreads)] << " ";
			std::cout << array[lenArray -1] << " ";


		}
		

		testState = 0;
		break;
	}
	}

}
void render() {
	SDL_SetRenderDrawColor(renderer,0,0,0,255);
	SDL_RenderClear(renderer);

	//render stuff

	SDL_RenderPresent(renderer);
}

void mainloop() {
	while (running) {
		input();
		update();
		render();
		SDL_Delay(static_cast<Uint32>(1./60.));
	}
}
void start() {
	array = new int[lenArray]();
	Libs::init();
	HardwareInfo hwi;
	hwi.update();

	openWindow();

	mainloop();

	closeWindow();
	Libs::quit();
	delete array;
}
