#pragma once
#include "TimeManager.h"
#include "InputManager.h"
#include "Window.h"
#include "Scene.h"

class Game {

	TimeManager time_man;
	InputManager input_man;
	Window win;
	bool quit;
	Scene* scene;
public:
	void start();

	void mainloop();

	/*void input();
	void update();
	void render();*/


	Game();
};