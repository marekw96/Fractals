#include "Line.hpp"

#include <SDL.h>

void Line::rotateByCenter(int angle)
{
	rotateByPoint(center, angle);
}

void Line::rotateByPoint(const Point & point, int angle)
{
	start.rotateBy(point, angle);
	end.rotateBy(point, angle);
}

void Line::drawOn(SDL_Renderer * renderer) const
{
	constexpr auto POINTS = 2;

	SDL_Point points[POINTS] = { start.toSDL(), end.toSDL() };

	SDL_RenderDrawLines(renderer, points, POINTS);
}

int Line::getLength() const
{
	return start.distanceTo(end);
}

Line& Line::moveBy(int x, int y)
{
	start.moveBy(x, y);
	end.moveBy(x, y);

	return *this;
}

const Point & Line::getStart() const
{
	return start;
}

const Point & Line::getEnd() const
{
	return end;
}
