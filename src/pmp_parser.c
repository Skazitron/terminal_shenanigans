#include "headers.h"

struct Movable * block_from_smp(FILE * f, int s_x, int s_y,
		struct Window * window)
{
	

	FILE * log_file = fopen("./src/tests/index.log", "w+");
	fprintf(log_file, "Function succesfully entered");

	if (f == NULL)
	{
		fprintf(stderr, "File does not exit");
		return NULL;
	}

	

	// TODO: Read file and check if the file is actually a pmp file
	// returns null and displays error if the file doesn't actually exist
	// TODO: Fix alignment 
	// step 1: for now just try scanning and creating a pixel block
	int y_count = 0;
	int x_count = 0;

	// initiates a pointer for the movable pixel that will be created
	struct Movable * m = NULL;
	struct Movable * head;

	char buffer[2];
	while (fscanf(f, "%c", buffer) != EOF)
	{
		fprintf(log_file, "%c", buffer[0]);

		if (buffer[0] == ' ') 
			x_count += 1; 
		else if (buffer[0] == '\n')
		{
			x_count = 0;
			y_count += 1;
		}

		else 
		{
			if (m != NULL)
			{

				m->next = create_movable_object(buffer[0], window,
						x_count + s_x , y_count + s_y);
				m = m->next;
				x_count += 1;
			} 
			else
			{
				m = create_movable_object(buffer[0], window,
						x_count + s_x, y_count + s_y);
				x_count += 1;
				head = m;
			}
		}

	}

	fclose(f);

	return head;
}

