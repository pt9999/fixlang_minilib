all: run

run: libtest.a
	LIBRARY_PATH="." fix run -d test -f main.fix

build: libtest.a
	LIBRARY_PATH="." fix build -d test -f main.fix

libtest.a: libtest.o
	ar r $@ $^

%.o: %.c
	gcc -Wall $< -c -o $@

clean:
	rm -f *.o *.a *.out
