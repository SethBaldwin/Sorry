#pragma once;
using namespace std;

class Pawns
{
private:
	int loc_x;
	int loc_y;
	int color; // What color
	int number; // Which pawn. prevents same pawn from bein selected.
	int loc; // Tracks which vector the piece is in.

public:
	Pawns(int color, int loc_x, int loc_y, int number, int loc);
	Pawns();
	~Pawns();

	int getLoc_x();
	int getLoc_y();
	int getCol();
	int getNum();
	int getLoc(); // Tracks which vector the piece is in.

	void setLoc_x(int x);
	void setLoc_y(int y);
	void setCol(int num);
	void setLoc(int num); // Tracks which vector the piece is in.
};

