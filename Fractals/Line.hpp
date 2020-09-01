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

	Line(const Point& start, const Point& end)
		: center((start.x + end.x) / 2, (start.y + end.y) / 2),
		  start(start),
		  end(end)
	{}

	void rotateByCenter(int angle);
	void rotateByPoint(const Point& point, int angle);
	void drawOn(SDL_Renderer* renderer);

	const Point& getStart() const;
	const Point& getEnd() const;

private:
	Point center;

	Point start;
	Point end;
};

