#pragma once
#include "Framework/GameObject.h"
#include "Framework/Vector.h"
class Paddle2 :
	public GameObject
{
public:
	Paddle2();
	~Paddle2();

	void handleInput(float dt);
	void update(float dt);

	//Window 
	void setWindow(sf::RenderWindow* hwnd) { window = hwnd; }
	//Window Component
	sf::RenderWindow* window;
private:
	sf::Vector2f velocity;
	sf::Vector2f target;
	sf::Vector2f direction;

};

