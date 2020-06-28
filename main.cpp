
#include <iostream>
#include "SDL.h"
#include "Game.h"

#include <cstdlib>  

#include <ctime>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

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
	delete(game);
	_CrtDumpMemoryLeaks();
	return 0;

}