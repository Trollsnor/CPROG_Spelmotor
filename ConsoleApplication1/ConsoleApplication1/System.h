#pragma once
#include <SDL.h>
#include <iostream>

namespace Engine {
	class System
	{
	public:
		System();
		SDL_Window* getWindow() {
			return window;
		}
		SDL_Renderer* getRenderer() {
			return renderer;
		}
		~System();
	private:
		SDL_Window* window;
		SDL_Renderer* renderer;
		SDL_Surface* surface;

	};
	extern System sys;

}
