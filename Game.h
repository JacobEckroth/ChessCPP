#pragma once
#include "SDL.h"
#include "Board.h"

#undef main
class Game
{
public:	
	Game();
	~Game();
	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void update();
	void handleEvents();
	void clean();
	void render();
	void handleMousePress(SDL_MouseButtonEvent& b);


	void checkForWinner();
	bool running();

	static char winner;
	static SDL_Renderer* renderer;
	static char currentTurn;
private:
	bool isRunning;
	SDL_Window* window;
	Board* board;

	


	

	
};

