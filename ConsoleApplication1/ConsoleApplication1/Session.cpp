#include "pch.h"
#include "Session.h"
#include <SDL_image.h>

namespace Engine {
	Session::Session()
	{
		
	}

	void Session::addSpriteObj(Sprite* obj) { // change to take Sprite obj as parameter, using dynamic cast when calling function(?)
		sVector.push_back(obj);
	}
	
	void Session::addComponentObj(Component* c) {
		cVector.push_back(c);
	}
	
	void Session::run(const int fps) {

		//SETTING VARIABLES FOR LOOP <3
		const int FPS = fps;                          //Set fps when calling run
		const int frameDelay = 1000 / FPS;            //Decides how long each frame should last in millisec
		Uint32 frameStart;                            //Counts time in millisec to decide frametime
		int frameTime;                                //Tells the actual time it took for the gameloop to go one "lap"
		gameOn = true;

		while (gameOn) {
			frameStart = SDL_GetTicks();
			int spriteUpdate = (frameStart / 100) % 6;     //For our standard sprite 

			//DETECT GAME CHANGES HERE
			SDL_Event event;
			while (SDL_PollEvent(&event)) {
				switch (event.type) {
				case SDL_QUIT: gameOn = false; break;
				case SDL_MOUSEBUTTONDOWN:
					for (Component* c : cVector) {
						c->onClick(event);
					}
					break;
				case SDL_KEYDOWN:
					handeKeyEvent(event);          //handling player key actions
					break;
				}//switch
			}//poll event

			detectCollision();

			//RENDER UPDATES
			SDL_RenderClear(sys.getRenderer());
			SDL_RenderCopy(sys.getRenderer(), backgroundTexture, 0, 0); 
			for (Sprite* s : sVector) {
				s->tickUpdate();
				s->draw(spriteUpdate);
			}
			for (Component* c : cVector) {                       
				c->draw();
			}
			SDL_RenderPresent(sys.getRenderer());

			//CONTROL FRAMERATE
			frameTime = SDL_GetTicks() - frameStart;   // how long a frame has taken, in millisec
			if (frameDelay > frameTime) {              //check if frameDelay is more that the timne frame actually took. In that case; delay.
				SDL_Delay(frameDelay-frameTime);
			}
		}
	}

	void Session::detectCollision() {
		int i = 0;
		for (Sprite* s : sVector) {
			if (s->checkCollision(sVector)) { // returns true if s obj collides w other sprite

				if (dynamic_cast<Character*>(s) != nullptr) {
					Character* c = dynamic_cast<Character*>(s);
					c->flipDirection();
				}
				
				else { // this means c is player
					std::cout << "player collide PLAYER";
					//sVector.erase(sVector.begin() + i);
					gameOver();
					
					return;
				}
				
			}
			i++;
		}
	}

	Player* Session::getPlayer() {
		for (Sprite* c : sVector) {
			if (dynamic_cast<Player*>(c) != nullptr) {
				return dynamic_cast<Player*>(c);
			}
		}
	}
	
	void Session::gameOver() {
		std::cout << "D E A D D D D AFE E GSROGNSOINRGOINS";
		SDL_Surface* surf = IMG_Load("GameOver.png");
		SDL_Texture* tex = SDL_CreateTextureFromSurface(sys.getRenderer(), surf);
		
		SDL_RenderClear(sys.getRenderer());
		SDL_RenderCopy(sys.getRenderer(), tex, 0, 0);
		SDL_RenderPresent(sys.getRenderer());
		SDL_Delay(2000);
		gameOn = false;
	}

	void Session::handeKeyEvent(SDL_Event event) {
		switch (event.key.keysym.sym) {
		case SDLK_UP:
			getPlayer()->move(0, -5);
			break;
		case SDLK_DOWN:
			getPlayer()->move(0, 5);
			break;
		case SDLK_RIGHT:
			getPlayer()->move(5, 0);
			break;
		case SDLK_LEFT:
			getPlayer()->move(-5, 0);
			break;
		case SDLK_n:  break;
		} // keydown switch
	}

	Session::~Session()
	{
		for (Sprite* s : sVector) {
			delete s;
		}

		for (Component*c : cVector) {
			delete c;
		}
	}
}