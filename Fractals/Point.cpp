#include "Point.hpp"

#include <cmath>
#define _USE_MATH_DEFINES
#include <math.h>

void Point::rotateBy(const Point & other, int angle)
{
	//https://gamefromscratch.com/gamedev-math-recipes-rotating-one-point-around-another-point/
	auto angle_rad = (M_PI / 180) * angle; // to radians

	auto rotatedX = std::cos(angle_rad) * (x - other.x) - std::sin(angle_rad) * (y - other.y) + other.x;
	auto rotatedY = std::sin(angle_rad) * (x - other.x) + std::cos(angle_rad) * (y - other.y) + other.y;

	x = static_cast<int>(rotatedX);
	y = static_cast<int>(rotatedY);
}

Point& Point::moveBy(int x, int y)
{
	this->x += x;
	this->y += y;

	return *this;
}

SDL_Point Point::toSDL() const
{
	return { x, y };
}
