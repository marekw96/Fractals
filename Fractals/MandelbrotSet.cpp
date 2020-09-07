#include "MandelbrotSet.hpp"

#include "Complex.hpp"

constexpr auto MAX_ITERATIONS = 80;

int mandelbrot(const Complex& c)
{
	Complex z;
	int iterations = 0;

	while (z.abs() <= 2 && iterations < MAX_ITERATIONS)
	{
		z = z * z + c;
		++iterations;
	}

	return iterations;
}

void MandelbrotSet::draw(int width, int height, SDL_Renderer * renderer)
{
	float r_start = -1.5;
	float r_stop = 0.5;
	float i_start = -1;
	float i_stop = 1;

	auto r_step = (r_stop - r_start) / width;
	auto i_step = (i_stop - i_start) / height;

	for (int y = 0; y < height; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			Complex c(r_start + x * r_step, i_start + y * i_step);
			auto m = mandelbrot(c);
			auto color = 255 - (m * 255 / MAX_ITERATIONS);


			SDL_SetRenderDrawColor(renderer, color, color, color, 0xFF);
			SDL_RenderDrawPoint(renderer, x, y);
		}
	}
}
