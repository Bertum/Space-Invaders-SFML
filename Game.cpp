#include "DEFINITIONS.h"
#include "Game.h"
#include <stdlib.h>

namespace SpaceInvaders {
	Game::Game(int width, int height, sf::String title) {
		window.create(sf::VideoMode(width, height), title);
		ship = new Ship(&window);
		createEnemies();
		rightMove = true;
		moveDown = false;
		window.setFramerateLimit(60);
		this->run();
	};

	void Game::run() {
		while (window.isOpen())
		{
			sf::Time dt = _clock.restart();
			float deltaTime = dt.asSeconds();
			// check all the window's events that were triggered since the last iteration of the loop
			sf::Event event;
			while (window.pollEvent(event))
			{
				// "close requested" event: we close the window
				if (event.type == sf::Event::Closed)
					window.close();
			}

			window.clear();
			counterToShoot += deltaTime;
			readInput(deltaTime);
			moveEnemies(deltaTime);
			updateBullets(deltaTime);
			checkFinishCondition();
			ship->update(deltaTime);
			window.display();
		}
	}

	void Game::createEnemies() {
		for (unsigned short int i = 0; i < 8; i++)
		{
			for (unsigned short int k = 0; k < 3; k++)
			{
				Enemy* enemy = new Enemy(&window, 50 * (i + 1), 50 * (k + 1));
				enemies.push_back(enemy);
			}
		}
	}

	void Game::moveEnemies(float deltaTime) {
		for (unsigned short int i = 0; i < enemies.size(); i++)
		{
			enemies[i]->move(deltaTime, rightMove);
			if (enemies[i]->endOfScreen() && !moveDown)
			{
				moveDown = true;
				rightMove = !rightMove;
			}

		}
		for (unsigned short int i = 0; i < enemies.size(); i++)
		{
			if (moveDown) {
				enemies[i]->moveDown();
			}
			enemies[i]->update(deltaTime);
		}
		moveDown = false;
	}

	void Game::checkFinishCondition() {
		for (unsigned short int i = 0; i < enemies.size(); i++)
		{
			if (enemies[i]->reachPlayer())
			{
				//TODO Finish games
			}
		}
	}

	void Game::updateBullets(float deltaTime) {
		for (unsigned short int i = 0; i < bullets.size(); i++)
		{
			bullets[i]->update(deltaTime);
		}
	}

	void Game::readInput(float deltaTime) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			ship->moveLeft(deltaTime);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			ship->moveRight(deltaTime);
		}
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			&& counterToShoot >= timeToShoot)
		{
			counterToShoot = 0;
			Bullet* bullet = new Bullet(&window, ship->getPosition());
			bullets.push_back(bullet);
		}
	}
}
