#include "Game.h"
#include <iostream>
SDL_Renderer* Game::renderer = nullptr;
char Game::winner = 'n';
char Game::currentTurn = 'w';
void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
	int flags = 0;
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Subsystems Initialized!\n";
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window) {
			std::cout << "Window Created!\n";
		}
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer created!\n";
			SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
		}
		isRunning = true;
	}
	else {
		isRunning = false;
	}
	
	board = new Board((char*)("images/tanBackground.png"),width,height);
	currentTurn = 'w';
	
}

void Game::clean() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);	//error here
	
	SDL_Quit();
	delete(board);	//gets rid of the board allocated.
	std::cout << "Succesfully cleaned!\n";
	
}

void Game::checkForWinner() {
	if (Game::winner == 'w') {
		std::cout << "White wins";
		isRunning = false;
	}
	else if (Game::winner== 'b') {
		std::cout << "Black wins!" << std::endl;
		isRunning = false;
	}
}

void Game::update() {
	board->update();
	
}

void Game::handleEvents() {
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;
	case SDL_MOUSEBUTTONDOWN:
		handleMousePress(event.button);
	default:
		break;
	}
}


void Game::handleMousePress(SDL_MouseButtonEvent& button) {
	int x, y;
	if (button.button == SDL_BUTTON_LEFT){
		
		SDL_GetMouseState(&x, &y);
		
		board->movePiece(y, x,currentTurn); 
	}
	else if (button.button == SDL_BUTTON_RIGHT) {	//delete the piece if you right click
		
		SDL_GetMouseState(&x, &y);
		
	}
	
}

void Game::render() {
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);
	board->render(board->getBoxes());	//the pieces?
	SDL_RenderPresent(Game::renderer);

	
}

bool Game::running() {
	return isRunning;
}

Game::Game() {

}

Game::~Game() {

}