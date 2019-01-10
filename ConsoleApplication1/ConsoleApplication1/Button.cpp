#include "pch.h"
#include "Button.h"


namespace Engine {
	Button::Button(int x, int y, std::string path) : Component(x, y, 0, 0)
	{
		//Button::txt = txt;
		//init rect according to dimensions.
		//Button::shape = new SDL_Rect();
		//shape->x = x;
		//shape->y = y;
		//shape->w = 200;
		//shape->h = 75;
		//createTexture(ren);
		createTexture(path);
	}

	void Button::onClick() {
		//SDL_Point p;
		
	}

	void Button::createTexture(std::string path) {
		if (texture != NULL)
			SDL_DestroyTexture(texture);
		std::cout << "Creating surface...";
		surface = IMG_Load(path.c_str());
		std::cout << "Creating texture...";
		texture = SDL_CreateTextureFromSurface(sys.getRenderer(), surface);
		setWH(50, 30);
		std::cout << "Button created";
	}

	void Button::draw() {

		SDL_RenderCopy(sys.getRenderer(), texture, NULL, &getRect());
	}
	/*
	SDL_Rect* Button::getRect() {
		return shape;
	}
	*/
	Button::~Button()
	{
		SDL_FreeSurface(surface);
		SDL_DestroyTexture(texture);
	}
}
