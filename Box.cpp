#include "Box.h"
#include "Board.h"
#include "SDL.h"
#include "Game.h"
int Box::getRow() {
	return row;
}
int Box::getCol() {
	return col;
}
Box::Box(int row, int col) {
	this->row = row;
	this->col = col;
	if ((row + col) % 2 == 0) { //this works to detect every other row. Kinda guessed on this one.
		originalColor[0] = originalColor[1] = originalColor[2] = currentColor[0] = currentColor[1] = currentColor[2] = 255;
	}
	else {
		originalColor[0] = originalColor[2] = originalColor[1] = currentColor[0] = currentColor[1] =currentColor[2]= 0;
	}
	isHighlighted = false;
	
}

bool Box::highlighted() {
	return isHighlighted;
}

void Box::toggleHighlight() {
	if (!isHighlighted) {
		isHighlighted = true;
		currentColor[0] = 188;//random higlight color, feel free to change this
		currentColor[1] = 169;
		currentColor[2] = 225;
	}
	else {
		isHighlighted = false;
		currentColor[0] = originalColor[0];
		currentColor[1] = originalColor[1];
		currentColor[2] = originalColor[2];
	}


}

void Box::render() {
	SDL_Rect rect;
	rect.x = row * Board::boxWidth;
	rect.y = col * Board::boxHeight;
	rect.w = Board::boxWidth;
	rect.h = Board::boxHeight;
	SDL_SetRenderDrawColor(Game::renderer, currentColor[0], currentColor[1], currentColor[2], 255);
	SDL_RenderFillRect(Game::renderer, &rect);
}
Box::Box() {

}
