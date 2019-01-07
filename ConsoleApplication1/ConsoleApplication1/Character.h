#pragma once
#include <string>
#include <SDL.h>
#include "Sprite.h"

class Character : public Sprite
{
public:
	Character(std::string n, int s, int h, SDL_Texture* t);
	int getStrenght();
	int getHealth();
	void tickUpdate();
	void draw(SDL_Renderer* ren, int spriteUpdate);
	SDL_Rect* getRect();
	void damageChar(int dmg);
	~Character();
private:
	SDL_Rect body;
	std::string name;
	int strenght;
	int health;
};

