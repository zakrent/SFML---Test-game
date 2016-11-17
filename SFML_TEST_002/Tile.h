#include <iostream>
#pragma once

class Tile
{
private:
	int x, y;
	bool Solid;
public:
	void SetSolid(bool value);
	void SetPos(int x,int y);
	bool IsSolid();
	int GetX();
	int GetY();
	
	Tile();
	~Tile();
};

