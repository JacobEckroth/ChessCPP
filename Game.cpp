#include "Game.h"
#include <iostream>
SDL_Renderer* Game::renderer = nullptr;

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
		}
		isRunning = true;
	}
	else {
		isRunning = false;
	}
	board = new Board();
	currentTurn = 'w';
}

void Game::clean() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	std::cout << "Succesfully cleaned!\n";
	
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
		std::cout << "Left Mouse Button Pressed\n";	//assumning that if left button is pressed we want to press.
		SDL_GetMouseState(&x, &y);
		board->movePiece(y, x,currentTurn); 
	}
	else if (button.button == SDL_BUTTON_RIGHT) {	//delete the piece if you right click
		std::cout << "Right button pressed\n";
		SDL_GetMouseState(&x, &y);
		board->removeSelectedPiece(y, x);
		board->updatePieceLocations();
	}
	
}

void Game::render() {
	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
	SDL_RenderClear(renderer);
	board->render();
	SDL_RenderPresent(renderer);
}

bool Game::running() {
	return isRunning;
}

Game::Game() {

}

Game::~Game() {

}