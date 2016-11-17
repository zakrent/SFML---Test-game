#include <iostream>
#include "Tile.h"

void Tile::SetSolid(bool value) { this->Solid = value; }
void Tile::SetPos(int x, int y) { this->x = x; this->y = y; }
bool Tile::IsSolid() { return Solid; }
int Tile::GetX(){return x;}
int Tile::GetY(){return y;}

Tile::Tile()
{
	this->x = 0;
	this->y = 0;
	this->Solid = false;
}
Tile::~Tile(){}
