#pragma once

#include "Point.hpp"

class Line
{
public:
	Line(int x_start, int y_start, int x_end, int y_end)
		: center((x_start + x_end) /2, (y_start + y_end) / 2),
		  start(x_start, y_start),
		  end(x_end, y_end)
	{}

	void rotateByCenter(int angle);
	void rotateByPoint(const Point& point, int angle);
	void drawOn(SDL_Renderer* renderer);

private:
	Point center;

	Point start;
	Point end;
};

