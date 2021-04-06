packs = $(shell pkg-config --cflags --libs ncurses)
extra_flags=-Wall -Werror

headers=$(wildcard .src/*.h)

ODIR=obj
_CFILES = $(wildcard src/*.c)
_OBJ_PATH = $(wildcard obj/*.o)

$(ODIR)/%.o: src/%.c
	gcc -c -o $@ $< $(packs)

objects = main.o window_manipulation.o movable_objects.o pmp_parser.o
objects += event_queue.o


pref_objects = $(addprefix obj/, $(objects))

program: include $(pref_objects) $(headers)
	gcc -o program $+ $(packs) $(extra_flags)

fast: $(pref_objects) $(headers)
	gcc -O3 -o program $+ $(packs) $(extra_flags)

.PHONY: clean dirmake

clean:
	rm obj/* program -r

