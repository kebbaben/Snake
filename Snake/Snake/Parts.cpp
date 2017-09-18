#include "Parts.h"

Parts::Parts() :
	body()
{
	body.setSize(sf::Vector2f(32, 32));
	body.setFillColor(sf::Color::Green);
	body.setPosition(-64, -64);
}

void Parts::Draw(sf::RenderWindow& win)
{
	win.draw(body);
}

const sf::RectangleShape & Parts::GetPart() const
{
	return body;
}

Head::Head()
{
	body.setSize(sf::Vector2f(32, 32));
	body.setFillColor(sf::Color::Magenta);
	body.setPosition(256, 256);
}

void Head::Update()
{
	Move();

	//std::cout << body.getPosition().x << " " << body.getPosition().y << std::endl;
}

void Head::Move()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		dir = { 0,0 };
		dir.x = -32.0f;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		dir = { 0,0 };
		dir.x = 32.0f;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		dir = { 0,0 };
		dir.y = -32.0f;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		dir = { 0,0 };
		dir.y = 32.0f;
	}
	body.move(dir);

	//border collisions
	if (body.getPosition().x < 0) //left border
	{
		body.setPosition(800 - 32, body.getPosition().y);
	}
	else if (body.getPosition().x >= 800) //right border
	{
		body.setPosition(0, body.getPosition().y);
	}
	else if (body.getPosition().y < 0) //top border
	{
		body.setPosition(body.getPosition().x, 640 - 32);
	}
	else if (body.getPosition().y >= 640) //bot border
	{
		body.setPosition(body.getPosition().x, 0);
	}
}


Body::Body(const Parts& target_)
	: target(&target_)
{
}

void Body::Update()
{
	body.setPosition(target->GetPart().getPosition());
}