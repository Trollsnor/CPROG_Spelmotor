#pragma once
#include <string>
#include <SDL.h>
#include "Sprite.h"
#include "System.h"

namespace Engine {
	class Character : public Sprite
	{
	public:
		Character(std::string n, int s, int h, SDL_Texture* t);
		void tickUpdate();
		void flipDirection();
		~Character();
	private:
		std::string name;
		int riktning = 2;
		int min;
		int max;
	};
}
