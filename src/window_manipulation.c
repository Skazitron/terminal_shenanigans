#include "headers.h"

void background_fill(struct Window * win, char back) 
{
	for (int i = 0; i < win->y; i++)
	{
		for (int j = 0; j < win->x; j++)
		{
			win->pixel[i][j].perishable = 1;
			win->pixel[i][j].immovable = 0;
			win->pixel[i][j].p = back;
		}

	}

}

struct Window * createWindow(int x, int y)
{
    struct Window * win = (struct Window *) malloc(sizeof(struct Window));
    win->x = x;
    win->y = y;


    // creates the y plane for the window
    win->pixel = (struct Pixel **) malloc(y * sizeof(struct Pixel *));
    
    // creates the x plane for the window
    for (int i = 0; i < y; i++)
    {
        win->pixel[i] = (struct Pixel *) malloc(x * sizeof(struct Pixel));
    }

    return win;

}

void print_window(struct Window * new_win) 
{
	for (int i = 0; i < new_win->y; i++)
	{

		for (int j = 0; j < new_win->x; j++)
		{
			printw("%c", new_win->pixel[i][j].p);
		}

		printw("\n");
	}
}


void create_immovable_block(int s_x, int e_x, int s_y, int e_y,
        struct Window * win, char P) 
{
	for (int i = s_y; i < e_y; i++)
	{
		for (int j = s_x; j < e_x; j++)
		{
			
			win->pixel[i][j].p = P;
			win->pixel[i][j].immovable = 1;
		}
	}
}
