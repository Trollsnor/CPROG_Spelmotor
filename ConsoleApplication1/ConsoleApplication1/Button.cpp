#include "pch.h"
#include "Button.h"


Button::Button(std::string txt, int x, int y)
{
	Button::txt = txt;
	Button::x = x;
	Button::y = y;
	//init rect according to dimensions.
	Button::shape = new SDL_Rect();
	shape->x = x;
	shape->y = y;
	shape->w = 200;
	shape->h = 75;
}

void Button::onClick() {
	
}

SDL_Rect* Button::getRect() {
	return shape;
}

Button::~Button()
{
}
