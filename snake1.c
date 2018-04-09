/*	PREUDOCODE
	Initialize the map
	Initialize the snake
	Initialize the length of the snake

	WHILE not game over DO
		Input the moving instruction
		
		move = input
		CASE move DO
		'A': turn left, break
		'D': turn right, break
		'W': turn up, break
		'S': turn down, break
		END CASE
		Output the map
		If the snake hit the wall or itself
	END WHILE
		Output GAME OVER!

*/



#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "snake1.h"

char map[12][12]=
	{"************",
	"*XXXXH     *",
	"*          *",
	"*          *",
	"*          *",
	"*          *",
	"*          *",
	"*          *",
	"*          *",
	"*          *",
	"*          *",
	"************"};

//define vars for snake, notice name of vars in C
int snakeX[SNAKE_MAX_LENGTH] = {1, 2, 3, 4, 5};
int snakeY[SNAKE_MAX_LENGTH] = {1, 1, 1, 1, 1};
int snakeLength = 5;

int main()
{
	int is_alive = 1;
	char move;
	int move_x = 0, move_y = 0;
	int mark = 0;
	
	while (is_alive == 1)
	{
		move_x = 0, move_y = 0;
		printf("Please give me a direction to let the snake move: ");
		move = getchar();
		getchar();
		switch(move)
		{
			case 'A':
				move_x = -1;
				break;
			case 'D':
				move_x = 1;
				break;
			case 'W':
				move_y = -1;
				break;
			case 'S':
				move_y = 1;
				break;	
		}
		snakeMove(move_x, move_y, &is_alive);
	}

	return 0;
}
//snake stepping: dy = -1(up)， 1(douwn); dx = -1(left), 1(right), 0 (no move)
void snakeMove(int dx, int dy, int *is_alive)
{
	int count = 0;
	map[snakeY[count]][snakeX[count]] = ' ';

	for (count = 0; count < snakeLength-1; ++count)			//move the snake
	{
		snakeX[count] = snakeX[count+1];
		snakeY[count] = snakeY[count+1];
	}
	snakeX[snakeLength-1] += dx;
	snakeY[snakeLength-1] += dy;

	if (map[snakeY[snakeLength-1]][snakeX[snakeLength-1]] == WALL_CELL)			//if the snake hit the wall, game over
	{
		*is_alive = 0;
	}
	else 																		//if the snake hit itself, game over
		for (count = 0; count < snakeLength - 1; ++count)
			if (snakeX[snakeLength-1] == snakeX[count] 
				&& snakeY[snakeLength-1] == snakeY[count])
			{
				*is_alive = 0;
				break;
			}
	for (count = 0; count < snakeLength-1; ++count)								//put the shape of snake
		map[snakeY[count]][snakeX[count]] = SNAKE_BODY;
	map[snakeY[snakeLength-1]][snakeX[snakeLength-1]] = SNAKE_HEAD;
	if (*is_alive == 1)
		output();
	else 
		gameover();		
}
//out cells of the grid
void output(void)
{
	int col = 0, row = 0;
	for (row = 0; row < 12; ++row)
	{
		for (col = 0; col < 12; ++col)
			putchar(map[row][col]);
		printf("\n");
	}
}
//outs when gameover
void gameover(void)
{
	printf("GAME OVER!\n");
}


