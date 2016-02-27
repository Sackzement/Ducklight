#include <SDL/SDL_platform.h>
#include "../inc/Game.h"

#if defined(__WINDOWS__) && (_WINDOWS)
int WinMain
#else
int main
#endif

(int argc, char** argv) {

	Game game;
	game.start();
	return 0;
}