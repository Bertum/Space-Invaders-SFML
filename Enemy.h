#pragma once
#include "DEFINITIONS.h"
#include "SFML/Graphics.hpp"

namespace SpaceInvaders {
	class Enemy
	{
	public:
		Enemy(sf::RenderWindow* w, int initialPosX, int initialPosY);
		void move(float deltaTime, bool right);
		void moveDown();
		void update(float deltaTime);
		bool endOfScreen();
		bool isAlive;
		bool reachPlayer();
	private:
		sf::RenderWindow* screen;
		sf::Texture texture;
		sf::Sprite sprite;
		float speed = 50;
		void loadSprite(float positionX, float positionY);
	};
}
