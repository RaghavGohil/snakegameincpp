#pragma once
// includes
#include <windows.h>
#include <vector>

class Snake 
{
	
private:
	COORD _pos;
	int _len;
	int _vel;
	char _direction;
	std::vector<COORD> _body;

public:
	Snake(COORD pos, int vel);
	void ChangeSnakeDirection(char dir);
	void MoveSnake();
	void Grow();
	COORD GetPos();
	bool eaten(COORD food_position);
	bool collided();
	std::vector<COORD> GetBody();

};