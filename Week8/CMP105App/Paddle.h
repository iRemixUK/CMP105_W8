#pragma once
#include "Framework/GameObject.h"
class Paddle :
	public GameObject
{
public:

	Paddle();
	~Paddle();

	void handleInput(float dt);
	void update(float dt);

	//Window 
	void setWindow(sf::RenderWindow* hwnd) { window = hwnd; }
	//Window Component
	sf::RenderWindow* window;

private:
	sf::Vector2f velocity;
};

