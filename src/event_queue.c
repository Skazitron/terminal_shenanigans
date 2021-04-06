#include "headers.h"
#include <stdarg.h>

struct Animation * cycle_state(int s_x, int s_y, 
        struct Window * win, int numargs, ...)
{
	va_list var_list;

	va_start(var_list, numargs);


	struct Animation * mov = NULL;
	struct Animation * head;

	for (int i = 0; i < numargs; i++)
	{
		FILE * f = fopen(va_arg(var_list, char *), "r");

		if (f == NULL)
		{
            error_hander("animation file doesn't exist");
		}
		
		if (mov == NULL)
        {

			struct Movable * this = block_from_smp(f, s_x, s_y, win);
            mov = malloc(sizeof(struct Animation));
            mov->curr_anim = this; 
            head = mov;
        }
        else 
        {
            struct Animation * anim = malloc(sizeof(struct Animation));
            struct Movable * curr = block_from_smp(f, s_x, s_y, win);
            anim->curr_anim = curr;
            
            mov->next_state = anim;
            mov = mov->next_state;
        }

	}

    mov->next_state = head;
        
    return head;
}


void move_animation_chain(char a, int num_nodes, struct Animation * animation)
{
    for (int i = 0; i < num_nodes; i++)
    {
        move_object_block(animation->curr_anim, animation->curr_anim->win,
                a);
        animation = animation->next_state;
    }
}
