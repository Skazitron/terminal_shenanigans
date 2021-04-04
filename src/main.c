#include "headers.h"
#include <unistd.h> 
#include <stdlib.h>

char background;

int main()
{

	background = '_';

    int x,y;

    x = 100;
    y = 30;

	// create a new window

    struct Window * newWin = createWindow(x,y);
	
	// create a new movable object 
	struct Movable * mov = create_movable_object('A', newWin);
	

	initscr();			/* Start curses mode 		  */
	
	background_fill(newWin, background);
	create_immovable_block(0, 100, 20, 30, newWin, 'O');
	create_immovable_block(80, 90, 0, 10, newWin, 'O');
	print_window(newWin);
	
	refresh();			/* Print it on to the real screen */
	char a;
	while ((a = getch()) != 'q')
	{
		
		background_fill(newWin, background);
		create_immovable_block(80, 90, 0, 10, newWin, 'O');
		create_immovable_block(0, 100, 20, 30, newWin, 'O');
		clear();
		move_object(mov, a);
		display_mov_object(mov);
		print_window(newWin);
		refresh();
	}
	endwin();			/* End curses mode		  */

	return 0;


}
