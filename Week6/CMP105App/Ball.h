#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include <string.h>
#include <iostream>
#include "Framework/GameObject.h"
#include "Framework/Vector.h"


class Ball: public GameObject
{
public:

	Ball();
	Ball(sf::RenderWindow* hwnd, Input* in);
	~Ball();

	float scale;
	sf::Vector2f gravity;
	sf::Vector2f stepVelocity;
	sf::Vector2f jumpLevel;

	bool isJumping;

	void update(float dt);
	void handleInput(float dt);

private:
	// Default variables for level class.
	sf::RenderWindow* win;

};