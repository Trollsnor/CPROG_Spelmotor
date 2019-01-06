// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "System.h"
#include "Character.h"
#include "Session.h"
#include "Button.h"
#include "Sprite.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>
using namespace std;

Character* cArr[5]{NULL, NULL, NULL, NULL, NULL};

Character* createCharacter() {
	cout << "what is your name? ";
	string name;
	cin >> name;
	Character* player = new Character(name, 10, 20);
	cout << "Successfully created Player" << endl;
	return player;
}

void initEnemies() {
	//create enemies:
	Character* c1 = new Character("Thrall", 200, 50);
	Character* c2 = new Character("Shyman", 10, 300);
	Character* c3 = new Character("SVT", 350, 150);
	Character* c4 = new Character("Läggdax", 150, 75);

	//add pointers of them to array:
	cArr[1] = c1;
	cArr[2] = c2;
	cArr[3] = c3;
	cArr[4] = c4;
}

int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_EVERYTHING);
	System* sys = new System(); // init system (window and renderer)
	SDL_Surface* surface = SDL_LoadBMP("C:/Users/laron/Desktop/bild.bmp");
	SDL_Texture* texture = SDL_CreateTextureFromSurface(sys->getRenderer(), surface);
	SDL_FreeSurface(surface);

	//start game stuffs
    cout << "Hello World!\n" << "Create your character here:" << endl; 
	cArr[0] = createCharacter();
	initEnemies(); // adds new characters to array
	//Later, add gameloop and render handling to session: Session::run() Using:
	//Session* s = new Session();

	//create sprite test
	// init spritesheet
	SDL_Surface* sprite = IMG_Load("C:/Users/Gabelstapler/Documents/adventurer-run3-sword-Sheet.png");
	SDL_Texture* spriteTex = SDL_CreateTextureFromSurface(sys->getRenderer(), sprite);
	Sprite* spek = new Sprite(sys->getRenderer(), sprite);

	bool runOn = true;
	while (runOn) {


		Uint32 ticks = SDL_GetTicks();

		int spriteU = (ticks / 100) % 6;

		SDL_Rect srcrect = { spriteU * 50, 0, 50, 37 };

		SDL_Event event;
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
			SDL_RenderClear(sys->getRenderer());
			SDL_RenderCopy(sys->getRenderer(), texture, 0, 0);
			for (Character* c : cArr) {
				SDL_SetRenderDrawColor(sys->getRenderer(), 100,100,100,255);
				SDL_RenderFillRect(sys->getRenderer(), c->getRect());
			}

			SDL_RenderCopy(sys->getRenderer(), spek->texture, spek->getFrame(spriteU), cArr[0]->getRect());

			SDL_RenderPresent(sys->getRenderer());

			
		}


	} // runOn Gameloop
	
	//s->run(*cArr); // sends array to gameloop
	sys->~System();
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
