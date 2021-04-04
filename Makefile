packs = $(shell pkg-config --cflags --libs ncurses)
extra_flags=-Wall -Werror

headers=$(wildcard .src/*.h)

ODIR=obj
_CFILES = $(wildcard src/*.c)
_OBJ_PATH = $(wildcard obj/*.o)

$(ODIR)/%.o: src/%.c
	gcc -c -o $@ $< $(packs)

objects = main.o window_manipulation.o test.o
pref_objecst = $(addprefix obj/, $(objects))

program: $(pref_objecst) $(headers)
	gcc -o program $+ $(packs) $(extra_flags)
.PHONY: clean

clean:
	rm obj/* program -r
