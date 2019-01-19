#include "pch.h"
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "Sprite.h"

namespace Engine {
	Sprite::Sprite(std::string path, int x, int y)
	{
		createTexture(path);

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
		//return srcrect from spritesheet texture 50, 0, 50, 37
		srcR = { update * 50, 10, 45, 35 }; // will later be changed according to width and height, when class holds more than 1 possible texture
		return &srcR;

	}


	void Sprite::createTexture(std::string path) {
		surface = IMG_Load(path.c_str());
		texture = SDL_CreateTextureFromSurface(sys.getRenderer(), surface);
		SDL_FreeSurface(surface);
	}

	SDL_Texture* Sprite::getTexture() {
		return texture;
	}

	
	bool Sprite::checkCollision(std::vector<Sprite*> sVector) {
		for (Sprite* s2 : sVector) {
			if (!(getBody() == s2->getBody())) {      // check that its not collidion with itself.
				bool collision = SDL_HasIntersection(getBody(), s2->getBody());
				if (collision) {
					std::cout << "collision detected" << std::endl;
					return true;
				}
			}
		}
		return false;
	}
	

	Sprite::~Sprite()
	{
		SDL_DestroyTexture(texture);
	}
}