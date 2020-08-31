#include "RectOutline.hpp"

#include <cmath>
#include <math.h>

void RectOutline::rotateByCenter(int angle)
{
	left_top.rotateBy(center, angle);
	left_bottom.rotateBy(center, angle);
	right_bottom.rotateBy(center, angle);
	right_top.rotateBy(center, angle);
}

void RectOutline::drawOn(SDL_Renderer * renderer)
{
	constexpr auto POINTS = 5;

	SDL_Point points[POINTS] = {
		{ left_top.x, left_top.y },
		{ left_bottom.x, left_bottom.y },
		{ right_bottom.x, right_bottom.y },
		{ right_top.x, right_top.y },
		{ left_top.x, left_top.y }
	};

	SDL_RenderDrawLines(renderer, points, POINTS);
}
