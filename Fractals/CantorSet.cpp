#include "CantorSet.hpp"

#include <vector>

#include "Line.hpp"

void CantorSet::draw(int width, int height, SDL_Renderer * renderer)
{
	std::vector<Line> lines;
	std::vector<Line> newLines;
	int paddingTop = 25;
	int iterations = 13;

	Line l(0, paddingTop, width, paddingTop);
	l.drawOn(renderer);
	lines.push_back(l);

	for (int i = 0; i < iterations; ++i)
	{
		for (const auto& line : lines)
		{
			width = line.getLength() / 3;
			Point start = Point(line.getStart()).moveBy(0, paddingTop);
			Point end = Point(line.getStart()).moveBy(width, paddingTop);
			Line l(start, end);
			newLines.push_back(l);

			l.moveBy(width * 2, 0);
			newLines.push_back(l);
		}

		for (const auto& line : newLines)
		{
			line.drawOn(renderer);
		}

		lines = newLines;
		newLines = {};
	}
}
