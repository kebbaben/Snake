#include "Snake.h"

Snake::Snake()
{
	part.push_back(new Head()); //helig pushback kod
	AddObject();
	AddObject();
	AddObject();
}

void Snake::Draw(sf::RenderWindow& renderWindow)
{
	for (int i = 0; i < part.size(); i++)
	{
		part[i]->Draw(renderWindow);
	}
}

void Snake::AddObject()
{
	part.push_back(new Body(*part[part.size() - 1])); //helig pushback kod
}

void Snake::Update(float deltaTime)
{
	static const float fixedFrameStep = 1.0f / 5.0f;
	static float frameTime = 0.0f;

	frameTime += deltaTime;
	if (frameTime > fixedFrameStep)
	{
		for (int i = part.size() - 1; i >= 0; i--)
		{
			part[i]->Update();
		}
		frameTime -= fixedFrameStep;
	}

	for (int i = 1; i <= part.size() - 1; i++)
	{
		if (part[0]->GetPart().getGlobalBounds().intersects(part[i]->GetPart().getGlobalBounds()))
		{
			isAlive = false;
			break;
		}
	}

	CheckHit();
}

bool Snake::CheckAlive()
{
	return isAlive;
}

void Snake::CheckHit()
{
	if (part[0]->body.getGlobalBounds().intersects(pickUp.GetPickUp().getGlobalBounds()))
	{
		AddObject();
		int rng = pickUp.GetPos();
		pickUp.SetPosition(rng);
		std::cout << pickUp.GetPickUp().getPosition().x << " " << pickUp.GetPickUp().getPosition().y << std::endl;
	}
}
