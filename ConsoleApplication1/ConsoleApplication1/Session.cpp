#include "pch.h"
#include "Session.h"

namespace Engine {
	Session::Session()
	{
		//system = sys;
	}

	void Session::addSpriteObj(Sprite* obj) { // change to take Sprite obj as parameter, using dynamic cast when calling function(?)
		sVector.push_back(obj);
	}

	void Session::addComponentObj(Component* c) {
		cVector.push_back(c);
	}

	void Session::run() {

		bool runOn = true;
		while (runOn) {

			Uint32 ticks = SDL_GetTicks();
			int spriteUpdate = (ticks / 100) % 6;
			SDL_Event event;
			while (SDL_PollEvent(&event)) {
				switch (event.type) {
				case SDL_QUIT: runOn = false; break;
				case SDL_KEYDOWN:
					switch (event.key.keysym.sym) {
					case SDLK_UP:
						sVector.at(0)->getBody()->y -= 5;
						break;
					case SDLK_DOWN:
						sVector.at(0)->getBody()->y += 5;
						break;
					case SDLK_RIGHT:
						sVector.at(0)->getBody()->x += 5;
						break;
					case SDLK_LEFT:
						sVector.at(0)->getBody()->x -= 5;
						break;
					case SDLK_n:  break;
					} // inre switch
					break;
				}//switch

				//clear screen and render updated graphics
				SDL_RenderClear(sys.getRenderer());
				SDL_RenderCopy(sys.getRenderer(), backgroundTexture, 0, 0); // background!!!


				//render all oj:s in vector:
				for (Sprite* s : sVector) {
					s->tickUpdate();
					s->draw(spriteUpdate);
				}
				//render all components in vector:
				for (Component* c : cVector)
					c->draw();

				SDL_RenderPresent(sys.getRenderer());
			} // poll event - while
		} // runOn Gameloop

	}

	Session::~Session()
	{
	}
}