#pragma once
#include <windows.h>
#include <cstdlib>

class Food 
{

private:
	COORD _pos;

public:
	Food(COORD snake_position);
	void GenFood();
	COORD GetPos();

};
