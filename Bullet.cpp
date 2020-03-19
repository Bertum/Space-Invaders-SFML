#include "Bullet.h"


namespace SpaceInvaders {
	Bullet::Bullet(sf::RenderWindow* window, sf::Vector2f position) : screen(window) {
		texture.loadFromFile(BULLET_SPRITE_PATH);
		sprite.setTexture(texture);
		sprite.setPosition(position);
		sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
		isActive = true;
	}

	void Bullet::update(float deltaTime) {
		if (isActive)
		{
			move(deltaTime);
			screen->draw(sprite);
			checkOutOfScreen();
		}
	}

	sf::Sprite& Bullet::getRectangleShape()
	{
		return sprite;
	}

	void Bullet::checkOutOfScreen()
	{
		if (sprite.getPosition().y + (sprite.getLocalBounds().height / 2) < 0)
		{
			isActive = false;
		}
	}

	void Bullet::move(float deltaTime) {
		sprite.move(0, -speed * deltaTime);
	}
}
