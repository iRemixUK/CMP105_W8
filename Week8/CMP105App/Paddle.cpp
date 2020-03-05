#include "Paddle.h"

Paddle::Paddle()
{
	velocity = sf::Vector2f(0.f,0.f);
}

void Paddle::update(float dt)
{
	sf::Vector2f ObjectSize = getSize();
	sf::Vector2u WinSize = window->getSize();
	move(velocity * dt);
	if (getPosition().x < 0)
	{
		setPosition(0, getPosition().y);

	}
	if (getPosition().x > WinSize.x - ObjectSize.x)
	{
		setPosition(WinSize.x - ObjectSize.x, getPosition().y);
		
	}
}
void Paddle::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::W)) // Up
	{
		 velocity.y = -200.f;
	}
	else if (input->isKeyDown(sf::Keyboard::S)) // Down
	{
		 velocity.y = 200.f;
	}
	else
	{
		velocity.y = 0;
	}
}

Paddle::~Paddle()
{

}