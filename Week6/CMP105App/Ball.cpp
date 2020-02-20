#include "Ball.h"

Ball::Ball()
{
	
}

Ball::Ball(sf::RenderWindow* hwnd, Input* in)
{
	win = hwnd;
	input = in;

	//set scale
	scale=100.0f;
	
	//set gravity levels
	gravity = sf::Vector2f(0, 9.8f) * scale;

	//set jumping level
	jumpLevel = sf::Vector2f(0, -7.0f) * scale;

	//Jumping true
	isJumping = false;

}

Ball::~Ball()
{

}

void Ball::update(float dt)
{
	//gravity
	stepVelocity+=gravity *dt; // v = u + at  note the += is not =
	sf::Vector2f pos = stepVelocity * dt + 0.5f * gravity * dt * dt; //ut+ 1/2at^2
	setPosition(getPosition() +pos);
	
	//get window size
	sf::Vector2u windowPos = win->getSize();
	sf::Vector2f ballPos = getPosition();

	//stop ball at bottom of window
	if (ballPos.y >= windowPos.y-100) 
	{	
		isJumping = false;
		setPosition(getPosition().x, windowPos.y-100);
		stepVelocity = sf::Vector2f(0, 0);
	}

}

void Ball::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Space))
	{
		if (!isJumping)
		{
			stepVelocity = jumpLevel;
			isJumping = true;
		}
	}
}
