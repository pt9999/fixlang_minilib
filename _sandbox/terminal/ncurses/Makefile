all:

test:
	fix test

document:
	fix docs -o docs

clean:
	fix clean
	rm -rf .tmp
	rm -f *.o *.out
	rm -f examples/*.out

%.o : %.c
	gcc -Wall -o $@ -c $<

%.out: %.fix ncurses.fix lib.c
	fix build -o $@ -f $<

EXAMPLES = \
	examples/demo_attributes.out \
	examples/demo_colors.out \
	examples/display_bounds.out \
	examples/hello_world.out \
	examples/hello_world2.out \
	examples/loadavg.out \

.PHONY: examples
examples: $(EXAMPLES)

