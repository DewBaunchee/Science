#include "PythagorasTree.h"

#define PI 3.14159265   

PythagorasTree::PythagorasTree(sf::RenderWindow* window) {
	_window = window;
}

void PythagorasTree::draw(int maxIteration, float x, float y, double branchLength, double rotate) {
	if (maxIteration == 0) return;

	sf::RectangleShape line(sf::Vector2f(branchLength, 1));
	line.move(x, y);
	line.setFillColor(sf::Color(255, 255, 255));
	line.rotate(rotate);

	_window->draw(line);

	double rightBranchLength = branchLength * 0.75;
	double leftBranchLength = branchLength * 0.75;

	double radianRotate = rotate * PI / 180;
	double newRightRotate = rotate + 45;
	double newLeftRotate = rotate - 45;
	
	draw(maxIteration - 1, 
		x + branchLength * cos(radianRotate),
		y + branchLength * sin(radianRotate),
		rightBranchLength, newRightRotate);
	draw(maxIteration - 1, 
		x + branchLength * cos(radianRotate),
		y + branchLength * sin(radianRotate),
		leftBranchLength, newLeftRotate);
}