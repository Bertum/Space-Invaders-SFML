#include "EndgameScreen.h"

namespace SpaceInvaders {
	EndgameScreen::EndgameScreen(sf::RenderWindow* window) : screen(window) {
		fontStyle.loadFromFile(FONT_STYLE);
		highscoreLabel = new sf::Text();
		highscoreText = new sf::Text();
		scoreLabel = new sf::Text();
		scoreText = new sf::Text();
		loadHighScore();
	}

	void EndgameScreen::draw(bool win) {
		screen->draw(*highscoreLabel);
		screen->draw(*highscoreText);
		screen->draw(*scoreLabel);
		screen->draw(*scoreText);
	}

	void EndgameScreen::configText(sf::Text* text, float posX, float posY, sf::String string, int size) {
		text->setFont(fontStyle);
		text->setFillColor(sf::Color::White);
		text->setString(string);
		text->setOrigin(text->getLocalBounds().width / 2, text->getLocalBounds().height / 2);
		text->setPosition(SCREEN_WIDTH / 2, posY);
		text->setCharacterSize(size);
	}

	void EndgameScreen::saveScore(int score) {
		if (score > highScore)
		{
			std::ofstream file("highScore.txt");
			file << score << std::endl;
			file.close();
			highscoreText->setString(std::to_string(score));
		}
		scoreText->setString(std::to_string(score));
		configText(highscoreLabel, 100, 100, "Highscore", 15);
		configText(highscoreText, 100, 200, std::to_string(highScore), 15);
		configText(scoreLabel, 100, 300, "Score", 15);
		configText(scoreText, 100, 400, std::to_string(score), 15);
	}

	void EndgameScreen::loadHighScore() {
		std::ifstream file;
		file.open("highScore.txt");
		if (file.good())
		{
			std::string line;
			std::getline(file, line);
			highScore = std::stoi(line);
			highscoreText->setString(std::to_string(highScore));
		}
		file.close();
	}
}
