#include "../inc/Game.h"

#include "../inc/Libs.h"

#include "../inc/MainMenu.h"


Game::Game() :
	time_man    (),
	input_man   (),
	quit        (false)
{}

void Game:: start() {

	Libs::init();

	win.create("Ducklight",100,100,800,600,SDL_WINDOW_SHOWN);

	scene = new MainMenu();

	mainloop();

	delete scene;

	win.destroy();
}


void Game::mainloop() {

	time_man.resetDelay();

	while (!quit) {

		time_man.update();
		
		input_man.pollEvents();
		input(input_man.getPolledEvents());
		scene->input(input_man.getPolledEvents());

		scene->update();

		scene->render();
		
		time_man.delay();
	}
}


void  Game::input(std::vector<SDL_Event>* events) {

	size_t len = events->size();

	for (size_t i=0;i<len;++i) {
		switch ( (*events)[i].type ) {
		case SDL_QUIT:
			quit = true;
			break;
		}
	}
}
/*void  Game::update() {

}
void  Game::render() {

}*/