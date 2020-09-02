#include "SelfSimilarSquares.hpp"

#include <cmath>

#include "RectOutline.hpp"

void SelfSimilarSquares::draw(int screen_width, int screen_height, SDL_Renderer * renderer)
{
	double size = std::fmin(screen_width, screen_height);
	int start_x = screen_width / 2;
	int start_y = screen_height / 2;
	int rotation_angle = 45;
	int iterations = 16;

	for (int i = 1; i <= iterations; ++i)
	{
		RectOutline rect(start_x, start_y, static_cast<int>(size), static_cast<int>(size));
		if (i % 2 == 0)
			rect.rotateByCenter(rotation_angle);
		rect.drawOn(renderer);

		size = std::sqrt(2 * (0.5 * size) *(0.5 * size));
	}
}
