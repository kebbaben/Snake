#include <ctime>
#include "PickUp.h"

PickUp::PickUp()
{
	Start();
}

void PickUp::VectorPos()
{
	for (float i = 0; i < 800 / 32; i++)
	{
		for (float j = 0; j < 640 / 32; j++)
		{
			pos.push_back(new sf::Vector2f(i * 32, j * 32));
		}
	}
}

int PickUp::GetPos()
{
	int rng = rand() % pos.size() - 1;
	return rng;
}

void PickUp::Start()
{
	srand(time(NULL));
	pickUp.setSize(sf::Vector2f(32, 32));
	pickUp.setFillColor(sf::Color::Yellow);

	VectorPos();

	int randomIndex = rand() % pos.size();
	pickUp.setPosition(pos[randomIndex]->x, pos[randomIndex]->y);
}

const sf::RectangleShape & PickUp::GetPickUp() const
{
	return pickUp;
}

void PickUp::SetPosition(int rng)
{
	pickUp.setPosition(pos[rng]->x, pos[rng]->y);
}

void PickUp::Draw(sf::RenderWindow & win)
{
	win.draw(pickUp);
}

