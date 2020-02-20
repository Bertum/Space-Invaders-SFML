#pragma once
#include "SFML/Graphics.hpp"
#include <vector>
#include "Bullet.h"

namespace SpaceInvaders {
	class Ship
	{
	public:
		Ship(sf::RenderWindow* w);
		void update(float deltaTime);
		void moveRight(float deltaTime);
		void moveLeft(float deltaTime);
		sf::Vector2f getPosition();
	private:
		sf::RenderWindow* screen;
		sf::Texture shipTexture;
		sf::Sprite shipSprite;
		float speed = 50;
	};
}
