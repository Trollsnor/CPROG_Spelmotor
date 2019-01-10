#pragma once
#include <SDL.h>
#include <string>

class Sprite
{
public:
	Sprite(SDL_Texture* t, int x, int y);
	SDL_Rect* getFrame(int update);
	SDL_Rect* getBody();
	void draw(SDL_Renderer* ren, int spriteUpdate);
	virtual void tickUpdate() {} // just for character obj:S
	Sprite(const Sprite&) = delete;
	const Sprite& operator=(const Sprite&) = delete;
	virtual ~Sprite();

protected:
	SDL_Rect body;

private:
	SDL_Rect srcR = {50, 0, 50, 37 }; // "frames" part of texture that will be rendered at the moment.
	int width; // tells instance how wide apart each pic lies from each other in texture.
	int height; // tells instance the height for ^ purpose. 
	SDL_Texture* texture;


};

