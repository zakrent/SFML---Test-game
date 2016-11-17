#include "Enemy.h"

void Enemy::follow(Player player, double time, Tile tile[])
{
	float Xdiff = player.GetX() - this->GetX();
	float Ydiff = player.GetY() - this->GetY();

	if (Xdiff > 0) { this->Move(1, time, tile); }
	else if (Xdiff < 0) { this->Move(3, time, tile); }
	if (Ydiff > 0) { this->Move(2, time, tile); }
	else if (Ydiff < 0) { this->Move(0, time, tile); }
}

void Enemy::attack(Player &player, double time)
{
	int distance = sqrt((abs(player.GetX() - this->GetX())*abs(player.GetX() - this->GetX())) + (abs(player.GetY() - this->GetY())*abs(player.GetY() - this->GetY())));
	if (distance < 48) { player.DoDamage(10*time); }
	
}
