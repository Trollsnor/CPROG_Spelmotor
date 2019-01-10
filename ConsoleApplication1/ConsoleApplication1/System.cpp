#include "pch.h"
#include "System.h"


System::System()
{
	window = SDL_CreateWindow("window",50,50,600,450,0);
	renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_SetRenderDrawColor(renderer, 150,65,230,255);
}


System::~System()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
