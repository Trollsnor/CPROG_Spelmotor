#pragma once
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include "Component.h"
#include "System.h"


class Button : Component
{
public:
	Button(std::string txt, int x, int y);
	void onClick();
	//SDL_Rect* getRect();
	~Button();
	void draw();
private:
	SDL_Surface* surface;
	SDL_Texture* texture;
	//SDL_Rect* shape;
	std::string txt;
	int x;
	int y;
	System* sys;
};

