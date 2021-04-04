#include "headers.h"

char background;

struct Movable * create_movable_object(char obj, struct Window * win)
{
	struct Movable * mov = malloc(sizeof(struct Movable));
	mov->p = obj;
	mov->win = win;
	mov->p_x = win->x / 2;
	mov->p_y = win->y / 2;
	
	return mov;
}

void display_mov_object(struct Movable * mov)
{
	
	mov->win->pixel[mov->p_y][mov->p_x].p = mov->p;
}


void move_object(struct Movable * mov, char move)
{
	if (move == 'h')
	{
		// le spaghet
		if (!(mov->win->pixel[mov->p_y][mov->p_x - 1].immovable))
			mov->p_x = mov->p_x - 1;
	}
	
	else if (move == 'l')
	{
		if (!(mov->win->pixel[mov->p_y][mov->p_x + 1].immovable))
			mov->p_x = mov->p_x + 1;
	}

	else if (move == 'j')
	{
		if (!(mov->win->pixel[mov->p_y + 1][mov->p_x].immovable))
			mov->p_y = mov->p_y + 1;
	}

	else if (move == 'k' || move == ' ')
	{
		if (!(mov->win->pixel[mov->p_y - 1][mov->p_x].immovable))
			mov->p_y = mov->p_y - 1;
	}
}
