#include "bigPieces.h"
#include "Piece.h"
#include "Queen.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include <iostream>

bigPieces::bigPieces() {
	whitePieces = new Piece * [4];
	whitePieces[0] = new Queen('w',3,0,2);
	whitePieces[1] = new Rook('w',3,2,2);
	whitePieces[2] = new Knight('w',3,4,2);
	whitePieces[3] = new Bishop('w',3,6,2);
	blackPieces = new Piece * [4];
	blackPieces[0] = new Queen('b', 3, 0, 2);
	blackPieces[1] = new Rook('b', 3, 2, 2);
	blackPieces[2] = new Knight('b', 3, 4, 2);
	blackPieces[3] = new Bishop('b', 3, 6, 2);


}

bigPieces::~bigPieces() {
	for (int i = 0; i < 4; i++) {
		delete whitePieces[i];
		delete blackPieces[i];
	}
	delete[] whitePieces;
	delete[] blackPieces;

}

void bigPieces::render(char teamToRender) {
	if (teamToRender == 'w') {
		for (int i = 0; i < 4; i++) {
			whitePieces[i]->render();
		}
	}
	else if(teamToRender== 'b') {
		for (int i = 0; i < 4; i++) {
			blackPieces[i]->render();
		}
	}
	else {
		std::cout << "error, teamtorender =:" << teamToRender << std::endl;
	}
}

