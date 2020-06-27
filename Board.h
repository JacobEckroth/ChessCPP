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
	static int width;
	static int height;
	static int boxHeight;
	static int boxWidth;
private:
	Box boxes[8][8];
	char pieces[8][8];
};

