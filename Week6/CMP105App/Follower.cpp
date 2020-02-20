#include "Follower.h"

Follower::Follower(sf::RenderWindow* hwnd, Input* in)
{
	win = hwnd;
	input = in;

	speed = 100.f;
}

Follower::~Follow()
{
}

void Follower::update(float dt)
{
	
	//set target to corner
	sf::Vector2u windowsize = win->getSize();
	sf::Vector2f target= (windowsize.x, windowsize.y);

	
	// calculate direction and move
	direction = target -getPosition();
	direction =Vector::normalise(direction);
	velocity =(direction *speed);
	setPosition(getPosition() + (velocity*dt));
	
	// if object is close enough to target
	if(Vector::magnitude(target -getPosition()) < 10.f)
	{
		setPosition(target);
	}

}
