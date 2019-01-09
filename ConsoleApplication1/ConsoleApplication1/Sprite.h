#pragma once
#include <SDL.h>
#include <string>

class Sprite
{
public:
	Sprite(SDL_Texture* t);
	SDL_Rect* getFrame(int update);
	virtual void draw(SDL_Rect destRect) {}
	SDL_Texture* texture;
	virtual ~Sprite();
	Sprite(const Sprite&) = delete;
	const Sprite& operator=(const Sprite&) = delete;
private:
	SDL_Rect srcR = {50, 0, 50, 37 }; // "frames" part of texture that will be rendered at the moment.
	int width; // tells instance how wide apart each pic lies from each other in texture.
	int height; // tells instance the height for ^ purpose. 
	

};

