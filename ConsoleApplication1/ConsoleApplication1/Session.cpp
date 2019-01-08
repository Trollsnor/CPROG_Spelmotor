#include "pch.h"
#include "Session.h"


Session::Session(System* sys)
{
	system = sys;
}

void Session::addCharacter(Character* a, Character* b, Character* c, Character* d, Character* e) {
	cArr[0] = a;
	cArr[1] = b;
	cArr[2] = c;
	cArr[3] = d;
	cArr[4] = e;
}

void Session::run() {
	
	bool runOn = true;
	SDL_Event event;
	while (runOn) {

		Uint32 ticks = SDL_GetTicks();
		int spriteUpdate = (ticks / 100) % 6;

		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT: runOn = false; break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym) {
				case SDLK_UP:
					cArr[0]->getRect()->y -= 5;
					break;
				case SDLK_DOWN:
					cArr[0]->getRect()->y += 5;
					break;
				case SDLK_RIGHT:
					cArr[0]->getRect()->x += 5;
					break;
				case SDLK_LEFT:
					cArr[0]->getRect()->x -= 5;
					break;
				case SDLK_n:  break;
				} // inre switch
				break;
			}//switch

			//clear screen and render updated graphics
			SDL_RenderClear(system->getRenderer());
			SDL_RenderCopy(system->getRenderer(), backgroundTexture, 0, 0); // background!!!

			//render all characters sprites. Later also call movement and (possible)behaviour tickUpdate 
			for (Character* c : cArr) {
				c->draw(system->getRenderer(), spriteUpdate);
			}

			SDL_RenderPresent(system->getRenderer());
		} // poll event - while
	} // runOn Gameloop

}

Session::~Session()
{
}
