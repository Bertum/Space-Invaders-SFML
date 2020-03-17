#include "HUD.h"

namespace SpaceInvaders {
	HUD::HUD(sf::RenderWindow* window) : screen(window)
	{
		fontStyle.loadFromFile(FONT_STYLE);
		highScoreLabelText.setFont(fontStyle);
		highScoreText.setFont(fontStyle);
		scoreLabelText.setFont(fontStyle);
		scoreText.setFont(fontStyle);
		highScoreLabelText.setString("Highscore:");
		scoreLabelText.setString("Score:");
		scoreText.setString("0");
		highScoreText.setString("0");
		highScoreText.setCharacterSize(fontSize);
		highScoreLabelText.setCharacterSize(fontSize);
		scoreText.setCharacterSize(fontSize);
		scoreLabelText.setCharacterSize(fontSize);
		highScoreLabelText.setFillColor(sf::Color::White);
		highScoreText.setFillColor(sf::Color::White);
		scoreLabelText.setFillColor(sf::Color::White);
		scoreText.setFillColor(sf::Color::White);
		highScoreLabelText.setOrigin(highScoreLabelText.getLocalBounds().width / 2, 0);
		highScoreLabelText.setPosition(SCREEN_WIDTH / 2, 0);
		highScoreText.setOrigin(highScoreText.getLocalBounds().width / 2, 0);
		scoreText.setPosition(scoreLabelText.getLocalBounds().width + 20, 0);
		highScoreText.setPosition(highScoreLabelText.getPosition().x +
			highScoreLabelText.getLocalBounds().width / 2 + 20, 0);
	}

	void HUD::draw() {
		screen->draw(highScoreLabelText);
		screen->draw(highScoreText);
		screen->draw(scoreLabelText);
		screen->draw(scoreText);
	}
}
