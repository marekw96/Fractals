#include <SDL.h>

#include <iostream>

#include "IStage.hpp"

#include "FibonacciTreeFractal.hpp"
#include "SelfSimilarSquares.hpp"
#include "CantorSet.hpp"
#include "MandelbrotSet.hpp"

int main()
{
    const int SCREEN_WIDTH = 1024;
    const int SCREEN_HEIGHT = 1024;

	SDL_Window* window = NULL;
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


    window = SDL_CreateWindow("SaveImageToPng",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN
    );
    if (window == NULL) {
        std::cerr << "Window could not be created! SDL_Error:" << SDL_GetError() << std::endl;
        return 1;
    }

    screen = SDL_GetWindowSurface(window);
    //renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    renderer = SDL_CreateSoftwareRenderer(screen);


	std::vector<IStage*> stages = { &fibStage, &squaresStage, &cantorSet, &mandelbrotSet };

    for(IStage* stage: stages)
    {
        stage->initialize();
		stage->draw(SCREEN_WIDTH, SCREEN_HEIGHT, renderer);
		SDL_RenderPresent(renderer);
        SDL_SaveBMP(screen, "DUPA.bmp");
        stage->cleanup();
    }

    return 0;
}
