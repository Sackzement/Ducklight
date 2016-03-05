#include "../inc/Game.h"
#include "../inc/Libs.h"
#include "../inc/MainMenu.h"
#include "../inc/HardwareInfo.h"


Game game;


Game::Game() :
	time_man    (),
	input_man   (),
	quit        (false)
{}

void Game:: start() {

	Libs::init();

	win.create("Ducklight", 0, 0, 1920, 1080, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);// | SDL_WINDOW_BORDERLESS);

	Scene::rescale(win.getSize().x, win.getSize().y);
	scene = new MainMenu();
	scene->load();

	HardwareInfo hwInfo;
	hwInfo.update();
	size_t charsize = sizeof(char);
	size_t hwiSize = sizeof(hwInfo);
	size_t hwiSize2 = sizeof(HardwareInfo);
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

		render();
		
		time_man.delay();
	}
}


void  Game::input(std::vector<SDL_Event>* events) {

	size_t len = events->size();

	for (size_t i=0;i<len;++i) {
		SDL_Event ev = (*events)[i];
		switch ( ev.type ) {
		case SDL_QUIT:
			quit = true;
			break;
		case SDL_WINDOWEVENT: {
			switch (ev.window.event)
			{
			case SDL_WINDOWEVENT_RESIZED:
				win.pullSize();
				Scene::rescale(win.getSize().x, win.getSize().y);
				break;
			}
			break;
		}
		case SDL_KEYDOWN:
			switch (ev.key.keysym.scancode)
			{
			case SDL_SCANCODE_Q:
				quit = true;
				break;
			}
			break;
		}
	}
}
/*void  Game::update() {

}*/
void  Game::render() {

	SDL_SetRenderDrawColor(win.getSdlRenderer(), 0, 255, 0, 255);
	SDL_RenderClear(win.getSdlRenderer());

	scene->render();

	SDL_RenderPresent(win.getSdlRenderer());
}