#pragma once
#include <iostream>
#include <math.h>
#include <SFML\Graphics.hpp>
#include "Entity.h"
#include "Player.h"

class Enemy : public Player
{
private:
public:
	void follow(Player player, double time, Tile tile[]);
	void attack(Player &player, double time);
};
