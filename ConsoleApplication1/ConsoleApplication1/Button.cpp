#include "pch.h"
#include "Button.h"


Button::Button(std::string txt, int x, int y) : Component(x, y, 0, 0), txt(txt)
{
	//Button::txt = txt;
	//init rect according to dimensions.
	//Button::shape = new SDL_Rect();
	//shape->x = x;
	//shape->y = y;
	//shape->w = 200;
	//shape->h = 75;
	surface = IMG_Load("C:/Users/Marie/Pictures/EGY0cYRq9Dp.jpg");
	texture = SDL_CreateTextureFromSurface(sys->getRenderer(), surface);
	SDL_FreeSurface(surface);
}

void Button::onClick() {
	
}

void Button::draw() {
	SDL_RenderCopy(sys->getRenderer(), texture, NULL, getRect());
}
/*
SDL_Rect* Button::getRect() {
	return shape;
}
*/
Button::~Button()
{
}
