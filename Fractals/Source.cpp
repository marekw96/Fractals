#include <SDL.h>
#include <iostream>
#include <vector>

#include "RectOutline.hpp"
#include "IStage.hpp"

#include "FibonacciTreeFractal.hpp"
#include "SelfSimilarSquares.hpp"
#include "CantorSet.hpp"

// Screen (rendering/display surface) dimensions
const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 1024;

int main(int argc, char* args[]) {
	SDL_Window* window = NULL;
	SDL_Surface* screen = NULL;
	SDL_Renderer* renderer = NULL;

	FibonacciTreeFractal fibStage{};
	SelfSimilarSquares squaresStage{};
	CantorSet cantorSet{};

	IStage* stages[] = {&fibStage, &squaresStage, &cantorSet};
	IStage* currentStage = stages[0];

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

			currentStage->initialize();

			SDL_Event event = {};
			while (event.type != SDL_QUIT) {
				SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0xFF);
				SDL_RenderClear(renderer);
				SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

				while (SDL_PollEvent(&event)) {
					if (event.type == SDL_QUIT) {
						SDL_Quit();
						exit(1);
					}
					else if (event.type == SDL_KEYUP)
					{
						switch (event.key.keysym.sym)
						{
						case SDLK_1:
							currentStage->cleanup();
							currentStage = stages[0];
							currentStage->initialize();
							break;
						case SDLK_2:
							currentStage->cleanup();
							currentStage = stages[1];
							currentStage->initialize();
							break;
						case SDLK_3:
							currentStage->cleanup();
							currentStage = stages[2];
							currentStage->initialize();
							break;
						}
					}
				}

				currentStage->draw(SCREEN_WIDTH, SCREEN_HEIGHT, renderer);

				SDL_RenderPresent(renderer);
			}
		}
	}

	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
