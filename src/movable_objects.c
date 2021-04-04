#include "headers.h"

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
	
}

void move_object(struct Movable * mov)
{

}
