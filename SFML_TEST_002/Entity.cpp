#pragma once
#include "Entity.h"
#include <SFML/Graphics.hpp>
#include <iostream>

void Entity::SetPos(float x, float y) { this->x = x;	this->y = y; }
void Entity::SetX(float x) { this->x = x; }
void Entity::SetY(float y) { this->y = y; }
float Entity::GetX() { return this->x; }
float Entity::GetY() { return this->y; }

sf::Sprite Entity::Draw(sf::Texture &texture)
{
	sf::Sprite sprite;
	sprite.setPosition(this->x, this->y);
	sprite.setTexture(texture);
	return sprite;
}

Entity::Entity()
{
	this->x = 0;
	this->y = 0;
}

Entity::~Entity()
{
}