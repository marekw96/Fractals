#pragma once

#include "IStage.hpp"

class MandelbrotSet :
	public IStage
{
	void initialize() {};
	void draw(int width, int height, SDL_Renderer* renderer);
	void cleanup() {};
    const char* name() { return "MandelbrotSet"; }
};

