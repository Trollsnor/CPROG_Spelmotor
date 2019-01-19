#pragma once
#include "System.h"
#include "Character.h"
#include "Player.h"
//#include "Component.h"
#include "Button.h"

#include <vector>
namespace Engine {
	class Session
	{
	public:
		Session();
		void run(const int fps);
		void handeKeyEvent(SDL_Event event);
		void setBackground(SDL_Texture* texture) {
			backgroundTexture = texture;
		}
		Player* getPlayer();
		void gameOver();
		void detectCollision();
		void addSpriteObj(Sprite* obj);
		void addComponentObj(Component* c);
		std::vector<Sprite*> getVector() {
			return sVector;
		}
		~Session();
	private:
		//System* system;
		SDL_Texture* backgroundTexture;
		std::vector<Sprite*> sVector;
		std::vector<Component*> cVector;
		bool gameOn = true;
	};

}