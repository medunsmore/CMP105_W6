#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include <string.h>
#include <iostream>
#include "Framework/GameObject.h"
#include "Framework/Vector.h"

class Follow : public GameObject
{
public:
	
	Follower(sf::RenderWindow* hwnd, Input* in);
	~Follower();
	
	sf::Vector2f direction;
	sf::Vector2f target;
	float speed;
	
	void update(float dt);
	

private:
	sf::RenderWindow* win;

};