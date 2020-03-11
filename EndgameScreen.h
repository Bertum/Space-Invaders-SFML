#pragma once
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.h"
#include <iostream>
#include <fstream>

namespace SpaceInvaders {
	class EndgameScreen
	{
	public:
		EndgameScreen(sf::RenderWindow* window);
		void draw(bool win);
		void saveScore(int score);
	private:
		sf::Text* scoreLabel;
		sf::Text* scoreText;
		sf::Text* highscoreLabel;
		sf::Text* highscoreText;
		sf::RenderWindow* screen;
		sf::Font fontStyle;
		void configText(sf::Text*, float posX, float posY, sf::String string, int size);
		void loadHighScore();
		int highScore = 0;
	};
}
