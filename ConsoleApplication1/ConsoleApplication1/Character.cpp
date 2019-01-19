#include "pch.h"
#include "Character.h"

namespace Engine {
	Character::Character(std::string n, int x, int y, SDL_Texture* t) : Sprite(t, x, y)
	{
		name = n;
		min = 0;
		max = 550;

	}
	void Character::flipDirection() {
		if (riktning == 2) {
			riktning = -2;
			std::cout << "flipped to left";
		}

		else if (riktning == -2) {
			riktning = 2;
			std::cout << "flipped to right";
		}
		std::cout << "flipped";
	}

	void Character::tickUpdate() {
		//move character (add movement pattern info, collision?)

		if (body.x < min) {
			flipDirection();
		}
		if (body.x > max) {
			flipDirection();
			
		}
		body.x += riktning;
		/*
		//now, after moving rect, but before drawing: check if collision
		checkCollision();
		*/

	}

	Character::~Character()
	{
	}
}