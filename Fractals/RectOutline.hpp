#pragma once
#include <SDL.h>

#include "Point.hpp"
#include "Line.hpp"


constexpr auto RECT_LINES = 4;

class RectOutline {
public:
	RectOutline(int x, int y, int width, int height)
		: center(x,y),
		lines{ {x - width / 2, y - height / 2, x - width / 2, y + height / 2},
			   {x - width / 2, y + height / 2, x + width / 2, y + height / 2},
			   {x + width / 2, y + height / 2, x + width / 2, y - height / 2},
			   {x + width / 2, y - height / 2, x - width / 2, y - height / 2} }
	{}


	void rotateByCenter(int angle);
	void drawOn(SDL_Renderer* renderer);

private:
	Point center;

	Line lines[RECT_LINES];
};
