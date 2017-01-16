#include "SDL.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) 
{
	bool running = true;

	SDL_Window *window;                    // Declare a pointer

	SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2

	window = SDL_CreateWindow("An SDL2 window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 800, SDL_WINDOW_SHOWN);

	// Check that the window was successfully created
	if (window == NULL) 
	{
		// In the case that the window could not be made...
		printf("Could not create window: %s\n", SDL_GetError());
		return 1;
	}

	// Setup renderer
	SDL_Renderer* renderer = NULL;
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	cout << "Hello" << endl;

	while (running)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDLK_a:
				cout << '\b';  //Cursor moves 1 position backwards
				cout << " ";
				running = false;
				break;
			default:
				break;
			}
		}
		
		//Clear screen
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		//Update screen
		SDL_RenderPresent(renderer);

	}

	SDL_DestroyWindow(window);
	SDL_Quit();
	
	return 0;
}