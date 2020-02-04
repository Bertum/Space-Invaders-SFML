#include "Ship.h"
#include "DEFINITIONS.h"
#include <iostream>
#include <string>

namespace SpaceInvaders {

	Ship::Ship(sf::RenderWindow* w) {
		screen = w;
		if (!shipTexture.loadFromFile(SHIP_SPRITE_PATH)) {
			std::cout << "Failed to load player image" << std::endl;
		}
		else {
			shipSprite.setTexture(shipTexture);
			shipSprite.setOrigin(shipTexture.getSize().x / 2, shipTexture.getSize().y / 2);
		}
	}

	void Ship::Update(float deltaTime) {
		shipSprite.setPosition(screen->getSize().x / 2, screen->getSize().y - 20);
		screen->draw(shipSprite);
	}
}
