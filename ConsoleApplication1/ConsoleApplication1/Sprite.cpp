#include "pch.h"
#include "Sprite.h"


Sprite::Sprite(SDL_Renderer* renderer, SDL_Surface* surface)
{
	texture = SDL_CreateTextureFromSurface(renderer, surface);

}

SDL_Rect* Sprite::getFrame(int update)
{
	//return srcrect from spritesheet texture
	srcR = { update * 50, 0, 50, 37 };
	return &srcR;
	
}
void Sprite::draw()
{
	
}

Sprite::~Sprite()
{
	SDL_DestroyTexture(texture);
}
