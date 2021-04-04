#include "headers.h"

void garbage_fill(struct Window * win, char back) 
{
	for (int i = 0; i < win->y; i++)
	{
		for (int j = 0; j < win->x; j++)
		{
			win->pixel[i][j].perishable = 1;
			win->pixel[i][j].p = back;
		}

	}

}
