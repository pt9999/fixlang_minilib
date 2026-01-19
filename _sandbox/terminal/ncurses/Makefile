all:

test:
	fix test

document:
	fix docs -o docs

examples: filer.out loadavg.out ncurses_test1.out

clean:
	fix clean
	rm -f *.o *.out
	rm -rf .tmp

%.o : %.c
	gcc -Wall -o $@ -c $<

%.out: %.fix
	fix build -o $@ -f $<
