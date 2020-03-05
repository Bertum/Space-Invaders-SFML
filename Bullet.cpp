#include "Bullet.h"


namespace SpaceInvaders {
	Bullet::Bullet(sf::RenderWindow* window, sf::Vector2f position) : screen(window) {
		bulletRect.setSize(sf::Vector2f(10, 10));
		bulletRect.setPosition(position);
		bulletRect.setOrigin(bulletRect.getSize().x / 2, bulletRect.getSize().y / 2);
		isActive = true;
	}

	void Bullet::update(float deltaTime) {
		if (isActive)
		{
			move(deltaTime);
			screen->draw(bulletRect);
			checkOutOfScreen();
		}
	}

	sf::RectangleShape& Bullet::getRectangleShape()
	{
		return bulletRect;
	}

	void Bullet::checkOutOfScreen()
	{
		if (bulletRect.getPosition().y + (bulletRect.getSize().y / 2) < 0)
		{
			isActive = false;
		}
	}

	void Bullet::move(float deltaTime) {
		bulletRect.move(0, -speed * deltaTime);
	}
}
