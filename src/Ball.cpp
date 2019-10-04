#include "Ball.h"

Ball::Ball()
{
	setRadius(3);
	sf::Color colorOutlineBall(150, 150, 150);
	setOutlineColor(colorOutlineBall);

	sf::Color colorFillBall(100, 100, 100);
	setFillColor(colorFillBall);

	setOutlineThickness(3);
	setPosition(400, 300);
}

Ball::~Ball()
{
}
