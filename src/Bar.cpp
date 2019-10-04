#include "Bar.h"

Bar::Bar()
{
    setPosition(350, 550);
    setSize(sf::Vector2f(100, 20));
    setOutlineColor(sf::Color::Red);
    setOutlineThickness(3);
}

Bar::~Bar()
{
    //dtor
}
