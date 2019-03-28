#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Breakout Clone");
    sf::RectangleShape bar;
    bar.setSize(sf::Vector2f(100, 20));
    bar.setOutlineColor(sf::Color::Red);
    bar.setOutlineThickness(3);
    bar.setPosition(350, 550);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear();
        window.draw(bar);
        window.display();
    }

    return 0;
}
