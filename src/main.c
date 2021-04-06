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
	
	struct Animation * cyc = cycle_state(5,5,newWin, 3,
			"./assets/1.smp",
			"./assets/2.smp",
			"./assets/3.smp");

	initscr();			/* Start curses mode 		  */
	
	background_fill(newWin, background);
	create_immovable_block(80, 90, 0, 10, newWin, 'X');
	create_immovable_block(0, 80, 20, 30, newWin, 'X');


	border_builder(newWin, '+');
	print_window(newWin);

	int show = 0;
	
	refresh();			/* Print it on to the real screen */
	char a;
	while ((a = getch()) != 'q')
	{

		
		background_fill(newWin, background);
		create_immovable_block(80, 90, 0, 10, newWin, 'X');
		create_immovable_block(0, 80, 20, 30, newWin, 'X');
		clear();
		move_animation_chain(a, 3, cyc); 
		display_mov_object(cyc->curr_anim);
		cyc = cyc->next_state;
		border_builder(newWin, '+');
		print_window(newWin);
		refresh();
	}
	endwin();			/* End curses mode		  */

	return 0;


}


void error_hander(char * message)
{

	printf("The program failed: %s\n", message);
	exit(1);

}
