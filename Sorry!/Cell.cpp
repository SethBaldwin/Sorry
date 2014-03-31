#include "Cell.h"

Cell::Cell()
{
	occupied = 0;
	loc_x = 0;
	loc_y = 0;
	special = 0;
}

Cell::~Cell(){}

Cell::Cell(int o, int x, int y, int s)
{
	occupied = o;
	loc_x = x;
	loc_y = y;
	special = s;
}