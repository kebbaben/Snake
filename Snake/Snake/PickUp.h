#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>
#include <time.h> 

class PickUp
{
public:
	PickUp();

	const sf::RectangleShape& GetPickUp() const;
	void SetPosition(int rng);
	void Draw(sf::RenderWindow& win);
	void VectorPos();
	int GetPos();

private:
	std::vector<sf::Vector2f*> pos;
	sf::RectangleShape pickUp;
	void Start();
};

