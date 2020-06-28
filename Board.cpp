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
#include "Pawn.h"

int Board::width = 800;
int Board::height = 800;
int Board::boxHeight = height / 8;
int Board::boxWidth = width / 8;

Board::Board() {
	pickedUpCol = -1;
	pickedUpRow = -1;
	pieces = new char* [8];
	for (int i = 0; i < 8; i++) {
		pieces[i] = new char[8];
	} 

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; ++j) {
			boxes[i][j] = Box(i, j);
		}
	}
	//black pieces.
	boxes[0][0].setPiece(new Rook('b',0,0));
	boxes[0][7].setPiece(new Rook('b',0,7));
	boxes[0][6].setPiece(new Knight('b',0,6));
	boxes[0][1].setPiece(new Knight('b',0,1));
	boxes[0][2].setPiece(new Bishop('b',0,2));
	boxes[0][5].setPiece(new Bishop('b',0,5));
	boxes[0][4].setPiece(new King('b',0,4));
	boxes[0][3].setPiece(new Queen('b',0,3));
	for (int i = 0; i < 8; i++) {
		boxes[1][i].setPiece(new Pawn('b',1,i));
		boxes[6][i].setPiece(new Pawn('w',6,i));
	}


	//white pieces

	boxes[7][0].setPiece(new Rook('w',7,0));
	boxes[7][7].setPiece(new Rook('w',7,7));
	boxes[7][6].setPiece(new Knight('w',7,6));
	boxes[7][1].setPiece(new Knight('w',7,1));
	boxes[7][2].setPiece(new Bishop('w',7,2));
	boxes[7][5].setPiece(new Bishop('w',7,5));
	boxes[7][4].setPiece(new King('w',7,4));
	boxes[7][3].setPiece(new Queen('w',7,3));
	
	updatePieceLocations();



}

Board::~Board() {
	for (int i = 0; i < 8; i++) {
		free(pieces[i]);
	}
	free(pieces);
}


void Board::render() {
	renderBoardBackground();
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (boxes[i][j].getPiece()) {
				
				boxes[i][j].getPiece()->render();
				
			}
		}
	}
}

void Board::renderBoardBackground() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			boxes[i][j].render();
		}
	}
	
}

void Board::highlightSquare(int row, int col) {
	std::cout << "Checking row:" << row << " and col:" << col << std::endl;
	std::vector<int> test = (boxes[row][col].getPiece())->showMoves(row, col,pieces);
	

	for (int i = 0; i < test.size() / 2; i++) {
		boxes[test[i * 2]][test[i * 2 + 1]].toggleHighlight();	//this works because the coordinates are provided 
		//2 in a row, so if I multiply by 2 I can get to the first and the second.
	}

	//boxes[row][col].toggleHighlight();
	
	
}

void Board::updatePieceLocations() {
	for (int row = 0; row < 8; row++) {
		for (int col = 0; col < 8; col++) {
			if (boxes[row][col].getPiece()) {
				pieces[row][col] = boxes[row][col].getPiece()->getTeam();
			}
			else {
				pieces[row][col] = 'e';
			}
		}
	}
}

void Board::printBoard() {
	
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			std::cout << pieces[i][j] << " ";
		}
		std::cout << "\n";
	}
}

void Board::removeSelectedPiece(int row, int col) {
	row = row / 100;
	col = col / 100;
	boxes[row][col].removePiece();

}


void Board::movePiece(int row, int col, char currentTurn) {
	if (pickedUpCol != -1) {
		setDownPiece();
	}
	row = row / 100;
	col = col / 100;
	if (boxes[row][col].getPiece()) {
		if (boxes[row][col].getPiece()->getTeam() == currentTurn) {
			pickedUpRow = row;
			pickedUpCol = col;
			this->highlightSquare(pickedUpRow,pickedUpCol);
			pickUpPiece(pickedUpRow, pickedUpCol);
		}
	}

}

void Board::pickUpPiece(int row, int col) {
	boxes[row][col].getPiece()->drawToMouse();
	
}

void Board::update() {
	if (pickedUpCol != -1) {
		boxes[pickedUpRow][pickedUpCol].getPiece()->drawToMouse();
	}
}


void Board::setDownPiece() {
	boxes[pickedUpRow][pickedUpCol].getPiece()->resetPlace();
	highlightSquare(pickedUpRow, pickedUpCol);
	pickedUpRow = -1;
	pickedUpCol = -1;
	updatePieceLocations();

}
