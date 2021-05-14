#include <SFML/Graphics.hpp>
#include "Mandelbrot.h"
#include "PythagorasTree.h"
#include "Sierpinsky.h"
#include <iostream>
int main()
{
    sf::RenderWindow window(sf::VideoMode(1800, 900), "SFML works!");
    sf::Vector2f points[3] = {
        sf::Vector2f(100, 100),
        sf::Vector2f(100, 700),
        sf::Vector2f(1000, 700)
    };
    Sierpinsky tri(&window);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);
        tri.draw(8, points);
        window.display();
    }

    return 0;
}
