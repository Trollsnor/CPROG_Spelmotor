#pragma once
#include "System.h"
#include "Character.h"

class Session
{
public:
	Session(System* sys);
	void run();
	void setBackground(SDL_Texture* texture) {
		backgroundTexture = texture;
	}
	void addCharacter(Character* a, Character* b, Character* c, Character* d, Character* e);
	~Session();
private:
	System* system;
	SDL_Texture* backgroundTexture;
	Character* cArr[5];
};

