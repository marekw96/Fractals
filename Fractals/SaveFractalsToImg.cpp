#include <SDL.h>

#include <iostream>
#include <string>

#include "IStage.hpp"

#include "FibonacciTreeFractal.hpp"
#include "SelfSimilarSquares.hpp"
#include "CantorSet.hpp"
#include "MandelbrotSet.hpp"

int main()
{
    const int SCREEN_WIDTH = 1024;
    const int SCREEN_HEIGHT = 1024;

	SDL_Surface* screen = NULL;
	SDL_Renderer* renderer = NULL;

	FibonacciTreeFractal fibStage{};
	SelfSimilarSquares squaresStage{};
	CantorSet cantorSet{};
	MandelbrotSet mandelbrotSet{};

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cerr << "SDL could not initialize! SDL_Error:" << SDL_GetError() << std::endl;
        return 1;
	}

    screen = SDL_CreateRGBSurface(0, SCREEN_WIDTH, SCREEN_HEIGHT,32, 0xff000000, 0xff0000, 0xff00, 0xff);
    renderer = SDL_CreateSoftwareRenderer(screen);

	std::vector<IStage*> stages = { &fibStage, &squaresStage, &cantorSet, &mandelbrotSet };

    for(IStage* stage: stages)
    {
        std::string name = stage->name();

        std::cout << "Draw: " << name << std::endl;

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0xFF);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

        stage->initialize();
		stage->draw(SCREEN_WIDTH, SCREEN_HEIGHT, renderer);
		SDL_RenderPresent(renderer);
        SDL_SaveBMP(screen, (name + ".BMP").c_str());
        stage->cleanup();
    }

    SDL_FreeSurface(screen);

    return 0;
}
