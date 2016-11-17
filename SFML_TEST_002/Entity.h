#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Entity
{
private:
	float x, y;
public:
	sf::Sprite Draw(sf::Texture &texture);
	void SetPos(float x, float y);
	void SetX(float x);
	void SetY(float y);
	float GetX();
	float GetY();
	Entity();
	~Entity();
};


