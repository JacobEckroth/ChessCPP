
#include <iostream>
#include "SDL.h"
#include "Game.h"

#include <cstdlib>  

#include <ctime>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <string>

bool again();

int main(int argc, char**argv) {
	Game* game; 
	
	srand(time(NULL));
	bool playAgain = true;
	while (playAgain) {
		game = new Game;
		game->init("Chess", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, false);
		while (game->running()) {
			game->handleEvents();
			game->update();
			game->render();
			game->checkForWinner();
		}
		SDL_Delay(3000);	//delay to show board before deleting it.
		game->clean();
		delete(game);
		playAgain = again();
		Game::winner = 'n';
	}
	
	_CrtDumpMemoryLeaks();
	return 0;
}


bool again() {
	std::cout << "Play again? yes or no?" << std::endl;
	std::string userInput = "";
	bool validInput = false;
	while (!validInput) {
		std::getline(std::cin, userInput);
		if (userInput == "yes" || userInput == "no") {
			validInput = true;
		}
		else {
			std::cout << "Invalid input! Please enter yes or no!" << std::endl;
		}

	}
	if (userInput == "yes") {
		return true;
	}
	else {
		return false;
	}
}