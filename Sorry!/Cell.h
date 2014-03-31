#pragma once;
using namespace std;

class Cell
{
private:
	int occupied, loc_x, loc_y, special;

public:
	Cell(int occupied, int loc_x, int loc_y, int special);
	Cell();
	~Cell();

	int getLoc_x();
	int getLoc_y();
	int getColor();

};