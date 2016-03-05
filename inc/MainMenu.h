#pragma once
#include "Scene.h"

class MainMenu : public Scene {



public:
	void load() override;
	void input(std::vector<SDL_Event>* events) override;
	void update() override;
	void render(Transform2d offset = Transform2d()) override;
	void unload() override;

};