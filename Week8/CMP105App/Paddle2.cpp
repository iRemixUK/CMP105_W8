#include "Paddle2.h"

Paddle2::Paddle2()
{
	velocity = sf::Vector2f(0.f, 0.f);
}

void Paddle2::update(float dt)
{
	sf::Vector2f ObjectSize = getSize();
	sf::Vector2u WinSize = window->getSize();
	setPosition(getPosition().x, input->getMouseY());
	if (getPosition().x < 0)
	{
		setPosition(0, getPosition().y);

	}
	if (getPosition().x > WinSize.x - ObjectSize.x)
	{
		setPosition(WinSize.x - ObjectSize.x, getPosition().y);

	}
}
void Paddle2::handleInput(float dt)
{
	target = sf::Vector2f(0, input->getMouseY());
}

Paddle2::~Paddle2()
{

}