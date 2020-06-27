#include "Board.h"
#include "Game.h"
#include <iostream>
#include <vector>
#include "Knight.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"

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
	//black pieces.
	boxes[0][0].setPiece(new Rook('b'));
	boxes[0][7].setPiece(new Rook('b'));
	boxes[0][6].setPiece(new Knight('b'));
	boxes[0][1].setPiece(new Knight('b'));
	boxes[0][2].setPiece(new Bishop('b'));
	boxes[0][5].setPiece(new Bishop('b'));
	boxes[0][4].setPiece(new King('b'));
	boxes[0][3].setPiece(new Queen('b'));


	//white pieces
	boxes[7][0].setPiece(new Rook('w'));
	boxes[7][7].setPiece(new Rook('w'));
	boxes[7][6].setPiece(new Knight('w'));
	boxes[7][1].setPiece(new Knight('w'));
	boxes[7][2].setPiece(new Bishop('w'));
	boxes[7][5].setPiece(new Bishop('w'));
	boxes[7][4].setPiece(new King('w'));
	boxes[7][3].setPiece(new Queen('w'));
	boxes[7][3].setPiece(new Queen('w'));





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
	std::vector<int> test;
	if (boxes[row][col].getPiece()) {
		test = (boxes[row][col].getPiece())->showMoves(row, col);
	}

	for (int i = 0; i < test.size() / 2; i++) {
		boxes[test[i * 2]][test[i * 2 + 1]].toggleHighlight();	//this works because the coordinates are provided 
		//2 in a row, so if I multiply by 2 I can get to the first and the second.
	}

	boxes[row][col].toggleHighlight();
	
	
}


