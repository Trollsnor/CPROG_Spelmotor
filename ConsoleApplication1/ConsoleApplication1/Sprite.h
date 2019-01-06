#pragma once
#include <SDL.h>
#include <string>

class Sprite
{
public:
	Sprite(SDL_Renderer* renderer, SDL_Surface* surface);
	SDL_Rect* getFrame(int update);
	void draw();
	SDL_Texture* texture;
	~Sprite();

private:
	SDL_Rect srcR;

};

