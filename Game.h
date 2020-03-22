#pragma once

#include "SFML\Graphics.hpp"
#include "Ship.h"
#include "Enemy.h"
#include "EndgameScreen.h"
#include "HUD.h"
#include <iostream>
#include <vector>
#include "SFML/Audio.hpp"

namespace SpaceInvaders {
	class Game
	{
	public:
		~Game() {};
		Game(int width, int height, sf::String title);
	private:
		const float dt = 1.0f / 60.0f;
		sf::Clock _clock;
		sf::Clock timerMoveEnemies;
		Ship* ship;
		std::vector<Enemy*> enemies;
		sf::RenderWindow window;
		void run();
		void createEnemies();
		void moveEnemies(float deltaTime);
		void checkFinishCondition();
		bool rightMove;
		bool moveDown;
		void readInput(float deltaTime);
		float counterToShoot = 1.5;
		const float timeToShoot = 1.5;
		void updateBullets(float deltaTime);
		std::vector<Bullet*> bullets;
		void checkBulletsCollision();
		HUD* hud;
		bool win;
		bool gameFinished;
		EndgameScreen* endgameScreen;
		void checkIfEnemiesAlive();
		float enemiesMoveTime = 1000;
		sf::SoundBuffer explosionSoundBuffer;
		sf::SoundBuffer shootSoundBuffer;
		sf::Sound explosionSound;
		sf::Sound shootSound;
	};
}
