#pragma once
#include "SDL.h"
#include "SDL_image.h"
class BoardBackground
{
public:
	void render();
	BoardBackground(char* board);
	~BoardBackground();
private:
	SDL_Texture* boardTexture;
	SDL_Rect srcRect;
	SDL_Rect destRect;
};

