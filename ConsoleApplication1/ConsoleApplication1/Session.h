#pragma once
#include "System.h"
#include "Character.h"
#include <vector>

class Session
{
public:
	Session(System* sys);
	void run();
	void setBackground(SDL_Texture* texture) {
		backgroundTexture = texture;
	}
	void addSpriteObj(Sprite* obj);
	~Session();
private:
	System* system;
	SDL_Texture* backgroundTexture;
	std::vector<Sprite*> sVector;
};

