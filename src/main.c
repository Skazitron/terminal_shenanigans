#include "headers.h"
#include <unistd.h> 
#include <stdlib.h>

char background;

int main()
{

	background = '_';

    int x,y;

    x = 100;
    y = 50;

	// resizing the terminal
	
	char buffer[20];

	// create a new window

    struct Window * newWin = createWindow(x,y);
	
	// create a new movable object 
	struct Movable * mov = create_movable_object('A', newWin, 50, 15);
	struct Movable * mov2 = create_movable_object('A', newWin, 51, 15);
	struct Movable * mov3 = create_movable_object('A', newWin, 49, 15);
	mov->next = mov2;
	mov2->next = mov3;

	initscr();			/* Start curses mode 		  */
	
	background_fill(newWin, background);
	create_immovable_block(0, 100, 20, 30, newWin, 'X');
	create_immovable_block(80, 90, 0, 10, newWin, 'X');
	print_window(newWin);
	
	refresh();			/* Print it on to the real screen */
	char a;
	while ((a = getch()) != 'q')
	{
		
		background_fill(newWin, background);
		create_immovable_block(80, 90, 0, 10, newWin, 'X');
		create_immovable_block(0, 100, 20, 30, newWin, 'X');
		clear();
		move_object_block(mov, newWin, a);
		display_mov_object(mov);
		print_window(newWin);
		refresh();
	}
	endwin();			/* End curses mode		  */

	return 0;


}
