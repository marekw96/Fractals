#include <SDL.h>
#include <stdio.h>

#include "RectangleOutline.hpp"

// Screen (rendering/display surface) dimensions
const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 1024;

int main(int argc, char* args[]) {
	SDL_Window* window = NULL;
	SDL_Surface* screen = NULL;
	SDL_Renderer* renderer = NULL;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else {
		window = SDL_CreateWindow("Markowy Fraktal",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN
		);
		if (window == NULL) {
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
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

			for (int i = 1; i <= 15; ++i)
			{
				RectOutline rect(start_x, start_y, static_cast<int>(size), static_cast<int>(size));
				if (i % 2 == 0)
					rect.rotateByCenter(45);
				rect.drawOn(renderer);
				
				size = std::sqrt(2 * (0.5 * size) *(0.5 * size));
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
