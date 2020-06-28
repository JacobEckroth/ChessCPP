
#include <iostream>
#include "SDL.h"
#include "Game.h"
#define _CRTDBG_MAP_ALLOC  
#include <cstdlib>  
#include <crtdbg.h>  
#include <ctime>

int main(int argc, char**argv) {
	Game* game = new Game();
	game->init("Chess", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, false);
	srand(time(NULL));
	while (game->running()) {
		game->handleEvents();
		game->update();
		game->render();
	}
	
	game->clean();
	
	_CrtDumpMemoryLeaks(); //this doesn't work.
	return 0;

}