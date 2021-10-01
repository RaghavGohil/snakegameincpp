// includes
#include "snake.h"
//defines
#define TELEPORTABLE 0

extern const int WIDTH;
extern const int HEIGHT;

Snake::Snake(COORD pos , int vel) 
{

	this->_pos = pos;
	this->_vel = vel;
	_len = 1;
	_direction = 'n'; // null direction

	_body.push_back(_pos);

}

void Snake::ChangeSnakeDirection(char dir) { _direction = dir; }

void Snake::MoveSnake()
{

	switch (_direction) 
	{
		
	case 'u':
		_pos.Y -= _vel; break;
	case 'd':
		_pos.Y += _vel; break;
	case 'l':
		_pos.X -= _vel; break;
	case 'r':
		_pos.X += _vel; break;
	}

#if TELEPORTABLE
	if (_pos.X > WIDTH - 2) _pos.X = 0;
	else if (_pos.Y > HEIGHT - 2) _pos.Y = 0;
	else if (_pos.X < 1) _pos.X = WIDTH-2;
	else if (_pos.Y < 1) _pos.Y = HEIGHT-2;
#endif

	_body.push_back(_pos);

	if (_body.size() > _len) _body.erase(_body.begin());

}

std::vector<COORD> Snake::GetBody() { return _body; }

void Snake::Grow() // grow the snake 
{

	_len++;

}

COORD Snake::GetPos() { return _pos; }

bool Snake::eaten(COORD food_position) 
{
	
	if (food_position.X == _pos.X && food_position.Y == _pos.Y) return true;
	else return false;

}

bool Snake::collided() 
{

#if !TELEPORTABLE
	if (_pos.X < 1 || _pos.Y < 1 || _pos.X > WIDTH-2 || _pos.Y > HEIGHT-2) return true;
	else return false;
#endif

	return false;

}