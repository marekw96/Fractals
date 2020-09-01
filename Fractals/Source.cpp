#include <SDL.h>
#include <iostream>
#include <vector>

#include "RectOutline.hpp"

// Screen (rendering/display surface) dimensions
const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 1024;

int main(int argc, char* args[]) {
	SDL_Window* window = NULL;
	SDL_Surface* screen = NULL;
	SDL_Renderer* renderer = NULL;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cerr << "SDL could not initialize! SDL_Error:" << SDL_GetError() << std::endl;
	}
	else {
		window = SDL_CreateWindow("Markowy Fraktal",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN
		);
		if (window == NULL) {
			std::cerr << "Window could not be created! SDL_Error:" << SDL_GetError() << std::endl;
		}
		else {
			screen = SDL_GetWindowSurface(window);
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0xFF);
			SDL_RenderClear(renderer);
			SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

			double size = std::fmin(SCREEN_WIDTH, SCREEN_HEIGHT);
			int start_x = SCREEN_WIDTH /2;
			int start_y = SCREEN_HEIGHT /2;
			int rotation_angle = 30;
			int iterations = 10;
			int left_angle = rotation_angle;

			int height = 150;

			std::vector<Point> last_points;
			std::vector<Point> new_last_points;
			std::vector<int> last_rotation;
			std::vector<int> new_last_rotation;

			Line l(start_x, SCREEN_HEIGHT, start_x, SCREEN_HEIGHT - height);
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
			
			SDL_RenderPresent(renderer);

			SDL_Event event = {};
			while (event.type != SDL_QUIT) {
				while (SDL_PollEvent(&event)) {
					if (event.type == SDL_QUIT) {
						SDL_Quit();
						exit(1);
					}
				}
			}
		}
	}

	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
