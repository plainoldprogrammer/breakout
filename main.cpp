#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	bool isBallFalling = true;

    sf::RenderWindow window(sf::VideoMode(800, 600), "Breakout Clone");

    sf::RectangleShape bar;
    bar.setSize(sf::Vector2f(100, 20));
    bar.setOutlineColor(sf::Color::Red);
    bar.setOutlineThickness(3);
    bar.setPosition(350, 550);

	sf::CircleShape ball;
	ball.setRadius(3);
	sf::Color colorOutlineBall(150, 150, 150);
	ball.setOutlineColor(colorOutlineBall);
	sf::Color colorFillBall(100, 100, 100);
	ball.setFillColor(colorFillBall);
	ball.setOutlineThickness(3);
	ball.setPosition(400, 300);

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
					bar.setPosition(bar.getPosition().x - 18, bar.getPosition().y);
				}
				else if (event.key.code == sf::Keyboard::Right)
				{
					std::cout << "right key" << std::endl;
					bar.setPosition(bar.getPosition().x + 18, bar.getPosition().y);
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
		if (((int) (ball.getPosition().y + (ball.getRadius() * 2) + ball.getOutlineThickness() )) == ((int) (bar.getPosition().y - bar.getOutlineThickness()) ))
		{
			std::cout << "ball collide with bar" << std::endl;
			isBallFalling = false;
		}

		window.clear();
		window.draw(bar);
		window.draw(ball);
		window.display();
    }

    return 0;
}
