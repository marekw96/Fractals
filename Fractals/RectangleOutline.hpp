#pragma once
#include <SDL.h>

#include <cmath>

# define M_PI           3.14159265358979323846

class RectOutline {
public:
	RectOutline(int x, int y, int width, int height)
		: center_x(x), center_y(y),
		  left_top_x(x - width/2), left_top_y(y - height/2),
		  left_bottom_x(x - width/2), left_bottom_y(y + height/2),
		  right_top_x(x + width/2), right_top_y(y - height/2),
		  right_bottom_x(x + width/2), right_bottom_y(y + height/2)
	{}


	void rotateByCenter(float angle)
	{
		//https://gamefromscratch.com/gamedev-math-recipes-rotating-one-point-around-another-point/
		angle = angle * (M_PI / 180); // to radians
		
		auto rotatedX = std::cos(angle) * (left_top_x - center_x) - std::sin(angle) * (left_top_y - center_y) + center_x;
		auto rotatedY = std::sin(angle) * (left_top_x - center_x) + std::cos(angle) * (left_top_y - center_y) + center_y;

		left_top_x = rotatedX;
		left_top_y = rotatedY;

		rotatedX = std::cos(angle) * (left_bottom_x - center_x) - std::sin(angle) * (left_bottom_y - center_y) + center_x;
		rotatedY = std::sin(angle) * (left_bottom_x - center_x) + std::cos(angle) * (left_bottom_y - center_y) + center_y;

		left_bottom_x = rotatedX;
		left_bottom_y = rotatedY;

		rotatedX = std::cos(angle) * (right_top_x - center_x) - std::sin(angle) * (right_top_y - center_y) + center_x;
		rotatedY = std::sin(angle) * (right_top_x - center_x) + std::cos(angle) * (right_top_y - center_y) + center_y;

		right_top_x = rotatedX;
		right_top_y = rotatedY;

		rotatedX = std::cos(angle) * (right_bottom_x - center_x) - std::sin(angle) * (right_bottom_y - center_y) + center_x;
		rotatedY = std::sin(angle) * (right_bottom_x - center_x) + std::cos(angle) * (right_bottom_y - center_y) + center_y;

		right_bottom_x = rotatedX;
		right_bottom_y = rotatedY;
	}

	void drawOn(SDL_Renderer* renderer)
	{
		constexpr auto POINTS = 5;

		SDL_Point points[POINTS] = {
			{left_top_x, left_top_y},
			{left_bottom_x, left_bottom_y},
			{right_bottom_x, right_bottom_y},
			{right_top_x, right_top_y},
			{left_top_x, left_top_y}
		};

		SDL_RenderDrawLines(renderer, points, POINTS);
	}

private:
	int center_x;
	int center_y;

	int left_top_x;
	int left_top_y;

	int left_bottom_x;
	int left_bottom_y;

	int right_top_x;
	int right_top_y;

	int right_bottom_x;
	int right_bottom_y;

};
