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

void Line::drawOn(SDL_Renderer * renderer)
{
	constexpr auto POINTS = 2;

	SDL_Point points[POINTS] = { start.toSDL(), end.toSDL() };

	SDL_RenderDrawLines(renderer, points, POINTS);
}
