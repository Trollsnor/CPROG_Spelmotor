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
		Button(int x, int y, int w, int h, std::string path);
		void onClick(const SDL_Event& event);
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