#include "headers.h"
#include <unistd.h> 
#include <stdlib.h>

char background;

int main()
{

	background = ' ';

    int x,y;

    x = 100;
    y = 40;

	// resizing the terminal
	
	char buffer[20];

	// create a new window

    struct Window * newWin = createWindow(x,y);
	
	// create a new movable object 
	FILE * pmp_file = fopen("./assets/example.pmp", "r");
	struct Movable * mov = block_from_pmp(pmp_file, 10, 10, newWin);

	initscr();			/* Start curses mode 		  */
	
	background_fill(newWin, background);
	create_immovable_block(80, 90, 0, 10, newWin, 'X');
	create_immovable_block(0, 80, 20, 30, newWin, 'X');
	border_builder(newWin, '+');
	print_window(newWin);
	
	refresh();			/* Print it on to the real screen */
	char a;
	while ((a = getch()) != 'q')
	{
		
		background_fill(newWin, background);
		create_immovable_block(80, 90, 0, 10, newWin, 'X');
		create_immovable_block(0, 80, 20, 30, newWin, 'X');
		clear();
		move_object_block(mov, newWin, a);
		display_mov_object(mov);
		border_builder(newWin, '+');
		print_window(newWin);
		refresh();
	}
	endwin();			/* End curses mode		  */

	return 0;


}

