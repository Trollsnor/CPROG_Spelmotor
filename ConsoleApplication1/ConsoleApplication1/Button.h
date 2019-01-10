#pragma once
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include "Component.h"
#include "System.h"


namespace Engine {
	class Button : public Component
	{
	public:
		Button(int x, int y, std::string path);
		void onClick();
		//SDL_Rect* getRect();
		~Button();
		void draw();
		void createTexture(std::string path);
	private:
		SDL_Surface* surface;
		SDL_Texture* texture = NULL;
		//SDL_Rect* shape;
		std::string txt;
		int x;
		int y;
		//System* sys;
	};

}