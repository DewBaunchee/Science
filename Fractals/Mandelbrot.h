#pragma once

#include <complex>
#include <SFML/Graphics.hpp>

class Mandelbrot
{
public:
	static sf::Image getImage(int maxIteration, unsigned int width, unsigned int height);
};

