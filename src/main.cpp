#include <SDL/SDL_platform.h>
#include "../inc/WinRenNumTest.h"

#if defined(__WINDOWS__) && (_WINDOWS)
int WinMain
#else
int main
#endif

(int argc, char** argv) {

	testWinRen();
	return 0;
}