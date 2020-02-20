#include "Bullet.h"


namespace SpaceInvaders {
	Bullet::Bullet(sf::RenderWindow* window, sf::Vector2f position) {
		screen = window;
		bulletRect.setSize(sf::Vector2f(10, 10));
		bulletRect.setPosition(position);
		isActive = true;
	}

	void Bullet::update(float deltaTime) {
		move(deltaTime);
		screen->draw(bulletRect);
	}

	void Bullet::move(float deltaTime) {
		bulletRect.move(0, -speed * deltaTime);
	}
}
