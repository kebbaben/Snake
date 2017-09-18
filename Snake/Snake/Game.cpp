#include "Game.h"



Game::Game()
{
	window.create(sf::VideoMode(800, 640), "snek");
}

Game::~Game()
{
	//window.close();
}

void Game::Update()
{
	sf::Clock clock;
	Snake snake;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		float deltaTime = clock.restart().asSeconds();

		alive = snake.CheckAlive();
		if (alive == false) {
			window.close();
			break;
		}

		window.clear();

		snake.Update(deltaTime);
		snake.Draw(window);
		snake.pickUp.Draw(window);
		
		window.display();
	}
}

const sf::RenderWindow & Game::GetWindow() const
{
	return window;
}

const sf::RenderWindow & Game::CloseWindow()
{
	window.close();
	return window;
}
