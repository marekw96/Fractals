#include "RectOutline.hpp"

#include <cmath>
#include <math.h>

void RectOutline::rotateByCenter(int angle)
{
	for (auto& line : lines)
		line.rotateByPoint(center, angle);
}

void RectOutline::drawOn(SDL_Renderer * renderer)
{
	for (auto& line : lines)
		line.drawOn(renderer);
}
