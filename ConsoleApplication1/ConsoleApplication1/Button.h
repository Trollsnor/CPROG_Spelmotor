#pragma once
#include <string>
#include <SDL.h>

class Button
{
public:
	Button(std::string txt, int x, int y);
	void onClick();
	SDL_Rect* getRect();
	~Button();
private:
	SDL_Rect* shape;
	std::string txt;
	int x;
	int y;
};

