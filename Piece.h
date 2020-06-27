#pragma once
#include <vector>
class Piece
{
public:
	virtual std::vector<int> showMoves(int row, int col) = 0;
	 char getType();
	 bool getTeam();

protected:
	char pieceType;
	bool team;	//0 if black 1 if white
};

