#pragma once
#include <vector>
#include "Box.h";
class Board
{

public:
	Board();
	~Board();
	void render();
	void renderBoardBackground();
	void highlightSquare(int row, int col);
	void updatePieceLocations();
	void printBoard();

	void removeSelectedPiece(int row, int col);

	void movePiece(int y,int  x,char currentTurn);
	void pickUpPiece(int row, int col);
	void setDownPiece();
	void update();


	static int width;
	static int height;
	static int boxHeight;
	static int boxWidth;
private:
	Box boxes[8][8];
	char** pieces;
	int pickedUpCol;
	int pickedUpRow;
};

