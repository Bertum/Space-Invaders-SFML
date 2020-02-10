#pragma once
#include "SFML/Graphics.hpp"

namespace SpaceInvaders {
	class Ship
	{
	public:
		Ship(sf::RenderWindow* w);
		void update(float deltaTime);
		sf::Sprite* getSprite();
	private:
		sf::RenderWindow* screen;
		sf::Texture shipTexture;
		sf::Sprite shipSprite;
	};
}
