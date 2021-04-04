#include <ncurses.h>
#include <stdlib.h>

// global variables
extern char background;

// struct for configuring the window
struct Window 
{
    int x,y;
    struct Pixel ** pixel;
};

// each pixel on the window
struct Pixel
{
    int perishable;
    int immovable;
    char p;
};

// movable 
struct Movable
{
    char p;
    int p_x, p_y;
    struct Window * win;
};

// event struct
struct Event
{
    
};

// event queue
struct Event_Queue
{
    struct Event * event;
};


void background_fill(struct Window * win, char back);

// returns a window pointer to the newly created window
struct Window * createWindow(int, int);

// fills the window with garbage just for testing
void garbage_fill(struct Window *, char);

// prints the window
void print_window(struct Window *);

// function to move a Movable object across the window
void move_object(struct Movable * mov, char);

// function to paint the movable object on the screen
void display_mov_object(struct Movable * mov);

// creates a movable object window
struct Movable * create_movable_object(char, struct Window *);

// create immovable block (starting index, ending index for
// both x and y
void create_immovable_block(int s_x, int e_x, int s_y, int e_y, 
        struct Window *, char P);


