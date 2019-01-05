#pragma once
#include <string>
#include <SDL.h>

class Character
{
public:
	Character(std::string n, int s, int h);
	int getStrenght();
	int getHealth();
	SDL_Rect* getRect();
	void damageChar(int dmg);
	~Character();
private:
	SDL_Rect body;
	std::string name;
	int strenght;
	int health;
};

