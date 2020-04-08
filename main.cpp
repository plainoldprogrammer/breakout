#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "Bar.h"
#include "Ball.h"
#include "Brick.h"
#include "easylogging++.h"

INITIALIZE_EASYLOGGINGPP

#define BALL_VELOCITY 0.8

void create_bricks(std::vector<Brick *> &);

void draw_bricks(std::vector<Brick *> &, sf::RenderWindow &);

int main()
{
	bool isBallFalling = true;

    sf::RenderWindow window(sf::VideoMode(800, 600), "Breakout Clone");

	Bar playerBar;
	Ball ball;
	std::vector<Brick *> bricks;
	create_bricks(bricks);

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
		if (((int) (ball.getPosition().y + (ball.getRadius() * 2) + ball.getOutlineThickness() )) == ((int) (playerBar.getPosition().y - playerBar.getOutlineThickness()) ))
		{
			LOG(INFO) << "ball collide with bar top surface";
			isBallFalling = false;
		}
		//	The thickness of the playerBar is considered
		if ( ( (ball.getPosition().x + 6) >= (playerBar.getPosition().x) ) && ( ball.getPosition().x < ( playerBar.getPosition().x + 100 + 6 )) )
		{
			// LOG(INFO) << "ball is in the limits of the player bar";
		}

		window.clear();
		window.draw(playerBar);
		window.draw(ball);

		// Draw the bricks.
		draw_bricks(bricks, window);

		// Display the graphics.
		window.display();
    }


	std::vector<Brick *>::iterator it = bricks.begin();

	while (it != bricks.end())
	{
		Brick * brick_to_delete = *it;
		it++;
		delete brick_to_delete;
	}

    return 0;
}


void create_bricks(std::vector<Brick *> & bricks_vector)
{
	Brick * the_brick = new Brick();
	the_brick->setPosition((0) + 45, 30);
	bricks_vector.push_back(the_brick);

	the_brick = new Brick();
	the_brick->setPosition((120 + 45), 30);
	bricks_vector.push_back(the_brick);

	LOG(INFO) << "End of create_bricks() call";
}


void draw_bricks(std::vector<Brick *> & bricks_vector, sf::RenderWindow & window)
{
	std::vector<Brick *>::iterator it = bricks_vector.begin();

	while (it != bricks_vector.end())
	{
		window.draw(*(*it));
		it++;
	}

}

