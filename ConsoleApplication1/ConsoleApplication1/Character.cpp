#include "pch.h"
#include "Character.h"


Character::Character(std::string n, int x, int y)
{
	name = n;
	body.x = x;
	body.y = y;
	body.w = 15;
	body.h = 25;
}


int Character::getStrenght() {
	return strenght;
}
int Character::getHealth() {
	return health;
}
SDL_Rect* Character::getRect(){
	return &body;
}
void Character::damageChar(int dmg) {
	health -= dmg;
}


Character::~Character()
{
}
