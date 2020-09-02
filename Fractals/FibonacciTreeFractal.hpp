#pragma once

#include <SDL.h>
#include <vector>
#include <cmath>

#include "IStage.hpp"
#include "Point.hpp"
#include "Line.hpp"

class FibonacciTreeFractal: public IStage
{
public:
	void initialize() {}
	void draw(int screen_width, int screen_height, SDL_Renderer* renderer);
	void cleanup() {};

private:
};

