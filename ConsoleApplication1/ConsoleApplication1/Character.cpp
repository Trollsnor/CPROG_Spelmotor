#include "pch.h"
#include "Character.h"


//Because sprite needs to be root class, all sprite specific objs needs to be sent while creating a character, as it cannot be reached otherwise? Fixes/cleanups (renderer+surf issue) to come later
Character::Character(std::string n, int x, int y, SDL_Texture* t) : Sprite(t)
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

void Character::tickUpdate() {
	//move character (add movement pattern info, collision?) <- later... (OBS: only for non-player controlled Characters)
	
	//more?
}

void Character::draw(SDL_Renderer* ren, int spriteUpdate) {
	SDL_RenderCopy(ren, texture, getFrame(spriteUpdate), &body);
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
