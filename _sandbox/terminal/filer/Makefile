all: build

build:
	fix build

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

install:
	install filer.out $(HOME)/.local/bin/filer

