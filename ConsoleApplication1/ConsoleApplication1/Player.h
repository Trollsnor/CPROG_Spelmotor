#pragma once
#include "Sprite.h"

namespace Engine {
	class Player :
		public Sprite
	{
	public:
		Player(std::string name, SDL_Texture* tex);
		void move(int xRiktning, int yRiktning);
		~Player();

	private:
		std::string name;
		int health; // amount of projectile hits player can take before eliminaion
	};

}