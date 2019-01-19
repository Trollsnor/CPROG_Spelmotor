#include "pch.h"
#include "Player.h"

namespace Engine {
	Player::Player(std::string name, std::string p) : Sprite(p, 300, 200)
	{
		Player::name = name;

	}

	void Player::move(int xRiktning, int yRiktning) {
		body = { (body.x += xRiktning), (body.y += yRiktning), 50, 50 };
	}

	void Player::draw(int spriteUpdate) {
		SDL_RenderCopy(sys.getRenderer(), getTexture(), getFrame(spriteUpdate), &body);

	}

	Player::~Player()
	{
	}
}