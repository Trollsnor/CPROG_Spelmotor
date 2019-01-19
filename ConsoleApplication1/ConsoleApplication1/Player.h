#pragma once
#include "Sprite.h"

namespace Engine {
	class Player :
		public Sprite
	{
	public:
		Player(std::string name, std::string p);
		void draw(int spriteUpdate);
		void move(int xRiktning, int yRiktning);
		~Player();

	private:
		std::string name;
		int health; // amount of projectile hits player can take before eliminaion
	};

}