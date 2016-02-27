#include "../inc/Game.h"

#include "../inc/Libs.h"


Game::Game() :
	time_man    (),
	input_man   (),
	quit        (false)
{}

void Game:: start() {

	Libs::init();

	Window win;
	win.create("Ducklight",100,100,800,600,SDL_WINDOW_SHOWN);
}


void Game::mainloop() {

	time_man.resetDelay();

	while (!quit) {

		time_man.update();
		input_man.pollEvents();
		scene->input(input_man.getPolledEvents());

		scene->render();
		time_man.delay();
	}
}


/*void  Game::input() {

}
void  Game::update() {

}
void  Game::render() {

}*/