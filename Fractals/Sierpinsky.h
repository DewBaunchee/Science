#pragma once

#include <SFML/Graphics.hpp>

class Sierpinsky
{
private:
	sf::RenderWindow* _window;
	sf::Vector2f getMiddlePoint(sf::Vector2f first, sf::Vector2f second);
	void recFill(int maxIteration, sf::Vector2f points[3]);
public:
	Sierpinsky(sf::RenderWindow*);
	void draw(int maxIteration, sf::Vector2f points[3]);
};

