#pragma once
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.h"

namespace SpaceInvaders {
	class HUD
	{
	public:
		HUD(sf::RenderWindow* window);
		void draw();
		int score = 0;
	private:
		sf::RenderWindow* screen;
		sf::Font fontStyle;
		sf::Text highScoreLabelText;
		sf::Text scoreLabelText;
		sf::Text highScoreText;
		sf::Text scoreText;
		int fontSize = 10;
		int highScore = 0;
	};
}
