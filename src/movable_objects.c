#include "headers.h"
#include <stdarg.h>

char background;


struct Movable * create_movable_object(char obj, struct Window * win, int x,
		int y)
{
	struct Movable * mov = malloc(sizeof(struct Movable));
	mov->p = obj;
	mov->win = win;
	mov->p_x = x;
	mov->p_y = y;
	
	return mov;
}
 
// sorry for the spaghet
void move_object_block(struct Movable * mov_b, struct Window * win,
		char check)
{
	struct Movable * new_mov = mov_b;

	while (mov_b)
	{
		if (!(check_mov_available(mov_b, check)))
			return;
		mov_b = mov_b->next;
	}
	
	while (new_mov)
	{
		move_object(new_mov, check);
		new_mov = new_mov->next;
	}

}

void display_mov_object(struct Movable * mov)
{
	while (mov)
	{

        mov->win->pixel[mov->p_y][mov->p_x].p = mov->p;
		mov = mov->next;
	}
}

int check_mov_available(struct Movable * mov, char move)
{

	if (move == 'h')
	{
		// le spaghet
		if (!(mov->win->pixel[mov->p_y][mov->p_x - 1].immovable))
			return 1;
	}
	
	else if (move == 'l')
	{
		if (!(mov->win->pixel[mov->p_y][mov->p_x + 1].immovable))
			return 1;
	}

	else if (move == 'j')
	{
		if (!(mov->win->pixel[mov->p_y + 1][mov->p_x].immovable))
			return 1;
	}

	else if (move == 'k' || move == ' ')
	{
		if (!(mov->win->pixel[mov->p_y - 1][mov->p_x].immovable))
			return 1;
	} 

	return 0;
}


void move_object(struct Movable * mov, char move)
{
	if (move == 'h')
	{
		mov->p_x = mov->p_x - 1;
	}

	else if (move == 'l')
	{
		mov->p_x = mov->p_x + 1;
	}

	else if (move == 'j')
	{
		mov->p_y = mov->p_y + 1;
	}

	else if (move == 'k' || move == ' ')
	{
		mov->p_y = mov->p_y - 1;
	}
}
