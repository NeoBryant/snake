#ifndef SNAKE2_H
#define SNAKE2_H

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
void gameover(void);
#endif
