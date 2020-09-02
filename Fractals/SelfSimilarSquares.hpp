#pragma once

#include "IStage.hpp"

class SelfSimilarSquares :
	public IStage
{
public:
	void initialize() {}
	void draw(int screen_width, int screen_height, SDL_Renderer* renderer);
	void cleanup() {};
};

