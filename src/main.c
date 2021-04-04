#include "headers.h"
#include <unistd.h> 
#include <stdlib.h>

int main()
{

    int x,y;

    x = 60;
    y = 30;

	// create a new window

    struct Window * newWin = createWindow(x,y);
	
	// create a new movable object 
	struct Movable * mov = create_movable_object('A', newWin);


	initscr();			/* Start curses mode 		  */
	
	garbage_fill(newWin, '_');
	print_window(newWin);
	
	refresh();			/* Print it on to the real screen */
	char a;
	while ((a = getch()) != 'q')
	{
		newWin->pixel[10][10].p = a;
		clear();
		print_window(newWin);
		refresh();
		sleep(1.0/30.0);
	}
	endwin();			/* End curses mode		  */

	return 0;


}
