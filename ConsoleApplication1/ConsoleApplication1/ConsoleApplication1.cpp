#include "pch.h"
#include "System.h"
#include "Character.h"
#include "Session.h"
#include "Button.h"
//#include "Sprite.h"
#include "Player.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>
using namespace std;
using namespace Engine;
//Global stuff (for now)
Character* cArr[5];
//System* sys;
SDL_Surface* surface;
//SDL_Texture* defaultSpriteTexture;

void initEnemies() {
	//create characters for testing: 
	cArr[0] = new Character("halallallaren", 10, 150, "pixel-art-fire-monster.jpg");
	cArr[1] = new Character("Thrall", 200, 150, "pixel-art-fire-monster.jpg");
	cArr[2] = new Character("Shyman", 10, 300, "pixel-art-fire-monster.jpg");
	cArr[3] = new Character("SVT", 350, 150, "pixel-art-fire-monster.jpg");
	cArr[4] = new Character("L�ggdax", 110, 75, "pixel-art-fire-monster.jpg");
}

int main(int argc, char* argv[])
{
	//sys = new System(); // init system (window and renderer)
	//defaultSpriteTexture = SDL_CreateTextureFromSurface(sys.getRenderer(), IMG_Load("adventurer-run3-sword-Sheet.png"));
	initEnemies(); 



	//*******************************************************************************//
	// *********************** CREATE AND ADD TO SESSION   **************************//
	//Session sessan = Session(sys); 
	Session sessan;
	surface = IMG_Load("wall_10.jpg"); 
	sessan.setBackground(SDL_CreateTextureFromSurface(sys.getRenderer(), surface));
	

	for (int i = 0; i < 5; i++) {
		sessan.addSpriteObj(cArr[i]);
	}

	/*
	Button* b = new Button(10, 5, 100, 60, "C:/Users/Gabelstapler/Pictures/gammal bild.jpg");
	sessan.addComponentObj(b);
	*/

	Player* p = new Player("Juckis", "adventurer-run3-sword-Sheet.png");
	sessan.addSpriteObj(p);

	//sessan.run();
	sessan.run(60);
	//******************************  END OF  **************************************//
	//******************************************************************************//

	// End program 
	sys.~System();
	sessan.~Session();
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
