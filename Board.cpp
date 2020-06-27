#include "Board.h"
#include "Game.h"
#include <iostream>
#include <vector>

int Board::width = 800;
int Board::height = 800;
int Board::boxHeight = height / 8;
int Board::boxWidth = width / 8;
Board::Board() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; ++j) {
			boxes[i][j] = Box(i, j);
		}
	}

}

Board::~Board() {
}


void Board::render() {
	renderBoardBackground();
}

void Board::renderBoardBackground() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			boxes[i][j].render();
		}
	}
}

void Board::highlightSquare(int row, int col) {
	
	row = row / 100;
	col = col / 100;
	boxes[row][col].toggleHighlight();
	
	
}


