#include "Enemy.h"

namespace SpaceInvaders {
	Enemy::Enemy(sf::RenderWindow* window, int initialPosX, int initialPosY, int row) : screen(window) {
		isAlive = true;
		loadSprite(initialPosX, initialPosY, row);
	}

	void Enemy::update() {
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
			doAnimation();
		}
	}

	void Enemy::moveDown() {
		sprite.move(0, speed);
	}

	void Enemy::loadSprite(float positionX, float positionY, int row) {
		switch (row)
		{
		case 0:
			texture.loadFromFile(ENEMY_SPRITE_A_PATH);
			break;
		case 1:
		case 2:
			texture.loadFromFile(ENEMY_SPRITE_B_PATH);
			break;
		case 3:
		case 4:
			texture.loadFromFile(ENEMY_SPRITE_C_PATH);
			break;
		default:
			break;
		}
		sprite.setTexture(texture);
		sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
		sprite.setPosition(positionX, positionY);
		rectSourceSprite = sf::IntRect(0, 0, sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height);
		sprite.setTextureRect(rectSourceSprite);
	}

	bool Enemy::endOfScreen() {
		if ((sprite.getPosition().x <= 50 || sprite.getPosition().x >= screen->getSize().x - 50) && isAlive)
			return true;

		return false;
	}

	bool Enemy::reachPlayer() {
		if (sprite.getPosition().y > screen->getSize().y - 20 && isAlive)
		{
			return true;
		}
		return false;
	}

	void Enemy::doAnimation() {
		if (animationIndex == 0)
			animationIndex++;
		else
			animationIndex = 0;

		rectSourceSprite.left = sprite.getGlobalBounds().width * animationIndex;
		sprite.setTextureRect(rectSourceSprite);
	}

	sf::Sprite& Enemy::getSprite()
	{
		return sprite;
	}
}
