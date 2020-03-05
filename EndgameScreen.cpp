#include "EndgameScreen.h"

namespace SpaceInvaders {
	EndgameScreen::EndgameScreen(sf::RenderWindow* window) : screen(window) {
		// Load gameOver to display
		//texture.loadFromFile(LOSE_GAME_SPRITE_PATH);
		//create sprite and scale
		//sprite.setTexture(texture);
		fontStyle.loadFromFile(FONT_STYLE);
		text.setFont(fontStyle);
		text.setString("Endgame");
		text.setFillColor(sf::Color::White);
	}

	void EndgameScreen::draw(bool win) {
		screen->draw(text);
	}
}
