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

Board::Board(char* boardBackgroundLink) {
	std::cout << "Size of Piece:" << sizeof(Piece) << std::endl;
	std::cout << "Size of Box:" << sizeof(Box) << std::endl;
	
	boardBackground = new BoardBackground(boardBackgroundLink);
	std::cout << "Board background link is: " << boardBackgroundLink;
	pickedUpCol = -1;
	pickedUpRow = -1;
	pieces = new char* [8];
	boxes = new Box * [8];
	for (int i = 0; i < 8; i++) {
		pieces[i] = new char[8];
		boxes[i] = new Box [8];
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
	
	updatePieceLocations(boxes,pieces);

	

}


Board::~Board() {
	for (int i = 0; i < 8; i++) {
		delete [](pieces[i]);
		delete[] boxes[i];
	}
	delete[] boxes;
	delete [](pieces);
	delete boardBackground;
	
}


void Board::render(Box** renderBoxes) {
	renderBoardBackground();
	
	

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			boxes[i][j].render();//make this better
			if (boxes[i][j].getPiece()) {
				if (i != pickedUpRow || j != pickedUpCol) {
					boxes[i][j].getPiece()->render();
					
				}
				
				
				
			}
		}
	}
	if (pickedUpCol != -1) {
		boxes[pickedUpRow][pickedUpCol].getPiece()->render();
		boxes[pickedUpRow][pickedUpCol].getPiece()->drawToMouse();
	}
}

void Board::renderBoardBackground() {
	boardBackground->render();
}

void Board::highlightSquare(int row, int col,char currentTurn) {
	std::vector<int> test = (boxes[row][col].getPiece())->showMoves(row, col,pieces);
	

	for (int i = 0; i < test.size() / 2; i++) {
		boxes[test[i * 2]][test[i * 2 + 1]].toggleHighlight(currentTurn);	//this works because the coordinates are provided 
		//2 in a row, so if I multiply by 2 I can get to the first and the second.
	}

	//boxes[row][col].toggleHighlight();
	
	
}

void Board::updatePieceLocations(Box** checkBoxes, char**& checkPieces) {
	for (int row = 0; row < 8; row++) {
		for (int col = 0; col < 8; col++) {
			if (checkBoxes[row][col].getPiece() ) {
				
				checkPieces[row][col] = checkBoxes[row][col].getPiece()->getTeam(); 
				
			}
			else {
				checkPieces[row][col] = 'e';
			}
		}
	}
}

void Board::printBoard(char** printPieces) {
	
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			std::cout << printPieces[i][j] << " ";
		}
		std::cout << "\n";
	}
}

void Board::removeSelectedPiece(int row, int col,char currentTurn) {
	setDownPiece(currentTurn,boxes);
	row = row / 100;
	col = col / 100;
	boxes[row][col].removePiece();

}


void Board::movePiece(int row, int col, char &currentTurn) {
	if (pickedUpCol != -1) {	//if we're holding a piece
		setDownPiece(currentTurn,boxes);
	}
	else { //picking up a new piece
		row = row / 100;
		col = col / 100;
		if (boxes[row][col].getPiece()) {
			if (boxes[row][col].getPiece()->getTeam() == currentTurn) {
				pickedUpRow = row;
				pickedUpCol = col;
				this->highlightSquare(pickedUpRow, pickedUpCol, currentTurn);
			}
		}
	}

}

void Board::update() {
	
}

void Board::setDownPiece(char &currentTurn,Box**& checkBoxes) {	//test to see if we want to set down a piece

	if (pickedUpCol != -1) { //checking if a piece is actually picked up
		attemptMove(currentTurn,checkBoxes);
		pickedUpCol = -1; 
		pickedUpRow = -1;
	}
	else {
		std::cout << "Tried to set down a piece that didn't exist" << std::endl;
	}

}

