#include "food.h"

extern const int WIDTH;
extern const int HEIGHT;

Food::Food(COORD snake_position) 
{

	_pos.X = snake_position.X + 5;
	_pos.Y = int(HEIGHT/ 2);

}

void Food::GenFood() 
{

	//rand() % u-l/1+l
	_pos.X = (rand() % WIDTH - 3) + 1;
	_pos.Y = (rand() % HEIGHT - 3) + 1;

}

COORD Food::GetPos() { return _pos; }