#pragma once
#include "Sprite.h"

class Player :
	public Sprite
{
public:
	Player(std::string name, SDL_Texture* tex);
	~Player();

private:
	std::string name;
	int health; // amount of projectile hits player can take before eliminaion
};

