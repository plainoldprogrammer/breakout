#include <SFML/Graphics.hpp>
#include <iostream>

#include "Bar.h"
#include "Ball.h"

int main()
{
	bool isBallFalling = true;

    sf::RenderWindow window(sf::VideoMode(800, 600), "Breakout Clone");

    Bar playerBar;
	Ball ball;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
			else if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Left)
				{
					std::cout << "left key" << std::endl;
					playerBar.setPosition(playerBar.getPosition().x - 18, playerBar.getPosition().y);
				}
				else if (event.key.code == sf::Keyboard::Right)
				{
					std::cout << "right key" << std::endl;
					playerBar.setPosition(playerBar.getPosition().x + 18, playerBar.getPosition().y);
				}
			}
        }

		// Drop the ball.
		if (isBallFalling)
		{
			ball.setPosition(ball.getPosition().x, ball.getPosition().y + 0.03);
		}
		else
		{
			ball.setPosition(ball.getPosition().x, ball.getPosition().y - 0.03);

			if (ball.getPosition().y < 0)
			{
				isBallFalling = true;
			}
		}

		// printf("%.2f\t%.2f\n", ball.getPosition().y, bar.getPosition().y);
		if (((int) (ball.getPosition().y + (ball.getRadius() * 2) + ball.getOutlineThickness() )) == ((int) (playerBar.getPosition().y - playerBar.getOutlineThickness()) ))
		{
			std::cout << "ball collide with bar" << std::endl;
			isBallFalling = false;
		}

		window.clear();
		window.draw(playerBar);
		window.draw(ball);
		window.display();
    }

    return 0;
}
