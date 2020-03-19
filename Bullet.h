#pragma once
#include "SFML/Graphics.hpp"
#include "DEFINITIONS.h"

namespace SpaceInvaders {
	class Bullet
	{
	public:
		Bullet(sf::RenderWindow* window, sf::Vector2f position);
		void update(float deltaTime);
		sf::Sprite& getRectangleShape();
		bool isActive;
	private:
		sf::Texture texture;
		sf::Sprite sprite;
		sf::RenderWindow* screen;
		void move(float deltaTime);
		float speed = 30;
		void checkOutOfScreen();
	};
}
