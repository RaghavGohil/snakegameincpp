// includes
#include <iostream>
#include <ctime>
#include <conio.h>
#include "snake.h"
#include "food.h"

//fields
extern const int WIDTH = 50, HEIGHT = 25;

bool GAMEOVER = true;

int score = 0;

Snake snake({ WIDTH / 2 , HEIGHT / 2 }, 1);
Food food(snake.GetPos());


void board() 
{
	
	std::vector<COORD> snake_body = snake.GetBody();

	for (int i = 0; i < HEIGHT; i++) 
	{

		std::cout << '#';
	
		for (int j = 0; j < WIDTH-2; j++) // -2 because of start and end
		{

			if (i == 0 || i == HEIGHT - 1) std::cout << '#';
			else if (i == snake.GetPos().Y && j+1 == snake.GetPos().X) std::cout << '0';
			else if (i == food.GetPos().Y && j+1 == food.GetPos().X) std::cout << '@';
			else 
			{
			
				bool is_body_part = false;

				for (int k = 0; k < snake_body.size()-1; k++) 
				{
				
					if (i == snake_body[k].Y && j + 1 == snake_body[k].X) 
					{
						
						std::cout << 'o';
						is_body_part = true;
						break;

					}

				
				}
			
				if(!is_body_part) std::cout << ' ';
			}
		}

		std::cout << '#' << std::endl;
	
	}

}

int main() 
{

	score = 0;

	srand(time(NULL));// control to random number generator.

	while (GAMEOVER)
	{
		
		std::cout << "Your score is: " << score << "\n\n";

		board();

		if (_kbhit()) 
		{
		
			switch (_getch()) 
			{
			
			case 'w':
				snake.ChangeSnakeDirection('u'); break;
			case 'a':
				snake.ChangeSnakeDirection('l'); break;
			case 's':
				snake.ChangeSnakeDirection('d'); break;
			case 'd':
				snake.ChangeSnakeDirection('r'); break;
			}
		
		}

		if (snake.eaten(food.GetPos())) 
		{
			
			food.GenFood();
			snake.Grow();
			score += 10;
		
		}

		if (snake.collided()) 
		{
			
			std::cout << "Ended Game Cuz You Ran Into Walls.";
			GAMEOVER = false;
			
		}

		snake.MoveSnake();

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0,0});
	
	}

	return 0;

}