﻿#pragma once
#include "SFML/Graphics.hpp"

namespace SpaceInvaders {
	class Bullet
	{
	public:
		Bullet(sf::RenderWindow* window, sf::Vector2f position);
		void update(float deltaTime);
		sf::RectangleShape& getRectangleShape();
		bool isActive;
	private:
		sf::RectangleShape bulletRect;
		sf::RenderWindow* screen;
		void move(float deltaTime);
		float speed = 30;
		void checkOutOfScreen();
	};
}
