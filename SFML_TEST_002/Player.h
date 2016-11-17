#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>
#include "Entity.h"
#include "Tile.h"


class Player : public Entity
{
private:
	float hp;
public:
	void Move(int direction, double time, Tile tile[]);
	void Shoot(int x, int y);
	void DoDamage(float dmg);
	float GetHealth();


	Player();
	~Player();
};
