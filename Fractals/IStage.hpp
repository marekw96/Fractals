#pragma once

#include <SDL.h>

class IStage
{
public:
	virtual ~IStage() {}

	virtual void initialize() = 0;
	virtual void draw(int width, int height, SDL_Renderer* renderer) = 0;
	virtual void cleanup() = 0;
    virtual const char* name() = 0;
};
