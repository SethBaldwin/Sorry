#include "Pawns.h"
using namespace std;

Pawns::Pawns()
{
	color = 0;
	loc_x = 0;
	loc_y = 0;
	number = 0;
	loc = 1;
}

Pawns::~Pawns(){};

Pawns::Pawns(int c, int x, int y, int n, int l)
{
	color = c;
	loc_x = x;
	loc_y = y;
	number = n;
	loc = l;
}

int Pawns::getLoc_x()
{
	return loc_x;
}

int Pawns::getLoc_y()
{
	return loc_y;
}

int Pawns::getCol()
{
	return color;
}

int Pawns::getNum()
{
	return number;
}

int Pawns::getLoc()
{
	return loc;
}

void Pawns::setLoc_x(int x)
{
	loc_x = x;
}

void Pawns::setLoc_y(int y)
{
	loc_y = y;
}

void Pawns::setCol(int col)
{
	color = col;
}

void Pawns::setLoc(int num)
{
	loc = num;
}

void Pawns::bump(int num)
{

}