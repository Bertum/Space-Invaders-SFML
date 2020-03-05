#pragma once
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.h"

namespace SpaceInvaders {
	class EndgameScreen
	{
	public:
		EndgameScreen(sf::RenderWindow* window);
		void draw(bool win);
	private:
		sf::Sprite sprite;
		sf::Texture texture;
		sf::Text text;
		sf::RenderWindow* screen;
		sf::Font fontStyle;
	};
}
