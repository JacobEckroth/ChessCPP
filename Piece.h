#pragma once
#include <vector>
#include "SDL_image.h"
class Piece
{
public:
	~Piece();
	virtual std::vector<int> showMoves(int row, int col,char**) = 0;
	 char getType();
	 char getTeam();
	 void setType(char);
	 void render();
	 void drawToMouse();
	 void resetPlace();
	 virtual bool attemptMove(int row, int col,char**) = 0;
	 void setRow(int row) {
		 this->row = row;
	 }
	 void setCol(int col) {
		 this->col = col;
	 }
	 void setMoved() {
		 hasMoved = true;
	 }
	 void resetMoved(bool newMoved) {
		 hasMoved = newMoved;
	 }
	 bool moved() {
		 return hasMoved;
	 }

protected:
	char pieceType;
	bool pickedUp;
	char team;	//0 if black 1 if white
	SDL_Texture* pieceTexture;
	SDL_Rect srcRect;
	SDL_Rect destRect;
	int row;
	int col;
	bool hasMoved;
};

