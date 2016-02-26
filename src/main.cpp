#include <SDL/SDL_platform.h>
#include "../inc/vec.h"

#if defined(__WINDOWS__) && (_WINDOWS)
int WinMain
#else
int main
#endif

(int argc, char** argv) {


	vec<5, int> ulu1;
	vec<5, int> ulu3({});
	vec<5, int> ulu4({1,2,3});
	vec<5, int> ulu5({1,2,3,4,5,6,7});
	ulu1[2] = 5;

	return 0;
}