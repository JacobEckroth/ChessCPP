#pragma once
#include <vector>
class Piece
{
public:
	virtual std::vector<int> showMoves(int row, int col,char**) = 0;
	 char getType();
	 char getTeam();
	 void setType(char);

protected:
	char pieceType;
	char team;	//0 if black 1 if white
};

