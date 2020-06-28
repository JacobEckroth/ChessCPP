#include "Piece.h"
#include "Game.h"
#include <iostream>
char Piece::getType() {
	return pieceType;
}
 

char Piece::getTeam() {
	return team;
}

void Piece::render() {
	SDL_SetRenderDrawColor(Game::renderer, 255, 255, 255, 255);
	SDL_RenderCopy(Game::renderer, pieceTexture, &srcRect, &destRect);
}

void Piece::drawToMouse() {
	int x, y;
	SDL_GetMouseState(&x, &y);
	destRect.x = x - 50;
	destRect.y = y - 50;
	
	pickedUp = true;
}
void Piece::resetPlace() {
	destRect.x = col * 100;
	destRect.y = row * 100;
}
Piece::~Piece() {
	if (pieceTexture) {
		
		SDL_DestroyTexture(pieceTexture);
	}
	
}