#include "FibonacciTreeFractal.hpp"

void FibonacciTreeFractal::draw(int screen_width, int screen_height, SDL_Renderer * renderer)
{
	double size = std::fmin(screen_width, screen_height);
	int start_x = screen_width / 2;
	int start_y = screen_height / 2;
	int rotation_angle = 30;
	int iterations = 10;
	int left_angle = rotation_angle;

	int height = 150;

	std::vector<Point> last_points;
	std::vector<Point> new_last_points;
	std::vector<int> last_rotation;
	std::vector<int> new_last_rotation;

	Line l(start_x, screen_height, start_x, screen_height - height);
	l.drawOn(renderer);
	last_points.push_back(l.getEnd());
	last_rotation.push_back(0);

	for (int i = 0; i < iterations; ++i)
	{
		int id = 0;
		for (Point point : last_points)
		{
			auto cpy = point;
			auto rot_angle = last_rotation[id];
			Line l2(point, cpy.moveBy(0, -height));

			l2.rotateByPoint(l2.getStart(), rot_angle - rotation_angle);
			new_last_points.push_back(l2.getEnd());
			new_last_rotation.push_back(rot_angle - rotation_angle);
			l2.drawOn(renderer);

			l2.rotateByPoint(l2.getStart(), 2 * rotation_angle);
			new_last_rotation.push_back(rot_angle + rotation_angle);
			new_last_points.push_back(l2.getEnd());
			l2.drawOn(renderer);

			++id;
		}
		height *= 0.75;

		last_points = new_last_points;
		last_rotation = new_last_rotation;
		new_last_points = {};
		new_last_rotation = {};
	}
}
