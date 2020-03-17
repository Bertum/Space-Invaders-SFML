#include "HUD.h"

namespace SpaceInvaders {
	HUD::HUD(sf::RenderWindow* window) : screen(window)
	{
		fontStyle.loadFromFile(FONT_STYLE);
		highScoreLabelText = new sf::Text();
		highScoreText = new sf::Text();
		scoreLabelText = new sf::Text();
		scoreText = new sf::Text();

		configText(scoreLabelText, "Score:", 15, 10);
		configText(scoreText, "0", scoreLabelText->getLocalBounds().width + 20, 10);
		configText(highScoreText, "0", SCREEN_WIDTH - 50, 10);
		configText(highScoreLabelText, "Highscore:", highScoreText->getPosition().x - 100, 10);

		loadHigherScore();
	}

	void HUD::draw() {
		screen->draw(*scoreLabelText);
		screen->draw(*scoreText);
		screen->draw(*highScoreLabelText);
		screen->draw(*highScoreText);
	}

	void HUD::configText(sf::Text* text, sf::String string, float posX, float posY) {
		text->setFont(fontStyle);
		text->setString(string);
		text->setFillColor(sf::Color::White);
		text->setCharacterSize(fontSize);
		text->setPosition(posX, posY);
	}

	void HUD::loadHigherScore() {
		std::ifstream file;
		file.open("highScore.txt");
		if (file.good())
		{
			std::string line;
			std::getline(file, line);
			highScore = std::stoi(line);
			highScoreText->setString(std::to_string(highScore));
		}
		file.close();
	}
}
