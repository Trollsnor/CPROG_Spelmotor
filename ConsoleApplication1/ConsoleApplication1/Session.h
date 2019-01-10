#pragma once
#include "System.h"
#include "Character.h"
#include "Component.h"
#include "Button.h"
#include <vector>
namespace Engine {
	class Session
	{
	public:
		Session();
		void run();
		void setBackground(SDL_Texture* texture) {
			backgroundTexture = texture;
		}
		void addSpriteObj(Sprite* obj);
		void addComponentObj(Component* c);
		~Session();
	private:
		//System* system;
		SDL_Texture* backgroundTexture;
		std::vector<Sprite*> sVector;
		std::vector<Component*> cVector;
	};

}