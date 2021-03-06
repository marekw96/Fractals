#pragma once

#include <SDL.h>

class Point
{
public:
	Point(int x, int y) : x(x), y(y) {}

	void rotateBy(const Point& other, int angle);
	Point& moveBy(int x, int y);
	int distanceTo(const Point& other) const;
	SDL_Point toSDL() const;

	int x;
	int y;
};

