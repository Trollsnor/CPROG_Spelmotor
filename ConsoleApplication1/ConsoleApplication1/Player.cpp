#include "pch.h"
#include "Player.h"

namespace Engine {
	Player::Player(std::string name, SDL_Texture* tex) : Sprite(tex, 300, 200)
	{
		Player::name = name;

	}

	void Player::move(int xRiktning, int yRiktning) {
		body = { (body.x += xRiktning), (body.y += yRiktning), 50, 50 };
	}



	Player::~Player()
	{
	}
}