#pragma once

#include "SFML\Graphics.hpp"
#include "Ship.h"

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
		sf::RenderWindow window;
		void Run();
	};
}
