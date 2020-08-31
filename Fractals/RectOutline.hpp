#pragma once
#include <SDL.h>
#include "Point.hpp"

class RectOutline {
public:
	RectOutline(int x, int y, int width, int height)
		: center(x,y),
		  left_top(x - width/2, y - height/2),
		  left_bottom(x - width/2, y + height/2),
		  right_bottom(x + width/2, y + height/2),
		  right_top(x + width/2, y - height/2)
	{}


	void rotateByCenter(int angle);
	void drawOn(SDL_Renderer* renderer);

private:
	Point center;

	Point left_top;
	Point left_bottom;
	Point right_bottom;
	Point right_top;

};
