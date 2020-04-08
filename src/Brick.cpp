#include "Brick.h"

Brick::Brick()
{
	LOG(INFO) << "Brick constructor";

	setPosition(10, 10);
	setSize(sf::Vector2f(100, 20));
	setFillColor(sf::Color::Green);
	setOutlineThickness(1);
}

Brick::~Brick()
{
	//dtor
}

