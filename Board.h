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
	void highlightSquare(int row, int col,char);
	void updatePieceLocations(Box**,char**&);
	void printBoard(char**);

	void removeSelectedPiece(int row, int col,char);

	void movePiece(int y,int  x,char& currentTurn);
	void pickUpPiece(int row, int col);
	void setDownPiece(char &currentTurn,Box**& checkBoxes);
	void update();
	void attemptMove(char&,Box**& checkBoxes);
	bool blackKingInCheck(Box** searchBoxes,char**);
	bool whiteKingInCheck(Box** searchBoxes,char**);
	void findKingRow(int& kingRow, int& kingCol, char team,Box** searchBoxes);
	char checkForCheckmate(char currentTeam);
	void freeBoardCopy(Box**,char**&);
	void remakeBoardCopy(Box**&,char**&,bool&);
	bool stillInCheckAfterThis(Box**&, char**&, int, int, int, int,char);
	static int width;
	static int height;
	static int boxHeight;
	static int boxWidth;
private:
	Box** boxes;
	char** pieces;
	int pickedUpCol;
	int pickedUpRow;
};

