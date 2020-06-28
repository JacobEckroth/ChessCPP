#include "Piece.h"
#include "Game.h"
char Piece::getType() {
	return pieceType;
}
 

char Piece::getTeam() {
	return team;
}

void Piece::render() {
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