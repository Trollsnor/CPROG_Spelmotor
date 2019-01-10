#include "pch.h"
#include "Character.h"


Character::Character(std::string n, int x, int y, SDL_Texture* t) : Sprite(t, x, y)
{
	name = n;
	min = x - 100;
	max = x + 150;

}

void Character::tickUpdate() {
	//move character (add movement pattern info, collision?)
	
	if (body.x < min) {
		riktning = 2;
	}
	 if (body.x > max) {
		riktning = -2;
	}
	body.x += riktning;
}

Character::~Character()
{
}
