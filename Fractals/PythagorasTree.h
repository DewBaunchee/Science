#pragma once

#include <SFML/Graphics.hpp>

class PythagorasTree
{
private:
	sf::RenderWindow* _window;
public:
	PythagorasTree(sf::RenderWindow*);
	void draw(int maxIteration, float x, float y, double branchLength, double rotate);
};
