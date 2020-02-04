#pragma once
#include "SFML/Graphics.hpp"

namespace SpaceInvaders {
	class Ship
	{
	public:
		Ship(sf::RenderWindow* w);
		void Update(float deltaTime);
	private:
		sf::RenderWindow* screen;
		sf::Texture shipTexture;
		sf::Sprite shipSprite;
	};
}
