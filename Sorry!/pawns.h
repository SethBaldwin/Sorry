#pragma once;
using namespace std;

class Pawns
{
private:
	int loc_x, loc_y, color, number, loc;

public:
	Pawns(int color, int loc_x, int loc_y, int number, int loc);
	Pawns();
	~Pawns();

	int getLoc_x();
	int getLoc_y();
	int getCol();
	int getNum();
	int getLoc();

	void setLoc_x(int x);
	void setLoc_y(int y);
	void setCol(int num);
	void setLoc(int num);
};

