#include "Sierpinsky.h"

Sierpinsky::Sierpinsky(sf::RenderWindow* renderWindow) {
	_window = renderWindow;
}

void Sierpinsky::draw(int maxIteration, sf::Vector2f points[3]) {
	sf::ConvexShape mainTriangle;
	mainTriangle.setPointCount(3);
	mainTriangle.setFillColor(sf::Color::Black);

	mainTriangle.setPoint(0, points[0]);
	mainTriangle.setPoint(1, points[1]);
	mainTriangle.setPoint(2, points[2]);
	_window->draw(mainTriangle);

	recFill(maxIteration - 1, points);
}

void Sierpinsky::recFill(int maxIteration, sf::Vector2f points[3]) {
	if (maxIteration == 0) return;

	sf::Vector2f fillPoints[3] = {
		getMiddlePoint(points[0], points[1]),
		getMiddlePoint(points[1], points[2]),
		getMiddlePoint(points[0], points[2])
	};

	sf::ConvexShape mainTriangle;
	mainTriangle.setPointCount(3);
	mainTriangle.setFillColor(sf::Color::White);

	mainTriangle.setPoint(0, fillPoints[0]);
	mainTriangle.setPoint(1, fillPoints[1]);
	mainTriangle.setPoint(2, fillPoints[2]);
	_window->draw(mainTriangle);
	
	sf::Vector2f firstTriangle[3] = {
		points[0], fillPoints[0], fillPoints[2]
	};
	recFill(maxIteration - 1, firstTriangle);

	sf::Vector2f secondTriangle[3] = {
		points[1], fillPoints[0], fillPoints[1]
	};
	recFill(maxIteration - 1, secondTriangle);

	sf::Vector2f thirdTriangle[3] = {
		points[2], fillPoints[1], fillPoints[2]
	};
	recFill(maxIteration - 1, thirdTriangle);
}

sf::Vector2f Sierpinsky::getMiddlePoint(sf::Vector2f first, sf::Vector2f second) {
	return sf::Vector2f(
		first.x + (second.x - first.x) / 2, 
		first.y + (second.y - first.y) / 2
	);
}
