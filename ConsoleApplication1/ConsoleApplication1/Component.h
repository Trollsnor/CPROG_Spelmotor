#pragma once

#include <string>
#include <SDL.h>

class Component
{
public:
	Component(int x, int y, std::string txt);
	virtual ~Component();
private:
	int x;
	int y;
	int w;
	int h;
	std::string txt;



};

