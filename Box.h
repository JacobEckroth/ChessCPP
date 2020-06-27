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
	void toggleHighlight();
	void render();
	void setPiece(Piece* newPiece);
	Piece* getPiece() {
		return piece;
	};
	void removePiece();
private:
	int row;
	int col;
	int currentColor[3];
	int originalColor[3];
	bool isHighlighted;
	Piece* piece;
};

