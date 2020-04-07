#include <SFML/Graphics.hpp>
#include <iostream>

#include "Bar.h"
#include "Ball.h"
#include "easylogging++.h"

INITIALIZE_EASYLOGGINGPP

#define BALL_VELOCITY 0.2

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
					playerBar.setPosition(playerBar.getPosition().x - 20, playerBar.getPosition().y);
				}
				else if (event.key.code == sf::Keyboard::Right)
				{
					std::cout << "right key" << std::endl;
					playerBar.setPosition(playerBar.getPosition().x + 20, playerBar.getPosition().y);
				}
			}
        }

		// Drop the ball.
		if (isBallFalling)
		{
			ball.setPosition(ball.getPosition().x, ball.getPosition().y + BALL_VELOCITY);
		}
		else
		{
			ball.setPosition(ball.getPosition().x, ball.getPosition().y - BALL_VELOCITY);

			if (ball.getPosition().y < 0)
			{
				isBallFalling = true;
			}
		}

		// printf("%.2f\t%.2f\n", ball.getPosition().y, bar.getPosition().y);
		if (((int) (ball.getPosition().y + (ball.getRadius() * 2) + ball.getOutlineThickness() )) == ((int) (playerBar.getPosition().y - playerBar.getOutlineThickness()) ))
		{
			std::cout << "ball collide with bar top surface" << std::endl;
			isBallFalling = false;
		}
		//	The thickness of the playerBar is considered
		if ( ( (ball.getPosition().x + 6) >= (playerBar.getPosition().x) ) && ( ball.getPosition().x < ( playerBar.getPosition().x + 100 + 6 )) )
		{
			std::cout << "ball is in the limits of the player bar" << std::endl;
		}

		window.clear();
		window.draw(playerBar);
		window.draw(ball);
		window.display();
    }

    return 0;
}
