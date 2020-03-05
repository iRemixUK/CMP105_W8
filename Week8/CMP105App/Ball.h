#pragma once
#include "Framework/GameObject.h"
class Ball :
	public GameObject
{
public:
	Ball();
	~Ball();
	void update(float dt);
	void collisionResponse(GameObject* collider);
	void setVelocity(float velocity);
	//Window 
	void setWindow(sf::RenderWindow* hwnd) { window = hwnd; }
	//Window Component
	sf::RenderWindow* window;

private:
	sf::Vector2f velocity;
};

