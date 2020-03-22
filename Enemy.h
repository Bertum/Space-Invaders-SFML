#pragma once
#include "DEFINITIONS.h"
#include "SFML/Graphics.hpp"

namespace SpaceInvaders {
	class Enemy
	{
	public:
		Enemy(sf::RenderWindow* window, int initialPosX, int initialPosY, int row);
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
		sf::Texture explosionTexture;
		sf::Sprite explosionSprite;
		float speed = 20;
		void loadSprite(float positionX, float positionY, int row);
		void doAnimation();
		int animationIndex = 0;
		sf::IntRect rectSourceSprite;
		float timeExplosionSprite;
	};
}
