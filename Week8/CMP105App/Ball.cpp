#include "Ball.h"
Ball::Ball()
{
	velocity.x = 50;
}

void Ball::update(float dt)
{
	sf::Vector2f ObjectSize = getSize();
	sf::Vector2u WinSize = window->getSize();
	move(velocity * dt);
	if (getPosition().x < 0)
	{
		setPosition(0, getPosition().y);
		velocity.x = -velocity.x;
	}
	if (getPosition().x > WinSize.x - ObjectSize.x)
	{
		setPosition(WinSize.x - ObjectSize.x, getPosition().y);
		velocity.x = -velocity.x;
	}
}
void Ball::collisionResponse(GameObject* collider)
{
	velocity.x = -velocity.x;
}

void Ball::setVelocity(float Velocity)
{
	Velocity = velocity.x;
}
Ball::~Ball()
{

}