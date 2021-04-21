#include <SFML/Graphics.hpp>
#include "Mandelbrot.h"
#include "PythagorasTree.h"
#include <iostream>
int main()
{
    sf::RenderWindow window(sf::VideoMode(1800, 900), "SFML works!");
    PythagorasTree tree(&window);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        tree.draw(15, 1000, 700, 100, -90);
        window.display();
    }

    return 0;
}
