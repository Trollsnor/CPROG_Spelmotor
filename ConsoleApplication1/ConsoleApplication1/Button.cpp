#include "pch.h"
#include "Button.h"


namespace Engine {
	Button::Button(int x, int y, int w, int h, std::string path) : Component(x, y, w, h)
	{
		createTexture(path);
	}

	void Button::onClick(const SDL_Event& event) {
		SDL_Point p = { event.button.x, event.button.y };
		if (SDL_PointInRect(&p, getRect()))
			std::cout << "Clicked";
	}

	void Button::createTexture(std::string path) {
		if (texture != NULL)
			SDL_DestroyTexture(texture);
		std::cout << "Creating surface...";
		surface = IMG_Load(path.c_str());
		std::cout << "Creating texture...";
		texture = SDL_CreateTextureFromSurface(sys.getRenderer(), surface);
		//setWH(50, 30);
		std::cout << "Button created";
	}

	void Button::draw() {

		SDL_RenderCopy(sys.getRenderer(), texture, NULL, getRect());
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
