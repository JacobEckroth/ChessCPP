#pragma once
#include "Piece.h";
class Box
{
public:
	int getRow();
	int getCol();
	Box();
	~Box();
	Box(int,int);
	bool highlighted();
	void toggleHighlight(char currentPlayer);
	void render();
	void setPiece(Piece* newPiece);
	void toggleTargeted(bool);
	Piece* getPiece() {
		return piece;
	};
	void removePiece();
	

private:
	SDL_Rect destRect;
	int row;
	int col;
	Uint8 r;
	Uint8 g;
	Uint8 b;
	Uint8 a;
	
	bool isHighlighted;
	bool isTargeted;
	Piece* piece;

};

