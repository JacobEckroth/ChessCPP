#include "BoardBackground.h"
#include "TextureManager.h"
#include "Game.h"
#include <iostream>
void BoardBackground::render() {
	TextureManager::Draw(boardTexture, srcRect, destRect);
}

BoardBackground::BoardBackground(char* boardLink) {
	srcRect.x = srcRect.y = destRect.x = destRect.y = 0;
	srcRect.w = srcRect.h = 8;
	destRect.w = destRect.h = 800;
	
	boardTexture = TextureManager::LoadTexture(boardLink);
	
}
BoardBackground::~BoardBackground() {
	SDL_DestroyTexture(boardTexture);
}