bool Board::attemptMove(char& currentTurn,Box**& checkBoxes) {	//true if the move is valid, false if it isn't.
	Piece* removedPiece = nullptr;
	int previousRow;
	int previousCol;
	bool validMove = false;
	int x;
	int y;
	SDL_GetMouseState(&x, &y);
	int row = y / 100;
	int col = x / 100;
	int previousKingRow, previousKingCol;
	findKingRow(previousKingRow, previousKingCol, currentTurn, checkBoxes);
	if (checkBoxes[pickedUpRow][pickedUpCol].getPiece()->attemptMove(row, col, pieces)) { //if we can move there.
		previousRow = pickedUpRow;
		previousCol = pickedUpCol;
		bool moveStatus = checkBoxes[pickedUpRow][pickedUpCol].getPiece()->moved();
		if (checkBoxes[row][col].getPiece()) {	//if there's a piece to take
			highlightSquare(pickedUpRow, pickedUpCol, currentTurn);
			checkBoxes[row][col].removePiece();
			removedPiece = checkBoxes[row][col].getPiece();
			checkBoxes[row][col].setPiece(checkBoxes[pickedUpRow][pickedUpCol].getPiece());
			checkBoxes[pickedUpRow][pickedUpCol].setPiece(NULL);

		}
		else {	//if yo ucan just move there.
			highlightSquare(pickedUpRow, pickedUpCol, currentTurn);
			checkBoxes[row][col].setPiece(checkBoxes[pickedUpRow][pickedUpCol].getPiece());
			checkBoxes[pickedUpRow][pickedUpCol].setPiece(NULL);

		}
		checkBoxes[row][col].getPiece()->setRow(row);
		checkBoxes[row][col].getPiece()->setCol(col);
		checkBoxes[row][col].getPiece()->resetPlace();
		checkBoxes[row][col].getPiece()->setMoved();

		updatePieceLocations(boxes, pieces);
		//if a move was made that would put your king in check/keep your king in check.
		if ((whiteKingInCheck(checkBoxes, pieces) && currentTurn == 'w') || (blackKingInCheck(checkBoxes, pieces) && currentTurn == 'b')) {
			checkBoxes[previousRow][previousCol].setPiece(checkBoxes[row][col].getPiece());
			checkBoxes[previousRow][previousCol].getPiece()->setRow(previousRow);
			checkBoxes[previousRow][previousCol].getPiece()->setCol(previousCol);
			checkBoxes[previousRow][previousCol].getPiece()->resetPlace();
			checkBoxes[previousRow][previousCol].getPiece()->resetMoved(moveStatus);
			if (removedPiece) {
				checkBoxes[row][col].setPiece(removedPiece);
				removedPiece = nullptr;
			}
			else {
				checkBoxes[row][col].setPiece(NULL);
			}
			std::cout << "Mistake! move that would put your own king in check was played.\n";
			return false;
		}
		else {	//the move didn't put your king into check.
			if (removedPiece) {
				std::cout << "Deleting removed Piece" << std::endl;
				delete(removedPiece);
				removedPiece = nullptr;
			}
			currentTurn == 'w' ? currentTurn = 'b' : currentTurn = 'w';
			updatePieceLocations(checkBoxes, pieces);
			int whiteKingRow, whiteKingCol, blackKingRow, blackKingCol;
			findKingRow(whiteKingRow, whiteKingCol, currentTurn, checkBoxes);
			findKingRow(blackKingRow, blackKingCol, currentTurn, checkBoxes);
			if (whiteKingInCheck(checkBoxes, pieces)) {
				checkBoxes[whiteKingRow][whiteKingCol].toggleTargeted(true);
				std::cout << "Checkmate check: " << checkForCheckmate(currentTurn);
				std::cout << "The white king is in check!" << std::endl;
			}
			else {
				checkBoxes[previousKingRow][previousKingCol].toggleTargeted(false);
			}
			if (blackKingInCheck(checkBoxes, pieces)) {
				checkBoxes[blackKingRow][blackKingCol].toggleTargeted(true);
				std::cout << "Checkmate check: " << checkForCheckmate(currentTurn);
				std::cout << "The Black king is in check!" << std::endl;
			}
			else {
				checkBoxes[previousKingRow][previousKingCol].toggleTargeted(false);
			}
			pickedUpRow = -1;
			pickedUpCol = -1;
			return true;
		}


	}	
	else {	//this move isn't in the realm of possiblility.
		highlightSquare(pickedUpRow, pickedUpCol, currentTurn);
		boxes[pickedUpRow][pickedUpCol].getPiece()->resetPlace();
		std::cout << "Can't move there!" << std::endl;
	}
	pickedUpRow = -1;
	pickedUpCol = -1;
	return false;

	
}



