
#include <iostream>
#include "SDL.h"
#include "Game.h"

#include <cstdlib>  

#include <ctime>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <string>
#include "wtypes.h"
bool again();
void calculateWindowSizes(int&, int&);

int main(int argc, char**argv) {
	Game* game; 
	
	srand(time(NULL));
	bool playAgain = true;

	int windowWidth = 800;
	int windowHeight = 800;
	calculateWindowSizes(windowWidth, windowHeight);

	while (playAgain) {
		game = new Game;
		game->init("Chess", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, false);
		while (game->running()) {
			game->handleEvents();
			game->update();
			game->render();
			game->checkForWinner();
		}
		SDL_Delay(1000);	//delay to show board before deleting it.
		game->clean();
		delete(game);
		playAgain = again();
		Game::winner = 'n';
	}
	
	_CrtDumpMemoryLeaks();
	return 0;
}

void calculateWindowSizes(int& windowWidth, int& windowHeight) {
	RECT desktop;
	const HWND hDesktop = GetDesktopWindow();
	GetWindowRect(hDesktop, &desktop);
	
	int vertical = desktop.bottom;
	
	vertical =  int(vertical * .8);
	while (vertical % 8 != 0) {
		vertical--;
	}
	windowWidth = vertical;
	windowHeight = vertical;


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