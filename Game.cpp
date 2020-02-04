#include "DEFINITIONS.h"
#include "Game.h"
#include <stdlib.h>

namespace SpaceInvaders {
	Game::Game(int width, int height, sf::String title) {
		window.create(sf::VideoMode(width, height), title);
		ship = new Ship(&window);
		this->Run();
	};

	void Game::Run() {
		while (window.isOpen())
		{
			sf::Time dt = _clock.restart();
			float deltatime = dt.asSeconds();
			// check all the window's events that were triggered since the last iteration of the loop
			sf::Event event;
			while (window.pollEvent(event))
			{
				// "close requested" event: we close the window
				if (event.type == sf::Event::Closed)
					window.close();
			}
			window.clear();
			ship->Update(deltatime);
			window.display();
		}
	}
}
