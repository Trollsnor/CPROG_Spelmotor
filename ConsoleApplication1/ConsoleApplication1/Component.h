#pragma once

#include <string>
#include <SDL.h>
//#include "Session.h"
//#include "Character.h"


namespace Engine {
	class Component
	{
	public:
		Component(int x, int y, int w, int h);
		virtual ~Component();
		virtual void draw() {}
		virtual void onClick(const SDL_Event& event) {}
		SDL_Rect* getRect() {
			return &shape;
		}
		//void setWH(int w, int h);

	private:
		/*
		int x;
		int y;
		int w;
		int h;
		*/
		//std::string txt;
		SDL_Rect shape;
	};
	

}
