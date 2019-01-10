#include "pch.h"
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "Sprite.h"

namespace Engine {
	Sprite::Sprite(SDL_Texture* t, int x, int y)
	{
		texture = t;

		body.x = x;
		body.y = y;
		body.w = 50;
		body.h = 50;
		std::cout << "sprite created";
	}

	SDL_Rect* Sprite::getBody() {
		return &body;
	}

	SDL_Rect* Sprite::getFrame(int update)
	{
		//return srcrect from spritesheet texture
		srcR = { update * 50, 0, 50, 37 }; // will later be changed according to width and height, when class holds more than 1 possible texture
		return &srcR;

	}

	void Sprite::draw(int spriteUpdate) {
		SDL_RenderCopy(sys.getRenderer(), texture, getFrame(spriteUpdate), &body);
	}

	Sprite::~Sprite()
	{
		SDL_DestroyTexture(texture);
	}
}