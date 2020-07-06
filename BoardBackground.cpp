#include "BoardBackground.h"
#include "TextureManager.h"
#include "Game.h"
#include "Board.h"
#include <iostream>
void BoardBackground::render() {
	TextureManager::Draw(boardTexture, srcRect, destRect);
}

BoardBackground::BoardBackground(char* boardLink) {
	srcRect.x = srcRect.y = destRect.x = destRect.y = 0;
	srcRect.w = srcRect.h = 8;
	destRect.w = destRect.h = Board::width;
	
	boardTexture = TextureManager::LoadTexture(boardLink);
	
}
BoardBackground::~BoardBackground() {
	SDL_DestroyTexture(boardTexture);
}