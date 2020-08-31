#pragma once

class Point
{
public:
	Point(int x, int y) : x(x), y(y) {}

	void rotateBy(const Point& other, int angle);

	int x;
	int y;
};

