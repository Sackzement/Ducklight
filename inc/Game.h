#pragma once
#include "TimeManager.h"
#include "InputManager.h"
#include "Window.h"
#include "Scene.h"

struct Game {



	TimeManager time_man;
	InputManager input_man;
	Window win;
	bool quit;
	Scene* scene;


	Game();
	void start();
	void mainloop();

	void input(std::vector<SDL_Event>* events);
	//void update();
	void render();


};


extern Game game;