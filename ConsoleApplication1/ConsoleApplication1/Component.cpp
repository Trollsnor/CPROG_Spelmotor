#include "pch.h"
#include "Component.h"


namespace Engine {
	Component::Component(int x, int y, int w, int h) : shape{ x, y, w, h }
	{

	}

	Component::~Component()
	{
	}
	/*
	void Component::setWH(int w, int h) {
		shape.w = w;
		shape.h = h;
	}
	*/
}
