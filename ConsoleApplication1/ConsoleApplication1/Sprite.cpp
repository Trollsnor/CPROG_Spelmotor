#include "pch.h"
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "Sprite.h"


Sprite::Sprite(SDL_Texture* t)
{
	texture = t;
	std::cout << "sprite created";
}

SDL_Rect* Sprite::getFrame(int update)
{
	//return srcrect from spritesheet texture
	srcR = { update * 50, 0, 50, 37 }; // will later be changed according to width and height, when class holds more than 1 possible texture
	return &srcR;
	
}
/*
void Sprite::draw(SDL_Rect destRect)
{
	//SDL_RenderCopy(sys->getRenderer(), spek->texture, spek->getFrame(spriteU), cArr[0]->getRect());
	SDL_RenderCopy(renderer, texture, getFrame(), destRect);
} */

Sprite::~Sprite()
{
	SDL_DestroyTexture(texture);
}
