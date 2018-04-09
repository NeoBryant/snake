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
			If the snake eat the food
				add the length of the snake

			Output the map
			If the snake hit the wall or itself
				Game over
		END WHILE
		Output GAME OVER!
																												
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SNAKE_MAX_LENGTH 20
#define SNAKE_HEAD 'H'
#define SNAKE_BODY 'X'
#define BLANK_CELL ' '
#define SNAKE_FOOD '$'
#define WALL_CELL '*'

//print the letter to contral the move of the snake
void input(int *, int *);
//snake stepping: dy = -1(up)， 1(douwn); dx = -1(left), 1(right), 0 (no move)
void snakeMove(int , int, int *);
//put a food randomized on a black cell
void put_money(void);
//out cells of the grid
void output(void);
//outs when gameover
void gameover(void);char map[12][12]=
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
	printf("Welcome to the world of my snake! \nYou can control the snake by pressing A,S,D,W...\n");
	printf("Please press 'D' to start the game!\n");
	int is_alive = 1;
	int move_x = 0, move_y = 0;
	
	srand(time(NULL));
	
	while (is_alive == 1)
	{
		put_money();											//if there is no money, put one
		input(&move_x, &move_y);
		snakeMove(move_x, move_y, &is_alive);
	}

	return 0;
}
void input(int *dx, int *dy)
{	
	char move;
	*dx = 0;
	*dy = 0;
	printf("Please give me a direction to let the snake move: ");
	move = getchar();
	getchar();
	switch(move)
	{
		case 'A':
			*dx = -1;
			break;
		case 'D':
			*dx = 1;
			break;
		case 'W':
			*dy = -1;
			break;
		case 'S':
			*dy = 1;
			break;	
		}
}
//snake stepping: dy = -1(up)， 1(douwn); dx = -1(left), 1(right), 0 (no move)
void snakeMove(int dx, int dy, int *is_alive)
{
	int count = 0;
	map[snakeY[count]][snakeX[count]] = BLANK_CELL;

	if (map[snakeY[snakeLength-1]+dy][snakeX[snakeLength-1]+dx] == SNAKE_FOOD)		
	{
		snakeLength++;
		snakeY[snakeLength-1] = snakeY[snakeLength-2] + dy;
		snakeX[snakeLength-1] = snakeX[snakeLength-2] + dx;
	}
	else
	{
		for (count = 0; count < snakeLength-1; ++count)								//move the snake
		{
			snakeX[count] = snakeX[count+1];
			snakeY[count] = snakeY[count+1];
		}
		snakeX[snakeLength-1] += dx;
		snakeY[snakeLength-1] += dy;
	}
	if (map[snakeY[snakeLength-1]][snakeX[snakeLength-1]] == WALL_CELL)			//if the snake hit the wall, game over
		*is_alive = 0;
	else 
		for (count = 0; count < snakeLength - 1; ++count)						//if the snake hit itself, game over
			if (snakeX[snakeLength-1] == snakeX[count] 
				&& snakeY[snakeLength-1] == snakeY[count])
			{
				*is_alive = 0;
				break;
			}

	for (count = 0; count < snakeLength-1; ++count)							//put the shape of snake
		map[snakeY[count]][snakeX[count]] = SNAKE_BODY;
	map[snakeY[snakeLength-1]][snakeX[snakeLength-1]] = SNAKE_HEAD;

	put_money();															//if there is no money, put one

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
//put a food randomized on a black cell
void put_money(void)
{
	int mark = 0;
	int col = 0, row = 0;
	for (row = 1; row < 11; ++row)
		for (col = 1; col < 11; ++col)
			if (map[row][col] == SNAKE_FOOD)
				mark = 1;
	if (mark == 0)	
	{	
		int money_x = 1 + rand() % 10;
		int money_y = 1 + rand() % 10;
		map[money_y][money_x] = SNAKE_FOOD;
	}
}