//this takes in layout and determines if Black king is in check in this layout
//searchBoxes is an array of Boxes with pieces, currentPieces is a 2d char array with w if white piece, b if black, e if empty.
bool Board::whiteKingInCheck(Box** searchBoxes,char** currentPieces) {	
	int kingRow, kingCol;
	findKingRow(kingRow, kingCol, 'w',searchBoxes);
	
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (searchBoxes[i][j].getPiece()) {
				if (searchBoxes[i][j].getPiece()->getTeam() == 'b') {
					std::vector<int> possibleAttacks = searchBoxes[i][j].getPiece()->showMoves(i,j,currentPieces);
					for (int k = 0; k < possibleAttacks.size() / 2; k++) {
						if (possibleAttacks[k * 2] == kingRow && possibleAttacks[k * 2 + 1] == kingCol) {	
							return true;
						}
					}
				}
			
			}
		}
	}
	return false;
}


//takes in layout and determines if black king is in check. Returns true if king in check, false if they're not.
//searchBoxes is an array of Boxes with pieces, currentPieces is a 2d char array with w if white piece, b if black, e if empty.
bool Board::blackKingInCheck(Box** searchBoxes,char** currentPieces) { 
	int kingRow, kingCol;
	findKingRow(kingRow, kingCol, 'b',searchBoxes);
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (searchBoxes[i][j].getPiece()) {
				
				if (searchBoxes[i][j].getPiece()->getTeam() == 'w') {
				
					std::vector<int> possibleAttacks = searchBoxes[i][j].getPiece()->showMoves(i, j, currentPieces);
					for (int k = 0; k < possibleAttacks.size() / 2; k++) {
						if (possibleAttacks[k * 2] == kingRow && possibleAttacks[k * 2 + 1] == kingCol) {
							return true;
						}
					}
				}

			}
		}
	}
	return false;
}

void Board::findKingRow(int& kingRow, int& kingCol, char team,Box** searchBoxes) {
	bool kingFound = false;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (searchBoxes[i][j].getPiece()) {
				
				if (searchBoxes[i][j].getPiece()->getTeam() == team && searchBoxes[i][j].getPiece()->getType() == 'K') {
					
					kingRow = i;
					kingCol = j;
					kingFound = true;
				}
			}
			if (kingFound) {
				break;
			}
		}
		if (kingFound) {
			break;
		}
	}
}



char Board::checkForCheckmate(char currentTeam){ //we will check if the player is in check, and whether they can make a move where they cannot be in check anymore.
	Box** copyOfBoard;
	copyOfBoard = nullptr;
	char** pieceCopy;
	pieceCopy = nullptr;
	bool wayOut = false;
	bool firstTime = true;
	remakeBoardCopy(copyOfBoard,pieceCopy,firstTime);
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (copyOfBoard[i][j].getPiece()) {
			
				if (copyOfBoard[i][j].getPiece()->getTeam() == currentTeam) {
					
					std::vector<int> moves = copyOfBoard[i][j].getPiece()->showMoves(i,j,pieceCopy);
					for (int k = 0; k < moves.size() / 2; k++) {
						
						if (!(stillInCheckAfterThis(copyOfBoard, pieceCopy, i, j, moves[k * 2], moves[k * 2 + 1], currentTeam))) { //error on this line
							std::cout << "way out found moving piece at " << i << " " << j << "to  " << moves[k * 2] << " " << moves[k * 2 + 1] << std::endl;
							wayOut = true;
							freeBoardCopy(copyOfBoard, pieceCopy);
							return 'n';
						}	
						remakeBoardCopy(copyOfBoard, pieceCopy,firstTime);
					}
				}
			}
		}
	}
	

	freeBoardCopy(copyOfBoard, pieceCopy);
	if (!wayOut) {
		if (currentTeam == 'b') {
			return 'w';
		}
		return 'b';
	}
	else {
		return 'n';
	}
}

