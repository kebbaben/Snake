#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

#include "Parts.h"
#include "PickUp.h"

class Snake
{
public:
	Snake();

	PickUp pickUp;
	void Draw(sf::RenderWindow& window);
	void AddObject();
	void Update(float deltaTime);
	bool CheckAlive();
	void CheckHit();

private:
	bool isAlive = true;
	std::vector<Parts*> part;
};