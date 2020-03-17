#pragma once
#include "DEFINITIONS.h"
#include "SFML/Graphics.hpp"

namespace SpaceInvaders {
	class Enemy
	{
	public:
		Enemy(sf::RenderWindow* window, int initialPosX, int initialPosY);
		void move(float deltaTime, bool right);
		void moveDown();
		void update();
		bool endOfScreen();
		bool reachPlayer();
		sf::Sprite& getSprite();
		bool isAlive;
	private:
		sf::RenderWindow* screen;
		sf::Texture texture;
		sf::Sprite sprite;
		float speed = 25;
		void loadSprite(float positionX, float positionY);
		void doAnimation();
		int animationIndex = 0;
		sf::IntRect rectSourceSprite;
	};
}
