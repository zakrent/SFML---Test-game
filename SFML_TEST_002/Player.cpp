#pragma once
#include <math.h>
#include "player.h"

int GetTileId(int xTil, int yTil) // Map width
{
	return (yTil/32 * 15 - (15 - xTil/32)) - 1;
}

//	*0*
//	3+1
//	*2*

void Player::Move(int direction, double time, Tile tile[])
{
	const int MovSpeed = 80;
	switch (direction)
	{
		int yTi;
		int xTi;
		case(0):

			yTi = int(Player::GetY() + 8);
			xTi = int(Player::GetX() + 16);
			yTi -= yTi % 32;
			xTi -= xTi % 32;

			if (!tile[GetTileId(xTi, yTi)].IsSolid())
			{
				Player::SetY(Player::GetY() - (MovSpeed * time));
			}
			//std::cout << xTi << " Y:" << yTi <<" ID:"<< GetTileId(xTi, yTi)<<std::endl;
		break;

		case(2):

			yTi = int(Player::GetY() + 24);
			xTi = int(Player::GetX() + 16);
			yTi -= yTi % 32;
			xTi -= xTi % 32;

			if (!tile[GetTileId(xTi, yTi)].IsSolid())
			{
				Player::SetY(Player::GetY() + (MovSpeed * time));
			}
			//std::cout << xTi << " Y:" << yTi << " ID:" << GetTileId(xTi, yTi) << std::endl;
		break;

		case(1):

			yTi = int(Player::GetY() + 16);
			xTi = int(Player::GetX() + 24);
			yTi -= yTi % 32;
			xTi -= xTi % 32;

			if (!tile[GetTileId(xTi, yTi)].IsSolid())
			{
				Player::SetX(Player::GetX() + (MovSpeed * time));
			}
			//std::cout << xTi << " Y:" << yTi << " ID:" << GetTileId(xTi, yTi) << std::endl;
		break;

		case(3):

			yTi = int(Player::GetY() + 16);
			xTi = int(Player::GetX() + 8);
			yTi -= yTi % 32;
			xTi -= xTi % 32;

			if (!tile[GetTileId(xTi, yTi)].IsSolid())
			{
				Player::SetX(Player::GetX() - (MovSpeed * time));
			}
			//std::cout << xTi << " Y:" << yTi << " ID:" << GetTileId(xTi, yTi) << std::endl;
		break;
	}

}

void Player::Shoot(float x, float y)
{

}

void Player::DoDamage(float dmg) { this->hp -= dmg; std::cout << dmg << std::endl; }

float Player::GetHealth()
{
	return this->hp;
}

Player::Player() : Entity() { this->hp = 100; }
Player::~Player(){}

if (false)
{
	1=1
}
