#pragma once

#include "SFML\Graphics.hpp"
#include "Ship.h"
#include "Enemy.h"
#include <iostream>
#include <vector>

namespace SpaceInvaders {
	class Game
	{
	public:
		~Game() {};
		Game(int width, int height, sf::String title);


	private:
		const float dt = 1.0f / 60.0f;
		sf::Clock _clock;
		Ship* ship;
		std::vector<Enemy*> enemies;
		sf::RenderWindow window;
		void run();
		void createEnemies();
		void moveEnemies(float deltaTime);
		bool rightMove;
		bool moveDown;
	};
}
