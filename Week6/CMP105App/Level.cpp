#include "Level.h"
#include "Ball.h"
#include "Follower.h"


Level::Level(sf::RenderWindow* hwnd, Input* in):
	ball(hwnd, in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	
	//ball
	ballTexture.loadFromFile("gfx/Beach_Ball.png");
	ball = Ball(window, input);
	ball.setTexture(&ballTexture);
	ball.setSize(sf::Vector2f(100, 100));
	
	//window size for ball position
	sf::Vector2u pos = window->getSize();
	ball.setPosition(350, pos.y + 100);

	//follower
	followTexture.loadFromFile("gfx/Goomba.png");
	follow = Follow(window, input);
	follow.setTexture(&followTexture);
	follow.setSize(sf::Vector2f(50, 50));
	follow.setPosition(50, 50);

}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	ball.handleInput(dt);
	
}

// Update game objects
void Level::update(float dt)
{
	ball.update(dt);
	follow.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(ball);
	window->draw(follow);

	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}