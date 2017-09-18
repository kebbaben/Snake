#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>

class Parts
{
public:
	Parts();

	virtual void Update() = 0;
	void Draw(sf::RenderWindow& win);

	const sf::RectangleShape& GetPart() const;

//protected:
	sf::RectangleShape body;
};

class Head : public Parts
{
public:
	Head();

	void Update();

private:
	sf::Vector2f dir{ 32, 0 };

	void Move();
};

class Body : public Parts
{
public:
	Body(const Parts& target_);

	void Update();

private:
	const Parts* target;
};
