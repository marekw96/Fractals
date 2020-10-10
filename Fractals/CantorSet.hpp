#pragma once

#include "IStage.hpp"

class CantorSet :
	public IStage
{
	void initialize() {};
	void draw(int width, int height, SDL_Renderer* renderer);
	void cleanup() {};
    const char* name() { return "CantorSet"; }
};