bool Board::stillInCheckAfterThis(Box**& boardCopy, char**& testPieces, int row, int col, int moveToRow, int moveToCol, char currentTeam) {
	Piece* tempPiece = boardCopy[moveToRow][moveToCol].getPiece();
	if (tempPiece) {
		delete(tempPiece);
		
	}
	boardCopy[moveToRow][moveToCol].setPiece(boardCopy[row][col].getPiece());
	boardCopy[row][col].setPiece(NULL);
	
	
	
	updatePieceLocations(boardCopy, testPieces);
	
	switch (currentTeam) {
	case 'w':
		if (whiteKingInCheck(boardCopy,testPieces)) {
			return true;
		}
		else {
			return false;
		}
		break;
	case 'b':
	
		if (blackKingInCheck(boardCopy, testPieces)) {
			
			return true;
		}
		else {
			return false;
		}
	}
	
}


void Board::freeBoardCopy(Box** copyOfBoard,char**& pieceCopy) {
	
	if (copyOfBoard) {
		for (int i = 0; i < 8; i++) {
			if (copyOfBoard[i]) {
				delete[] (copyOfBoard[i]);
			}
		}
		delete[](copyOfBoard);
	}	
	if (pieceCopy) {
		for (int i = 0; i < 8; i++) {
			if (pieceCopy[i]) {
				delete[] pieceCopy[i];
			}
		}
		delete[] pieceCopy;
	}
}

void Board::remakeBoardCopy(Box**& copyOfBoard,char**& pieceCopy,bool&firstTime) {
	if (!firstTime) {
		
		freeBoardCopy(copyOfBoard, pieceCopy);
	}
	firstTime = false;

		pieceCopy = new char* [8];
	
	
	copyOfBoard = new Box * [8];
	for (int i = 0; i < 8; i++) {
		copyOfBoard[i] = new Box[8];
		pieceCopy[i] = new char[8];
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			copyOfBoard[i][j].setPiece(NULL);
			pieceCopy[i][j] = 'e';
		}
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			pieceCopy[i][j] = pieces[i][j];
			if (boxes[i][j].getPiece()) {
				switch (boxes[i][j].getPiece()->getType()) {
				case 'p':
					copyOfBoard[i][j].setPiece(new Pawn(boxes[i][j].getPiece()->getTeam(), i, j));
					break;
				case 'r':
					copyOfBoard[i][j].setPiece(new Rook(boxes[i][j].getPiece()->getTeam(), i, j));
					break;
				case 'k':
					copyOfBoard[i][j].setPiece(new Knight(boxes[i][j].getPiece()->getTeam(), i, j));
					break;
				case 'b':
					copyOfBoard[i][j].setPiece(new Bishop(boxes[i][j].getPiece()->getTeam(), i, j));
					break;
				case 'K':
					copyOfBoard[i][j].setPiece(new King(boxes[i][j].getPiece()->getTeam(), i, j));
					break;
				case 'q':
					copyOfBoard[i][j].setPiece(new Queen(boxes[i][j].getPiece()->getTeam(), i, j));
					break;
				default:
					copyOfBoard[i][j].setPiece(NULL);
					std::cout << "error in switch statement in remakeBoardCopy" << std::endl;
				}
			}

		}
	}
}


void Board::randomBotMove() {
	bool pieceMoved = false;
	std::vector<int> pieces = getBlackPieces();
	while (!pieceMoved) {
		int piecePicked = rand() % (pieces.size() / 2);
		//std::vector<int> moves = (boxes[pieces[piecePicked * 2]][pieces[piecePicked * 2 + 1]]).getPiece()->showMoves();
		//for (int i = 0; i < moves.size() / 2; i++) {
			
		//}
	}
}

std::vector<int> Board::getBlackPieces() {
	std::vector<int> pieces;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (boxes[i][j].getPiece()->getTeam() == 'b') {
				pieces.push_back(i);
				pieces.push_back(j);
			}
		}
	}
	return pieces;
}


