#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	texture.loadFromFile("gfx/Beach_ball.png");

	ball.setTexture(&texture);
	ball.setPosition(0, 200);
	ball.setSize(sf::Vector2f(50, 50));
	ball.setPosition(300, 200); 
	ball.setWindow(window);
	ball.setCollisionBox(sf::FloatRect(0, 0, 50, 50));

	paddle1.setPosition(100, 200);
	paddle1.setSize(sf::Vector2f(50, 200)); 
	paddle1.setCollisionBox(sf::FloatRect(0, 0, 50, 200));
	paddle1.setFillColor(sf::Color::Blue);
	paddle1.setWindow(window);
	paddle1.setInput(input);

	paddle2.setPosition(1100, 200);
	paddle2.setSize(sf::Vector2f(50, 200));
	paddle2.setCollisionBox(sf::FloatRect(0, 0, 50, 200));
	paddle2.setFillColor(sf::Color::Green);
	paddle2.setWindow(window);
	paddle2.setInput(input);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	paddle1.handleInput(dt);
	paddle2.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	ball.update(dt);
	paddle1.update(dt);
	paddle2.update(dt);

	if (Collision::checkBoundingBox(&ball, &paddle1))
	{ 
		ball.collisionResponse(NULL);
		
	}

	if (Collision::checkBoundingBox(&ball, &paddle2))
	{
		ball.collisionResponse(NULL);

	}
}

// Render level
void Level::render()
{
	beginDraw();

	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
	window->draw(ball);
	window->draw(paddle1);
	window->draw(paddle2);
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}