#include "pch.h"
#include "Player.h"


Player::Player(std::string name, SDL_Texture* tex) : Sprite(tex, 300, 200)
{
	Player::name = name;

}




Player::~Player()
{
}
