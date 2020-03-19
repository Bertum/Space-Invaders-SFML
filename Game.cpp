#include "DEFINITIONS.h"
#include "Game.h"
#include <stdlib.h>

namespace SpaceInvaders {
	Game::Game(int width, int height, sf::String title) {
		window.create(sf::VideoMode(width, height), title);
		ship = new Ship(&window);
		hud = new HUD(&window);
		endgameScreen = new EndgameScreen(&window);
		createEnemies();
		rightMove = true;
		moveDown = false;
		explosionSoundBuffer.loadFromFile(EXPLOSION_SOUND_FILEPATH);
		explosionSound.setBuffer(explosionSoundBuffer);
		shootSoundBuffer.loadFromFile(SHOOT_SOUND_FILEPATH);
		shootSound.setBuffer(shootSoundBuffer);
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
			if (!gameFinished)
			{
				counterToShoot += deltaTime;
				readInput(deltaTime);
				moveEnemies(deltaTime);
				updateBullets(deltaTime);
				checkFinishCondition();
				ship->update(deltaTime);
				checkBulletsCollision();
				hud->draw();
				checkIfEnemiesAlive();
			}
			else
			{
				endgameScreen->draw(win);
			}
			window.display();
		}
	}

	void Game::createEnemies() {
		for (unsigned short int i = 0; i < 10; i++)
		{
			for (unsigned short int k = 0; k < 5; k++)
			{
				Enemy* enemy = new Enemy(&window, 50 * (i + 1), 50 * (k + 1), k);
				enemies.push_back(enemy);
			}
		}
	}

	void Game::moveEnemies(float deltaTime) {

		bool tempMoveDown = moveDown;
		bool tempRightMove = rightMove;
		bool moveEnemies = timerMoveEnemies.getElapsedTime().asMilliseconds() > enemiesMoveTime;
		for (unsigned short int i = 0; i < enemies.size(); i++)
		{
			if (moveEnemies)
			{
				if (tempMoveDown) {
					moveDown = false;
					enemies[i]->moveDown();
				}
				else
				{
					enemies[i]->move(timerMoveEnemies.getElapsedTime().asSeconds(), rightMove);
					if (enemies[i]->endOfScreen())
					{
						moveDown = true;
						tempRightMove = !tempRightMove;
					}
				}
			}
			enemies[i]->update();
		}
		rightMove = tempRightMove;
		if (moveEnemies)
		{
			timerMoveEnemies.restart();
		}
	}


	void Game::checkFinishCondition() {
		for (unsigned short int i = 0; i < enemies.size(); i++)
		{
			if (enemies[i]->reachPlayer())
			{
				gameFinished = true;
				win = false;
				endgameScreen->saveScore(hud->score);
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
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) && (ship->getPosition().x - ship->getSprite().getLocalBounds().width / 2) > 0)
		{
			ship->moveLeft(deltaTime);
		}
		else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) && (ship->getPosition().x + ship->getSprite().getLocalBounds().width / 2) < window.getSize().x)
		{
			ship->moveRight(deltaTime);
		}
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			&& counterToShoot >= timeToShoot)
		{
			counterToShoot = 0;
			Bullet* bullet = new Bullet(&window, ship->getPosition());
			bullets.push_back(bullet);
			shootSound.play();
		}
	}

	void Game::checkBulletsCollision() {
		for (unsigned short int i = 0; i < bullets.size(); i++)
		{
			for (unsigned short int k = 0; k < enemies.size(); k++)
			{
				if (bullets[i]->isActive && enemies[k]->isAlive &&
					bullets[i]->getRectangleShape().getGlobalBounds().intersects(enemies[k]->getSprite().getGlobalBounds()))
				{
					hud->score += 100;
					explosionSound.play();
					bullets[i]->isActive = false;
					enemies[k]->isAlive = false;
				}
			}
		}
	}

	void Game::checkIfEnemiesAlive() {
		bool anyAlive = false;
		for (unsigned short int i = 0; i < enemies.size(); i++)
		{
			if (enemies[i]->isAlive)
			{
				anyAlive = true;
			}
		}
		if (!anyAlive) {
			gameFinished = true;
			win = true;
			endgameScreen->saveScore(hud->score);
		}
	}
}
