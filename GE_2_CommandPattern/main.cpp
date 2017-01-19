#include "SDL.h"
#include <iostream>
#include "InputHandler.h"
#include "MacroCommand.h"

using namespace std;

int main(int argc, char* argv[]) 
{
	bool running = true;
	SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2

	SDL_Window *window;                    // Declare a pointer
	window = SDL_CreateWindow("Command Pattern", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 800, SDL_WINDOW_SHOWN);

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

	InputHandler m_inputHandler;
	MacroCommand m_macroHandler;
	m_inputHandler.buttonBind();
	//m_macroHandler.add(new JumpCommand);
	//m_macroHandler.add(new JumpCommand);

	
	while (running)
	{
		
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_KEYDOWN:
				//m_macroHandler.add(new JumpCommand);
				m_inputHandler.handleInput(event);
				break;
			default:
				break;
			}
		}
		//m_macroHandler.execute();

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