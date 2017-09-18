#pragma once
#include <SFML/Graphics.hpp>
#include "Snake.h"

class Game
{
public:
	Game();
	~Game();

	void Update();
	const sf::RenderWindow& GetWindow() const;
	const sf::RenderWindow& CloseWindow();

private:
	sf::RenderWindow window;
	bool alive = true;
};
