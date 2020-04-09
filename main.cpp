#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "Bar.h"
#include "Ball.h"
#include "Brick.h"
#include "easylogging++.h"

INITIALIZE_EASYLOGGINGPP

#define BALL_VELOCITY 2.5
#define NUMBER_OF_BRICKS 6

Brick ** create_bricks();

void draw_bricks(Brick **, sf::RenderWindow &);

void release_memory(Brick **);

int main()
{
	bool isBallFalling = true;

    sf::RenderWindow window(sf::VideoMode(800, 600), "Breakout Clone");

	Bar playerBar;
	Ball ball;
	Brick ** bricks = create_bricks();

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
					LOG(INFO) << "left key";
					playerBar.setPosition(playerBar.getPosition().x - 20, playerBar.getPosition().y);
				}
				else if (event.key.code == sf::Keyboard::Right)
				{
					LOG(INFO) << "right key";
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
		if (((int) (ball.getPosition().y + (ball.getRadius() * 2) + ball.getOutlineThickness() )) >= ((int) (playerBar.getPosition().y - playerBar.getOutlineThickness()) ))
		{
			LOG(INFO) << "ball collide with bar top surface";
			isBallFalling = false;
		}
		//	The thickness of the playerBar is considered
		if ( ( (ball.getPosition().x + 6) >= (playerBar.getPosition().x) ) && ( ball.getPosition().x < ( playerBar.getPosition().x + 100 + 6 )) )
		{
			// LOG(INFO) << "ball is in the limits of the player bar";
		}

		// Crear the whole window.
		window.clear();

		// Draw all the elements on the window.
		window.draw(playerBar);
		window.draw(ball);
		draw_bricks(bricks, window);

		// Display the graphics.
		window.display();
    }

	release_memory(bricks);

    return 0;
}


Brick ** create_bricks()
{
	Brick ** all_bricks = new Brick *[NUMBER_OF_BRICKS];

	for (int i = 0; i < NUMBER_OF_BRICKS; i++)
	{
		*(all_bricks + i) = new Brick();
		(*(all_bricks + i))->setPosition((120 * i) + 40, 30);
	}

	return all_bricks;
}


void draw_bricks(Brick ** bricks, sf::RenderWindow & window)
{
	for (int i = 0; i < NUMBER_OF_BRICKS; i++)
	{
		window.draw(*bricks[i]);
	}
}

void release_memory(Brick ** bricks)
{
	for (int i = 0; i < NUMBER_OF_BRICKS; i++)
	{
		delete *(bricks + i);
	}
}

