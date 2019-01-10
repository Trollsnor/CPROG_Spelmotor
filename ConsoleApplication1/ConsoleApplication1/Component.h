#pragma once

#include <string>
#include <SDL.h>

class Component
{
public:
	Component(int x, int y, int w, int h);
	virtual ~Component();
	virtual void draw() {}
	SDL_Rect* getRect() { 
		return shape; 
	}

private:
	int x;
	int y;
	int w;
	int h;
	//std::string txt;
	SDL_Rect* shape;
};

