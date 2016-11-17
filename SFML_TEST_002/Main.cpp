#include <iostream>
#include <math.h>
#include <windows.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Tile.h"
#include "Entity.h"
#include "Player.h"
#include "Enemy.h"

using namespace std;

const int mapWidth = 15;  
Tile tile[mapWidth*mapWidth]; //powierzchnia
void CalcMap()
{
	bool MapReady = false;
	int xTile = 1, yTile = 1, rMap = 0;
	while (!MapReady)
	{
		if (xTile > mapWidth) { yTile++; xTile = 1; }
		if (yTile > mapWidth) { MapReady = true; }
		else 
		{
			tile[rMap].SetPos(xTile*32, yTile*32);
			if ((xTile == 1 || xTile == mapWidth) || (yTile == 1 || yTile == mapWidth)) { tile[rMap].SetSolid(true); }
			cout << "X: " << tile[rMap].GetX() << " Y: " << tile[rMap].GetY() << " Sol: " << tile[rMap].IsSolid() << " " << rMap << endl;
			xTile++;
			rMap++;
			if (rMap == 125 || rMap == 126 || rMap == 140 || rMap == 141) { tile[rMap].SetSolid(true); }
		}
	}
}

int main()
{
	//Startup
	sf::RenderWindow window(sf::VideoMode(544, 544, 16), "Test", sf::Style::Close | sf::Style::Titlebar);
	window.setFramerateLimit(30);
	
	CalcMap();
	
	//Draw Map
	bool MapDraw = false;
	int rDraw=-1;

	sf::Texture texture1;
	texture1.loadFromFile("texture1.png");
	sf::Texture texture2;
	texture2.loadFromFile("texture2.png");
	sf::Texture playerTex;
	playerTex.loadFromFile("player.png");
	sf::Texture enemyTex;
	enemyTex.loadFromFile("enemy.png");
	sf::Sprite spriteTile[mapWidth*mapWidth];

	while (!MapDraw)
	{
		rDraw++;
		if (rDraw == mapWidth*mapWidth) { MapDraw = true; cout << rDraw << " ";}
		else
		{
			spriteTile[rDraw].setPosition(tile[rDraw].GetX(), tile[rDraw].GetY());
			if (tile[rDraw].IsSolid()) { spriteTile[rDraw].setTexture(texture2); }
			else { spriteTile[rDraw].setTexture(texture1); }
			cout << rDraw << " ";
		}
	}
	//Setup Player && Enemy
	Player player[1];
	player[0].SetPos(64, 188);

	Enemy enemy[1];
	enemy[0].SetPos(80, 189);
	//Clock
	sf::Clock MovClock;

	//Game loop
	while (window.isOpen() && player[0].GetHealth()>0)
	{

		//Event handling
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;	
			default:
				break;
			}
		}
		sf::Time MovTime = MovClock.restart();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { player[0].Move(3, MovTime.asSeconds(), tile); }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) { player[0].Move(1, MovTime.asSeconds(), tile); }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) { player[0].Move(0, MovTime.asSeconds(), tile); }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) { player[0].Move(2, MovTime.asSeconds(), tile); }

		enemy[0].follow(player[0], MovTime.asSeconds()/2, tile);
		enemy[0].attack(player[0], MovTime.asSeconds());
		std::cout << player[0].GetHealth() << std::endl;

		//Rendering
		window.clear(sf::Color(100-player[0].GetHealth(),0,0,255));
		bool tileSpritesDraw = false;
		int spriteDrawR = -1;
		while (!tileSpritesDraw)
		{
			spriteDrawR++; if (spriteDrawR < mapWidth*mapWidth) 
			{ window.draw(spriteTile[spriteDrawR]); }
			else { tileSpritesDraw = true; }
		}
		window.draw(player[0].Draw(playerTex));
		window.draw(enemy[0].Draw(enemyTex));
		window.display();
		//
	}
	//
	system("cls");
	std::cout << "YOU'VE LOST"<< std::endl;
	system("pause");
	return 0;
}
