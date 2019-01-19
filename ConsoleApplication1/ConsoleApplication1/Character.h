#pragma once
#include <string>
#include <SDL.h>
#include "Sprite.h"
#include "System.h"

namespace Engine {
	class Character : public Sprite
	{
	public:
		Character(std::string n, int s, int h, std::string p);
		void tickUpdate();
		void flipDirection();
		void draw(int spriteUpdate);
		void die();
		~Character();
	private:
		std::string name;
		int riktning = 2;
		int min;
		int max;
	};
}
