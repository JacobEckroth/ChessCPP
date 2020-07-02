#pragma once
#include "Piece.h";
class bigPieces
{
public:
	void render(char);
	bigPieces();
	~bigPieces();
private:
	Piece** whitePieces;
	Piece** blackPieces;
};

