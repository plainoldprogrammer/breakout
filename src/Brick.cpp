#include "Brick.h"

Brick::Brick()
{
	setPosition(10, 10);
	setSize(sf::Vector2f(100, 20));
	setFillColor(sf::Color::Green);
	setOutlineThickness(0);
}

Brick::~Brick()
{
}

