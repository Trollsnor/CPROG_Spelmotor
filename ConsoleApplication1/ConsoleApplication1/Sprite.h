#pragma once
#include <SDL.h>
#include <string>

class Sprite
{
public:
	Sprite(SDL_Texture* t);
	SDL_Rect* getFrame(int update);
	//void draw(SDL_Rect destRect);
	SDL_Texture* texture;
	~Sprite();

private:
	SDL_Rect srcR; // "frames" part of texture that will be rendered at the moment.
	int width; // tells instance how wide apart each pic lies from each other in texture.
	int height; // tells instance the height for ^ purpose. 
	

};

