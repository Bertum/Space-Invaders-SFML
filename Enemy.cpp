﻿#include "Enemy.h"
#include<iostream>

namespace SpaceInvaders {
	Enemy::Enemy(sf::RenderWindow* window, int initialPosX, int initialPosY) {
		screen = window;
		isAlive = true;
		loadSprite(initialPosX, initialPosY);
	}

	void Enemy::update(float deltaTime) {
		if (isAlive)
		{
			screen->draw(sprite);
		}
	}

	void Enemy::move(float deltaTime, bool right) {
		if (isAlive)
		{
			float xMove = 0;
			if (right)
				xMove = speed * deltaTime;
			else
				xMove = -speed * deltaTime;
			sprite.move(xMove, 0);
		}
	}

	void Enemy::moveDown() {
		sprite.move(0, speed);
	}

	void Enemy::loadSprite(float positionX, float positionY) {
		texture.loadFromFile(ENEMY_SPRITE_PATH);
		sprite.setTexture(texture);
		sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
		sprite.setPosition(positionX, positionY);
	}

	bool Enemy::endOfScreen() {
		if (sprite.getPosition().x <= 50 || sprite.getPosition().x >= screen->getSize().x - 50)
			return true;

		return false;
	}
}